#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <thread> // potrzeba C++11
#include "odliczanie.cpp"
#include "zapis.cpp"
using namespace std;

int main()
{
    int select, from, where, order, zmienna, i = 0, j = 0, czy, k, numer, z = 0;
    string x, word, x2;
    list<pair<int, string> > lista;
    thread t1(odliczanie); //tutaj tread obok programu wczytuje funckje która wyswietla X minut do konca zajec/przerwy,
    t1.detach(); //reczny sposob poniewaz mia³em problemy z implementacja Crona w CPP
    while (i < 1) {
        zmienna = j = z = k = 0;
        cout << "Podaj numer zapytania: ";
        cin >> numer;
        cin.ignore();
        cout << "Podaj zapytanie: ";
        getline(cin, x);
        while (x[k]) {
            x[k] = tolower(x[k]);
            k++;
        }
        select = x.find("select ");
        from = x.find(" from ");
        where = x.find(" where ");
        order = x.find(" order by ");
        if (select != 0 || from < 1) //select nie na 1 miejscu i from na 1 miejscu lub nie wystepuje
        {
            cout << "Bledne zapytanie !";
            zmienna = 1;
        }
        else {
            if (where != -1) { //where wystepuje
                if (from > where) // from za where
                {
                    cout << "Bledne zapytanie !";
                    zmienna = 1;
                }
            }
            if (order != -1 && where != -1) { //order wystepuje i where wystepuje
                if (order < where || order < from) //order przed where lub from
                {
                    cout << "Bledne zapytanie !";
                    zmienna = 1;
                }
            }
            if (order != -1 && where == -1) //order wystepuje, where nie
            {
                if (order < from) {
                    cout << "Bledne zapytanie !";
                    zmienna = 1;
                }
            }
            if (zmienna == 0) {
                cout << "Poprawne zapytanie !"; // TYLKO TUTAJ ZAPISUJEMY
                for (std::list<pair<int, string> >::iterator it = lista.begin(); it != lista.end(); it++) {
                    if (it->first == numer) {
                        lista.remove(*it); // usuwa element, ktory ma zostac nadpisany
                        break;
                    }
                }
                lista.push_front(make_pair(numer, x)); // dodaje do listy pare
                lista.sort(); // sortuej liste
                thread t2(save, lista); // uruchamia drugi watek boczny
                t2.detach();
            }
        }
        cout << "\nJesli chcesz dodac zapytanie, wcisnij 1: ";
        cin >> czy;
        if (czy == 1)
            ;
        else {
            cout << "\nZakonczyles dzialanie programu.";
            return 0;
        }
    }
}

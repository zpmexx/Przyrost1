#include <iostream>
#include <fstream>
#include <list>
#include <time.h>
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>
using namespace std;
void save(list<pair<int, string> > lista1)
{
    int i = 0;
    while (i < 1) {
        time_t now = time(0);
        tm* x = localtime(&now);
        if ((x->tm_sec == 0) || (x->tm_sec == 30)) {
            fstream plik("odp.txt", ios::out | ios::trunc); //otwiera plik.txt
            for (list<pair<int, string> >::iterator it = lista1.begin(); it != lista1.end(); it++) {
                plik << it->first << " " << it->second << "\n";
            } // dpdaje liste do pliku.txt
        Sleep(1000);
        }

    }
}

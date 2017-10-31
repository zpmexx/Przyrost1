#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>/
using namespace std;
void odliczanie()
{
    int i = 0;
    while (i < 1) {
        time_t now = time(0);
        tm* x = localtime(&now);
        if (x->tm_sec == 0) {
                cout<<"\n";
            if (x->tm_hour == 8 && x->tm_min > 15) //1
                cout << 45 + (60 - x->tm_min) << " minut do konca zajec" << endl;
            if (x->tm_hour == 9 && x->tm_min < 45) //2
                cout << 45 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 9 && x->tm_min >= 45) //3
                cout << 60 - x->tm_min << " minut do konca przerwy" << endl;
            if (x->tm_hour == 10) //4
                cout << 30 + 60 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 11 && x->tm_min < 30) //5
                cout << 30 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 11 && x->tm_min >= 30 && x->tm_min < 45) //6
                cout << 45 - x->tm_min << " minut do konca przerwy" << endl;
            if (x->tm_hour == 11 && x->tm_min >= 45) //7
                cout << 75 + 60 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 12) //8
                cout << 15 + 60 - x->tm_min << " minut do konca zajec " << endl;
            if (x->tm_hour == 13 && x->tm_min < 15) //9
                cout << 15 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 13 && x->tm_min >= 15 && x->tm_min < 45) //10
                cout << 45 - x->tm_min << " minut do konca przerwy" << endl;
            if (x->tm_hour == 13 && x->tm_min >= 45) //11
                cout << 75 + 60 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 14) //12
                cout << 15 + 60 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 15 && x->tm_min < 15) //13
                cout << 15 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 15 && x->tm_min >= 15 && x->tm_min < 30) //14
                cout << 30 - x->tm_min << " minut do konca przerwy" << endl;
            if (x->tm_hour == 15 && x->tm_min >= 30) //15
                cout << 60 + 60 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 16) //16
                cout << 60 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 17 && x->tm_min < 15) //17
                cout << 15 - x->tm_min << " minut do konca przerwy" << endl;
            if (x->tm_hour == 17 && x->tm_min >= 15) //18
                cout << 45 + 60 - x->tm_min << " minut do konca zajec" << endl;
            if (x->tm_hour == 18 && x->tm_min < 45) //18
                cout << 45 - x->tm_min << " minut do konca zajec" << endl;
            Sleep(59000);
        }
    }
}


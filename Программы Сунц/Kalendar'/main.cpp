//
//  main.cpp
//  Kalendar
//
//  Created by Tastekov Adil Azatovich on 20.02.15.
//  Copyright (c) 2015 Tastekov Adil Azatovich. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

bool visokos_1 (int year) {
    return (year % 100 != 0 && year % 4 == 0) || year % 400 == 0;
}
int kolvoDn_2 (int year) {
    if (visokos_1(year))
        return 366;
    else
        return 365;
}
int dlitMnt_3 (int year, int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return  31;
    else {
        if (month == 2) {
            if (visokos_1(year))
                return 29;
            else
                return 28;
        }
        else
            return 30;
    }
}
int raznNepoln_4 (int day, int month, int year) {
    int summ = 0;
    for (int i = 1; i < month; i++)
        summ += dlitMnt_3(year, i);
    return summ + day;
}
int raznPoln_5 (int day, int month, int year) {
    int summ = 0;
    for (int  i = 1; i < year; i++)
        summ += kolvoDn_2(i);
    return summ + raznNepoln_4(day, month, year);
}
int raznBtwDates_6 (int day1, int month1, int year1, int day2, int month2, int year2) {
    return abs(raznPoln_5(day1, month1, year1) - raznPoln_5(day2, month2, year2));
}
int denNedeli_7 (int day2, int month2, int year2) {
    int r;
    if (raznPoln_5(1, 1, 1) > raznPoln_5(day2, month2, year2))
        r = -raznBtwDates_6(1, 1, 1, day2, month2, year2);
    else
        r = raznBtwDates_6(1, 1, 1, day2, month2, year2);
    return (0 + r) % 7;
}
void vivodMonth_8 (int month, int year) {
    cout << "Mo  Tu  We  Th  Fr  Sa  Su" << endl;
    int dn = denNedeli_7 (1, month, year); //Получаем день недели первого дня искомого месяца
    int i = -dn; //счетчик для цикла
    int k = 0;
    while (i < dlitMnt_3(year, month)) {
        if (i < 0) {
            printf(" -  ");
            i++; k++;
            if (k % 7 == 0)
                cout << endl;
        }
        else {
            if (i + 1 < 10)
                cout << " " << i + 1 << "  ";
            else
                cout << i + 1 << "  ";
            i++; k++;
            if (k % 7 == 0)
                cout << endl;
        }
    }
}
void vivod3Month (int month, int year) {
    cout << "Mo Tu We Th Fr Sa Su  | Mo Tu We Th Fr Sa Su  | Mo Tu We Th Fr Sa Su" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    int mnt[4], dn[4], kl[4];
    mnt[1] = dlitMnt_3(year, month);
    mnt[2] = dlitMnt_3(year, month + 1);
    mnt[3] = dlitMnt_3(year, month + 2);
    dn[1] = denNedeli_7 (1, month, year);
    dn[2] = denNedeli_7 (1, month + 1, year);
    dn[3] = denNedeli_7 (1, month + 2, year);
    kl[1] = 1; kl[2] = 1; kl[3] = 1;
    int k = 1, kel, l = 1;
    while (k <= 126) {
        kel = kl[l] - dn[l];
        if (kl[l] <= dn[l])
            cout << " - ";
        else {
            if (kel > mnt[l]) {
                cout << "   ";
            }
            else {
                if (kel < 10) cout << " " << kel << " ";
                else cout << kel << " ";
            }
        }
        kl[l]++;
        if (!(k % 7)) {
            cout << "   ";
            l++;
        }
        if (!(k % 21)) {
            cout << endl;
            l = 1;
        }
        k++;
    }
}
void vivodYear_9 (int year) {
    cout << "----------------------------------------------------------------------" << endl;
    cout << "      January         |        February        |        March          " << endl;
    vivod3Month(1, year);
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "       April          |         May            |        June           " << endl;
    vivod3Month(4, year);
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "       July           |        August          |      September        " << endl;
    vivod3Month(7, year);
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "      October         |        November        |       December        " << endl;
    vivod3Month(10, year);
}
int main() {
    int n;
    cout << "Year - ";
    cin >> n;
    vivodYear_9(n);
    cout << endl;
    return 0;
}



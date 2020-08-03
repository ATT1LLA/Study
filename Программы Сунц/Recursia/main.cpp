//
//  main.cpp
//  Recursia
//
//  Created by Тастеков Адиль Азатович on 04/09/15.
//  Copyright (c) 2015 Тастеков Адиль Азатович. All rights reserved.
//

#include <iostream>
#include <math.h>


using namespace std;

long long mas[70][70];

int razr (int a) {
    int count = 0;
    while (a != 0) {
        a /= 10;
        count++;
    }
    return count;
}

/*int i1;//count of fib;
ll fib[100];
bool flag[1001];

void gen(long long sum, int i_gl) {
    if (sum < 0) return;
    if (sum == 0)
    {
        bool flag_1 = 0;
        for (int i = i1 - 1; i > 0; i--)
        {
            if (flag[i])
            {
                if (!flag_1) flag_1 = 1;
                cout << 1;
            }
            else if (flag_1) cout << 0;
        }
        cout << endl;
    }
    else
    {
        for (int i = i1 - 1; i > i_gl; i--)
        {
            if (!flag[i])
            {
                flag[i] = 1;
                gen(sum - fib[i], i);
                flag[i] = 0;
                
            }
        }
    }
    
}*/

void convert (int a, int mas[razr(a)]) {
    int i = 0;
    while (a != 0) {
        mas[i] = a % 10;
        a /= 10;
        i++;
    }
}

//Длинка
int dlinka(int a[], int size_a, int b[], int size_b, int c[]) {
    int length = size_a + size_b + 1;
    
    for (int q = 0; q < length; q++) c[q] = 0;
    
    for (int i = 0; i < size_a; i++) {
        for (int j = 0; j < size_b; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    
    for (int i = 0; i < length; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    
    while (c[length - 1] == 0) length--;
    
    return length;
}

// №1 Факториал
void fuckt (int k[], int n) {
    int a[10000000], c[10000000];
    
    convert(n, a);
    
    
}
void fackt(int n) {
    int c(10000000);
    
    
}

// №2 Нахожденине НОД
int NOD (int m, int n) {
    if (m < n) { int c = m; m = n; n = c;}
    if (m % n == 0) return n;
    else return NOD(n, m % n);
}

// №3 Кол-во сочетание из N по K
long long soch (int n, int k) {
    if (n == k or k == 0) return 1;
    else {
        if (mas[n - 1][k - 1] == 0) mas[n - 1][k - 1] = soch(n - 1, k - 1);
        if (mas[n - 1][k] == 0) mas[n - 1][k] = soch(n - 1, k);
        return mas[n - 1][k - 1] + mas[n - 1][k];
    }
}
// №4 Скобки
void skob();

// №5 Ханойскте башни
// 1. Вспомагательная функция
void HT (int n/*кол-во дисков*/, int orig/*откуда убирать*/, int dest/*куда класть*/) {
    if (n == 0) {}
    else {
        int tmp = 6 - (orig + dest);
        HT (n - 1, orig, tmp);
        cout << orig << dest << " ";
        HT (n - 1, tmp, dest);
    }
}
// 2. Основная функция
void khan ();

int main(int argc, const char * argv[]) {
    int r;
    //cin >> r;
    int a[100];
    //dlinka(r, 25, a);
    HT(4, 1, 3);
    cout << endl;
    return 0;
}

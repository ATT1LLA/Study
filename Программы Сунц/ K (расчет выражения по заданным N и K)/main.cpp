//
//  main.cpp
//  Zadachi
//
//  Created by Тастеков Адиль Азатович on 14.11.14.
//  Copyright (c) 2014 Тастеков Адиль Азатович. All rights reserved.
//

#include <iostream>

#define ll long long
#define big (long long)10E17*9

ll n, n1, k, kol, h, lil, rar, del[1000000][2], mn = big;

void prost_d (ll a) {
    int j = 0, f = 2;
    for (f = 2; f * f <= a; f++) {
        if (a % f == 0) {
            kol++;
            del[++j][0] = f;
            while (a % f == 0) {
                a /= f;
                del[j][1]++;
            }
        }
    }
    if (a > 1) {
        j++;
        del[j][0] = a;
        del[j][1] = 1;
        kol++;
    }
}

int main() {
    std::cin >> n >> k;
    prost_d(k);
    for (int i = 1; i <= kol; i++) {
        //std::cout << del[i][0] << "^" << del[i][1] << " | ";
        n1 = n;
        while (n1 / del[i][0] != 0) {
            n1 /= del[i][0];
            lil += n1;
        }
        lil /= del[i][1];
        del[i][0] = lil;
        lil = 0;
        if (del[i][0] < mn)
            mn = del[i][0];
    }
    //std::cout << std::endl;
    std::cout << mn << std::endl;
    return 0;
}

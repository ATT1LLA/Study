//
//  main.cpp
//  Chummator
//
//  Created by Тастеков Адиль Азатович on 29.01.15.
//  Copyright (c) 2015 Тастеков Адиль Азатович. All rights reserved.
//


#include <iostream>

using namespace std;


bool arr[3];


bool strPears (bool a, bool b) {
    return not(a or b);
}
bool n (bool a) {
    return strPears(a, a);
}
bool konThree (bool a, bool b, bool c) {
    bool k = strPears(strPears(a, a), strPears(b, b));
    return strPears(strPears(k, k), strPears(c, c));
}
bool dizFour (bool a, bool b, bool c, bool d) {
    bool k = strPears(strPears(a, b), strPears(a, b));
    bool l = strPears(strPears(c, d), strPears(c, d));
    return strPears(strPears(k, l), strPears(k, l));
}
void s() {
    bool s1 = konThree(n(arr[0]), n(arr[1]), arr[2]);
    bool s2 = konThree(n(arr[0]), arr[1], n(arr[2]));
    bool s3 = konThree(arr[0], n(arr[1]), n(arr[2]));
    bool s4 = konThree(arr[0], arr[1], arr[2]);
    bool s = dizFour(s1, s2, s3, s4);
    cout << s << " | ";
}
void p() {
    bool p1 = konThree(n(arr[0]), arr[1], arr[2]);
    bool p2 = konThree(arr[0], n(arr[1]), arr[2]);
    bool p3 = konThree(arr[0], arr[1], n(arr[2]));
    bool p4 = konThree(arr[0], arr[1], arr[2]);
    bool p = dizFour(p1, p2, p3, p4);
    cout << p << endl;
}
void rec (int i = 0) {
    if (i > 2) {
        cout << arr[0] << " | " << arr[1] << " | " << arr[2] << " | ";
        s();
        p();
    }
    else {
        arr[i] = 0;
        rec(i + 1);
        arr[i] = 1;
        rec(i + 1);
    }
}


int main() {
    rec();
    cout << endl;
    return 0;
}



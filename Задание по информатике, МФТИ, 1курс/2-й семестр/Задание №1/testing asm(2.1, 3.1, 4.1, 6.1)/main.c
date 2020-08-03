//
//  main.c
//  teating asm
//
//  Created by Тастеков Адиль Азатович on 22.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>

int a1;
long int a2;
unsigned int a3;
unsigned long a4;

float f;

double d;

char c;

int main(int argc, const char * argv[]) {

    int a1_l = 1;
    long int a2_l = 2;
    unsigned int a3_l = 3;
    unsigned long a4_l = 4;
    
    float f_l = 1.1;
    
    double d_l = 1.11;
    
    char c_l = 'N';

    
    scanf("%d", &a1);
    
    a1 = a1 + 2;
    a1 = a1 * 2;
    a1 = a1 - 2;
    a1 = a1 / 2;
    
    if (a1 < 2) {
        a2 = -1;
    } else {
        if (a1 > 2) {
            a2 = 1;
        } else {
            a2 = 0;
        }
    }

    return 0;
}

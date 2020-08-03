//
//  main.c
//  №3.8 "Уравнение"
//
//  Created by Тастеков Адиль Азатович on 15.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415

double left_0, right_0;

double f(double x) {
    return (tanf(x) - x) / 100000000000000;
}

bool check (double left, double right) {
    double border = pi / 2;
    
    while (left > border) border += pi;
    
    if (right < border) {
        return 1;
    } else {
        return 0;
    }
}

void bin_search (double left, double right) {
    if (fabs(left) > fabs(right)) {
        bin_search(-right, -left);
    } else {
        double center = (right + left) / 2;
        double border = -10 * pi + pi / 2, f_border;
        bool flag = 0;
        
        // Проверяем лежат ли left и right на одном непрерывном отрезке
        while (left - border > 0) border += pi;
        if (right < border) {
            flag = 1;
        } else {
            flag = 0;
        }
        
        // Смотрим куда стремится f в т-ке разрыва
        if ((int)((border - pi / 2) / pi) % 2 == 0) f_border = 1;
        else f_border = -1;
        
        // Сама рекурсия
        if (right - left < 0.0000000001) {
            left_0 = left;
            right_0 = right;
        } else {
            if (flag) {
                if (f(center) == 0) {
                    left_0 = left;
                    right_0 = right;
                } else {
                    if (f(left) * f(center) <  0) {
                        bin_search(left, center);
                    } else {
                        bin_search(center, right);
                    }
                }
            } else {
                if (f(left) <  0) {
                    bin_search(left, border - 0.00000000005);
                } else {
                    bin_search(border + 0.00000000005, right);
                }
            }
        }
    }
}

typedef struct {
    int x;
    int y;
} point;


int main(int argc, const char * argv[]) {
    
    double left, right;
    
    scanf("%lf", &left);
    scanf("%lf", &right);
    
    bin_search(left, right);
    
    if (fabs(left) > fabs(right)) {
        printf("%.10lf\n", -1 * (left_0 + right_0) / 2);
    } else {
        printf("%.10lf\n", (left_0 + right_0) / 2);
    }
    
    return 0;
}

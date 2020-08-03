//
//  main.c
//  №4.1 "Атлеты"
//
//  Created by Тастеков Адиль Азатович on 10.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void swap (int *arr, int l, int r) {
    int n;
    n = *(arr + l);
    *(arr + l) = *(arr + r);
    *(arr + r) = n;
}

int main(int argc, const char * argv[]) {
    int n;
    
    scanf("%d", &n);
    
    int* mass = (int*)malloc(n * sizeof(int));
    int* str = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &mass[i]);
        scanf("%d", &str[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (str[j] > str[j + 1]) {
                swap(str, j, j + 1);
                swap(mass, j, j + 1);
            }
        }
    }
    
    int mass_sum = 0;
    int height = 0;
    
    for (int i = 0; i < n; i++) {
        if (str[i] > mass_sum) {
            mass_sum += str[i];
            height++;
        }
    }
    
    printf("%d\n", height);
    
    return 0;
}

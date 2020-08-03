//
//  main.c
//  №3.7 "Задача Иосифа"
//
//  Created by Тастеков Адиль Азатович on 15.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void swap (int *arr, int l, int r) {
    int n;
    n = *(arr + l);
    *(arr + l) = *(arr + r);
    *(arr + r) = n;
}

void reverse (int *arr, int l, int r) {
    int i;
    if (l != r) {
        
        for (i = l; i <= (l + r) / 2; i++) {
            swap(arr, i, (r + l) - i);
        }
    }
}

void iosif (int *arr, int n, int m) {
    int cc;
    if (n > 1) {
        if (m  % n == 0) {
            cc = n;
        } else {
            cc = m % n;
        }
        reverse(arr, cc - 1, n - 1);
        reverse(arr, cc - 1, n - 2);
        iosif(arr, n - 1, m);
    }
}

int main(int argc, const char * argv[]) {
    
    int n, m;
    
    int c;
    
    c = max(n, m);
    
    scanf("%d", &n);
    scanf("%d", &m);
    
    int* arr = (int*)malloc(n * sizeof(int));
    
    int i;
    for (i = 0; i < n; i++) *(arr + i) = i + 1;
    
    iosif(arr, n, m);
    reverse(arr, 0, 2);
    
    //reverse(arr, 2, n - 1);
    
    for (i = 0; i < 3; i++) {
        printf ("%d\t", *(arr + i));
    }
    
    printf("\n");

    return 0;
}

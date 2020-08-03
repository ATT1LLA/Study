//
//  main.c
//  №3.4 "Биномиальные коэффициенты"
//
//  Created by Тастеков Адиль Азатович on 15.10.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int **matrix_alloc(size_t n, size_t m)
{
    int **a = malloc(sizeof(int*) * n);
    int i;
    for (i = 0; i < n; i++)
        a[i] = malloc(sizeof(int) * m);
    return a;
}

void matrix_free(int **a, size_t n)
{
    int i;
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

int soch (int** arr, int n, int k) {
    if((k == 0 && n == 0) || (k == 1 && n == 1) || (k == 0 && n == 1) || k == n || k == 0) {
        if (arr[n][k] == 0) {
            arr[n][k] = 1;
        }
    } else {
        if (arr[n][k] == 0) {
            arr[n][k] = soch(arr, n - 1, k - 1) + soch(arr, n - 1, k);
        }
    }
    return arr[n][k];
}

int main(int argc, const char * argv[]) {
    
    int n, k;
    
    scanf("%d", &n);
    scanf("%d", &k);
    
    int** arr = matrix_alloc(n + 1, n + 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            arr[i][j] = 0;
        }
    }
    
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d", arr[i][j]);
        }
    }*/
    
    
    printf("%d\n", soch(arr, n, k));
    
    return 0;
}

//
//  main.c
//  №3.1 Суммирование массива вещественных чисел
//
//  Created by Тастеков Адиль Азатович on 22.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>

float arr[10];

float summ_array (float* arr) {
    float summ = 0;    
    for (int i = 0; i < 10; i++) {
        summ += arr[i];
    }
    
    return summ;
}

int main(int argc, const char * argv[]) {
    float summ = 0;
    
    for (int i = 0; i < 10; i++) {
        scanf("%f", &arr[i]);
    }
    
    summ = summ_array(arr);
    
    printf("%f\n", summ);
    
    return 0;
}

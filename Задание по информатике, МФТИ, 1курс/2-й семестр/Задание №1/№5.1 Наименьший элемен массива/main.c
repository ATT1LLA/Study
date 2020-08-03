//
//  main.c
//  №5.1 Наименьший элемен массива
//
//  Created by Тастеков Адиль Азатович on 22.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>

int arr[10];

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min = arr[0];
    
    for (int j = 1; j < 10; j++) {
        if (arr[j] < min) {
            min = arr[j];
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}

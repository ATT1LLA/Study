//
//  main.c
//  Индивидуальная задача
//
//  Created by Тастеков Адиль Азатович on 22.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    char input;
    int length = 0;
    
    scanf("%c", &input);
    
    char* str = (char*)malloc(sizeof(char));
    
    while (input != 'S') {
        str[length] = input;
        
        scanf("%c", &input);
    
        length++;
        
        str = (char*)realloc(str, length);
    }
    
    for (int i = 0; i < length; i++) {
        printf("%c", str[i]);
    }
    
    printf("\n");
    
    return 0;
}

//
//  main.c
//  №1.3 Из 2-ичной в 16-тиричную
//
//  Created by Тастеков Адиль Азатович on 21.05.17.
//  Copyright © 2017 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* getString() {
    char* string = (char*)malloc(sizeof(char));
    char input;
    int length = 1;
    
    while (true) {
        scanf("%c", &input);
        
        if (input == '\n') {
            break;
        } else {
            string[length - 1] = input;
            length++;
            string = (char*)realloc(string, length);
        }
    }
    
    return string;
}

int* transform_toInt (char* string) {
    int* transformed = (int*)malloc(strlen(string) * sizeof(int));
    
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '0')
            transformed[i] = 0;
        else
            transformed[i] = 1;
    }
    
    return transformed;
}

int main(int argc, const char * argv[]) {

    int i = 0, var = 0, counter = 0;
    int imul = 1, j, n;
    
    scanf("%d", &n);
    
    int* binary = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &binary[i]);
    }
    
    char* hex = (char*)malloc((n / 4 + 1) * sizeof(char));
    
    for (i = n - 1; i >= 3 ; i -= 4) {
        var = binary[i] + binary[i - 1] * 2 + binary[i - 2] * 4 + binary[i - 3] * 8;
        
        switch (var) {
                case 0:
                    hex[counter] = '0';
                    counter++;
                    break;
                    
                case 1:
                    hex[counter] = '1';
                    counter++;
                    break;
                    
                case 2:
                    hex[counter] = '2';
                    counter++;
                    break;
                    
                case 3:
                    hex[counter] = '3';
                    counter++;
                    break;
                    
                case 4:
                    hex[counter] = '4';
                    counter++;
                    break;
                    
                case 5:
                    hex[counter] = '5';
                    counter++;
                    break;
                    
                case 6:
                    hex[counter] = '6';
                    counter++;
                    break;
                    
                case 7:
                    hex[counter] = '7';
                    counter++;
                    break;
                    
                case 8:
                    hex[counter] = '8';
                    counter++;
                    break;
                    
                case 9:
                    hex[counter] = '9';
                    counter++;
                break;
                    
                case 10:
                    hex[counter] = 'A';
                    counter++;
                break;
                
                case 11:
                    hex[counter] = 'B';
                    counter++;
                break;
                
                case 12:
                    hex[counter] = 'C';
                    counter++;
                break;
                
                case 13:
                    hex[counter] = 'D';
                    counter++;
                break;
                
                case 14:
                    hex[counter] = 'E';
                    counter++;
                break;
                
                case 15:
                    hex[counter] = 'F';
                    counter++;
                break;
            
                default:
                break;
            }
    }
    
    if (i < 3 && i >= 0) {
        var = 0;
        imul = 1;
        while (i >= 0) {
            var += binary[i] * imul;
            i--;
            imul *= 2;
        }
        
        switch (var) {
            case 0:
                hex[counter] = '0';
                counter++;
                break;
                
            case 1:
                hex[counter] = '1';
                counter++;
                break;
                
            case 2:
                hex[counter] = '2';
                counter++;
                break;
                
            case 3:
                hex[counter] = '3';
                counter++;
                break;
                
            case 4:
                hex[counter] = '4';
                counter++;
                break;
                
            case 5:
                hex[counter] = '5';
                counter++;
                break;
                
            case 6:
                hex[counter] = '6';
                counter++;
                break;
                
            case 7:
                hex[counter] = '7';
                counter++;
                break;
                
            case 8:
                hex[counter] = '8';
                counter++;
                break;
                
            case 9:
                hex[counter] = '9';
                counter++;
                break;
                
            case 10:
                hex[counter] = 'A';
                counter++;
                break;
                
            case 11:
                hex[counter] = 'B';
                counter++;
                break;
                
            case 12:
                hex[counter] = 'C';
                counter++;
                break;
                
            case 13:
                hex[counter] = 'D';
                counter++;
                break;
                
            case 14:
                hex[counter] = 'E';
                counter++;
                break;
                
            case 15:
                hex[counter] = 'F';
                counter++;
                break;
                
            default:
                break;
                
    }
    }
    
    printf ("\nЧисло в двоичной системе исчисления: ");
    
    for (i = 0; i < n; i++) {
        printf("%d", binary[i]);
    }
    
    printf("\n");
    
    printf ("Число в шестнадцатиричной системе исчисления: ");
    
    for (i = n / 4; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    
    printf("\n");
    
    return 0;
}

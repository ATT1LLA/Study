//
//  main.c
//  №1.5 "Калькулятор"
//
//  Created by Тастеков Адиль Азатович on 07.11.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Stack_Max_Size 100

typedef char* C;

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

typedef struct Stack_tag{
    C data[Stack_Max_Size];
    size_t size;
}Stack_t;

void push(Stack_t *stack, const C value) {
    stack->data[stack->size] = value;
    stack->size++;
}

C pop(Stack_t *stack) {
    stack->size--;
    return stack->data[stack->size];
}

int convert_toInt(char* string) {
    int a = 0, i;
    
    for (i = 0; i < strlen(string); i++) {
        a *= 10;
        a += (int)string[i] - 48;
    }
    
    return a;
}

char* convert_toString(int a) {
    char* string = (char*)malloc(sizeof(char));
    
    int i, pow_a10 = 0, b = a;
    
    while (b != 0) {
        b /= 10;
        pow_a10++;
    }
    
    string = (char*)realloc(string, pow_a10);
    
    for(i = pow_a10 - 1; i >= 0; i--) {
        string[i] = (char)((a % 10) + 48);
        a /= 10;
    }
    
    return string;
}

char* calculate_postfiks(char* full_str) {
    
    Stack_t stack;
    stack.size = 0;
    
    int i, counter = 0;
    unsigned long zaniato = 0;
    
    char* first_elem = (char*)malloc(sizeof(char));
    char* second_elem = (char*)malloc(sizeof(char));
    char* sign = (char*)malloc(sizeof(char));
    char* result_str = (char*)malloc(sizeof(char));
    
    int first, second, result_int = 0;

    
    for (i = 0; i <= strlen(full_str); i++) {
        if (counter < 3 && i != strlen(full_str)) {
            if (counter == 0) {
                if (full_str[i] != ' ') {
                    first_elem = (char*)realloc(first_elem, i + 1);
                    first_elem[i] = full_str[i];
                } else {
                    push(&stack, first_elem);
                    counter++;
                    zaniato += (strlen(first_elem) + 1);
                }
            } else {
                if (counter == 1) {
                    if (full_str[i] != ' ') {
                        second_elem = (char*)realloc(second_elem, (i + 1) - zaniato);
                        second_elem[i - zaniato] = full_str[i];
                    } else {
                        push(&stack, second_elem);
                        counter++;
                        zaniato += (strlen(second_elem) + 1);
                    }
                } else {
                    if (counter == 2) {
                        if (full_str[i] != ' ') {
                            sign = (char*)realloc(sign, (i + 1) - zaniato);
                            sign[i - zaniato] = full_str[i];
                        } else {
                            push(&stack, sign);
                            counter++;
                            zaniato += (strlen(sign) + 1);
                        }
                    }
                }
            }
        } else {
            if (counter == 3) {
                sign = pop(&stack);
                second = convert_toInt(pop(&stack));
                first = convert_toInt(pop(&stack));
                
                switch (*sign) {
                    case '+':
                        result_int = (first + second);
                        break;
                    case '-':
                        result_int = (first - second);
                        break;
                    case '*':
                        result_int = (first * second);
                        break;
                    case '/':
                        result_int = (first / second);
                        break;
                    default:
                        break;
                }
                
                result_str = convert_toString(result_int);
                
                push(&stack, result_str);
                
                counter = 1;
                i--;
            }
        }
    }

    return pop(&stack);
}

int main(int argc, const char * argv[]) {
    
    char* full_str = getString();

    printf("%s\n", calculate_postfiks(full_str));
    
    return 0;
}

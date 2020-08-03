//
//  main.c
//  №1.4 "Скобки"
//
//  Created by Тастеков Адиль Азатович on 07.11.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

#define Stack_Max_Size 100

typedef char T;

typedef struct node{
    T data[Stack_Max_Size];
    size_t size;
} node;

void push (node *stack, const T value) {
    stack->data[stack->size] = value;
    stack->size++;
}

void pop (node *stack, const T value) {
    if (stack->size > 0)
        stack->size--;
}

int main(int argc, const char * argv[]) {
    
    char value = 0;
    bool flag = 1;
    
    node stack;
    
    stack.size = 0;
    
    while (value != '\n') {
        scanf("%c", &value);
        
        if (value == '(' || value == '{') {
            push(&stack, value);
        }
        
        if (value == ')' || value == '}') {
            if (stack.size <= 0) {
                flag = false;
                break;
            } else {
                pop(&stack, value);
            }
        }
    }
    
    if (stack.size != 0 && flag) flag = false;
    
    if (flag) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}

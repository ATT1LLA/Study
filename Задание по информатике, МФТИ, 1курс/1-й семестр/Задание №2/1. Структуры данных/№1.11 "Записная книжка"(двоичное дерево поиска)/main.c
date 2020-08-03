//
//  main.c
//  №1.11 "Записная книжка"(двоичное дерево поиска)
//
//  Created by Тастеков Адиль Азатович on 21.11.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
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

typedef struct Tree_notebook {
    char* surname;
    char* phone;
    struct Tree_notebook *left, *right;
}Tree_n;

void addNode(Tree_n *root, char* surname, char* phone) {
    int comparator;
    
    /*if (root == NULL) {
        root->surname = surname;
        root->phone = phone;
    } else {*/
        comparator = strcmp(root->surname, surname);
        
        if (comparator < 0) {
            if (root->left != NULL) {
                addNode(root->left, surname, phone);
            } else {
                Tree_n *added = (Tree_n*)malloc(sizeof(Tree_n));
                added->surname = surname;
                added->phone = phone;
                added->left = NULL;
                added->right = NULL;
                
                root->left = added;
                
                printf("OK\n");
            }
        }
        
        if (comparator > 0) {
            if (root->right != NULL) {
                addNode(root->right, surname, phone);
            } else {
                Tree_n *added = (Tree_n*)malloc(sizeof(Tree_n));
                added->surname = surname;
                added->phone = phone;
                added->left = NULL;
                added->right = NULL;
                
                root->right = added;
                
                printf("OK\n");
            }
        }
        
        if (comparator == 0) {
            printf("Changed. Old value = %s\n", root->phone);
            root->phone = phone;
        }
    //}
}

void find(Tree_n *root, char* surname) {
    int comparator = strcmp(root->surname, surname);
    
    if (comparator < 0) {
        if (root->left != NULL) {
            find(root->left, surname);
        } else {
            printf("NO\n");
        }
    }
    
    if (comparator > 0) {
        if (root->right != NULL) {
            find(root->right, surname);
        } else {
            printf("NO\n");
        }
    }
    
    if (comparator == 0) {
        printf("%s\n", root->phone);
    }
}

int main(int argc, const char * argv[]) {
    Tree_n node;

    printf("Введите фамилию и номер:\n");
    char* surname = getString();
    char* phone = getString();
    printf("OK\n");
    node.surname = surname;
    node.phone = phone;
    node.left = node.right = NULL;
    
    char* stop;
    
    while(1) {
        stop = getString();
        
        if (strcmp(stop, "next") == 0) {
            printf("Введите фамилию и номер:\n");
            surname = getString();
            phone = getString();
            
            addNode(&node, surname, phone);
        } else {
            break;
        }
    }
    
    printf("Поиск по фамилии: ");
    surname = getString();
    
    printf("Нужный номер: ");
    find(&node, surname);
    
    return 0;
}

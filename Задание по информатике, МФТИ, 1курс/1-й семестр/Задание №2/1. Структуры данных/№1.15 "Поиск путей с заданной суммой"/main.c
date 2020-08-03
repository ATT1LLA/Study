//
//  main.c
//  №1.15 "Поиск путей с заданной суммой"
//
//  Created by Тастеков Адиль Азатович on 21.11.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

typedef struct Tree {
    int key;
    struct Tree *left, *right;
}tree;

void addNode (tree *root, int key) {
    if (root == NULL) {
        root->key = key;
    } else {
        if (key < root->key) {
            if (root->left != NULL) {
                addNode(root->left, key);
            } else {
                tree *added;
                added->key = key;
                added->right = NULL;
                added->left = NULL;
                
                root->left = added;
            }
        }
        
        if (key >= root->key) {
            if (root->right != NULL) {
                addNode(root->right, key);
            } else {
                tree *added;
                added->key = key;
                added->right = NULL;
                added->left = NULL;
                
                root->right = added;
            }
        }
    }
}

bool findWay(tree *root, int s) {
    if (s == root->key) {
        return 1;
    } else {
        if (s > root->key) {
            findWay(root->left, s - root->key);
            findWay(root->right, s - root->key);
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    tree *node = NULL;
    
    int input;
    
    while(true) {
        scanf("%d", &input);
        
        if (input == 0) {
            break;
        } else {
            addNode(node, input);
        }
    }
    
    int s;
    
    scanf("%d", &s);
    
    printf("%d", findWay(node, s));
    
    return 0;
}

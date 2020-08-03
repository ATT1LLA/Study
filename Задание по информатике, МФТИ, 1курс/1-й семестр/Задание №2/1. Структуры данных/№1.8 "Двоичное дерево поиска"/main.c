//
//  main.c
//  №1.8 "Двоичное дерево поиска"
//
//  Created by Тастеков Адиль Азатович on 08.12.16.
//  Copyright © 2016 Тастеков Адиль Азатович. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree {
    int key;
    double value;
    struct Tree *left, *right, *parent;
}tree;

typedef struct queue {
    tree *root[100];
    int count;
}queue;

tree* get_first (queue queue) {
    int i;
    tree* root = queue.root[0];
    
    for (i = 0; i < queue.count - 1; i++) {
        queue.root[i] = queue.root[i + 1];
    }
    
    queue.count--;
    
    return root;
}

tree* get_last (queue queue) {
    queue.count--;
    return queue.root[queue.count];
}

void push (queue queue, tree* root) {
    queue.root[queue.count] = root;
    queue.count++;
}

tree* create_tree (int key, double value) {
    tree *root = (tree*)malloc(sizeof(tree));
    
    root->key = key;
    root->value = value;
    root->left = root->right = root->parent = NULL;
    
    return root;
}

void add_elem (tree* root, int key, double value) {
    if (root != NULL) {
        if (root->key < key) {
            if (root->left == NULL) {
                tree* add = create_tree(key, value);
                add->parent = root;
                root->left = add;
                return;
            } else {
                add_elem(root->left, key, value);
            }
        }
        
        if (root->key > key) {
            if (root->right == NULL) {
                tree* add = create_tree(key, value);
                add->parent = root;
                root->right = add;
                return;
            } else {
                add_elem(root->right, key, value);
            }
        }
        
        if (root->key == key) {
            printf("We have this element already\n");
            return;
        }
    } else {
        root = create_tree(key, value);
    }
}

void delete_elem (tree* root, int key) {
    if (root != NULL) {
        if (root->key < key) {
            if (root->left == NULL) {
                printf ("Такого элемента нет");
                return;
            } else {
                delete_elem(root->left, key);
            }
        }
        
        if (root->key > key) {
            if (root->right == NULL) {
                printf ("Такого элемента нет");
                return;
            } else {
                delete_elem(root->right, key);
            }
        }
        
        if (root->key == key) {
            if (root->parent->left == root) {
                root->parent->left = NULL;
            }
            
            if (root->parent->right == root) {
                root->parent->right = NULL;
            }
            
            return;
        }
    }
}

void dfs (tree *root) {
    if (root == NULL) {
        return;
    }
    printf("%lf\t", root->value);
    
    dfs(root->left);
    dfs(root->right);
    
}

void wfs (tree *root) {
    int i;
    
    queue queue;
    
    bool used[100];
    for (i = 0; i < 100; i++) used[i] = false;
    
    push(queue, root);
    used[root->key] = true;
    
    while(queue.count != 0) {
        tree* var = get_first(queue);
        printf("%lf", var->value);
        
        if (var->left != NULL) {
            if (!used[var->left->key]) {
                push(queue, var->left);
                used[var->left->key] = true;
            }
        }
        
        if (var->right != NULL) {
            if (!used[var->right->key]) {
                push(queue, var->right);
                used[var->right->key] = true;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    
    tree *root = NULL;
    
    double p;
    int counter = 1, n;
    
    printf("Введите количество элементов дерева: ");
    scanf("%d", &n);
    
    root = malloc(sizeof(tree));
    root->key = 0;
    scanf("%lf", &p);
    root->value = p;
    
    printf("Введите жлементы дерева:\n");
    while (counter < n) {
        scanf("%lf", &p);
        
        add_elem(root, counter, p);
        counter++;
    }
    
    dfs(root);
    
    printf("\n");
    
    return 0;
}













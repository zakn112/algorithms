//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node *root)
{
    if (root)
    {
        printf("%d", root->data);
        if (root->left || root->right)
        {
            printf("(");

            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");

            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

// Создание нового узла
Node* getFreeNode(int value, Node *parent)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

// Вставка узла
void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (value > tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value < tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);                                // дерево построено неправильно
        }
    }
}

void preOrderTravers(Node* root)
{
    if (root)
    {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node* root)
{
    if (root)
    {
        inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(Node* root)
{
    if (root)
    {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

Node* search(Node* root, int searchValue)
{
    if (root)
    {
        if (root->data == searchValue) {
            return root;
        }
        
        if (root->data > searchValue) {
           return search(root->left, searchValue);
        }else{
           return search(root->right, searchValue);
        }
    }
    
    return NULL;
    
}

int hash(char s[200]);

int main(int argc, const char * argv[]) {
    
    //1.Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
//    char s[200];
//    printf("Введите строку:");
//    scanf("%s", s);
//    printf("Хеш сумма вашей строки: %i\n", hash(s));
    
    //2. Переписать программу, реализующую двоичное дерево поиска.
    Node *Tree = NULL;
    FILE* file = fopen("/Users/kio/Documents/Geekbrains/algorithms/data.txt", "r");
    
    if (file == NULL)
    {
        puts("Can't open file!");
        // getch();
    }
    int count;
    fscanf(file, "%d", &count);          // Считываем количество записей
    int i;
    for (i = 0; i < count; i++)
    {
        int value;
        fscanf(file, "%d", &value);
        insert(&Tree, value);
    }
    fclose(file);
    printTree(Tree);
    printf("\nPreOrderTravers:");
    preOrderTravers(Tree);
    printf("\nInOrderTravers:");
    inOrderTravers(Tree);
    printf("\nPostOrderTravers:");
    postOrderTravers(Tree);
    printf("\nВведите число для поиска:");
    int searchValue;
    scanf("%i",&searchValue);
    
    Node* resNode = search(Tree, searchValue);
    if (resNode == NULL){
      printf("\nЗначение не найдено");
    }else{
        printf("\nАдрес найденного элемента дерева %p", resNode);
    }
    
   
       
    return 0;
}


int hash(char s[200]){
    
    int hash;
    int strInt = 0;
    
    for(int i = 0; i < 200; i++){
        strInt += (int)s[i];
    }
    
    hash = strInt%100000;
    
    return  hash;
}

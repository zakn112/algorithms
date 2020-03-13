//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>
#define MAX 20
#define infinity 9999

void printMatrix(int G[MAX][MAX], int n);
void deepCrawl(int vertex);
void widthCrawl(int vertex);
void initdCrawl(void);
int vertexInCrawl(int vertex);
int G[MAX][MAX];
int сrawl[MAX], сrawlCount;
int n;

int main(int argc, const char * argv[]) {
   
    
    FILE* file = fopen("/Users/kio/Documents/Geekbrains/algorithms/algorithms/data.txt", "r");
    if (file == NULL)
    {
        printf("Can't open file");
        exit(1);
    }
    fscanf(file, "%d", &n);
    
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int c;
            fscanf(file, "%d", &c);
            G[i][j] = c;
        }
    fclose(file);
    
    printMatrix(G,n);
    
    printf("\nОбход графа в глубину:\n");
    сrawlCount = 0;
    initdCrawl();
    deepCrawl(0);
    
    printf("\nОбход графа в ширину:\n");
    сrawlCount = 0;
    initdCrawl();
    widthCrawl(0);
    
    return 0;
}

void printMatrix(int G[MAX][MAX], int n)
{
    printf("%s", "      ");	
    for (int i = 0; i < n; i++)
        printf("%c(%d) ", 65 + i, i);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c(%d)", 65 + i, i);
        for (int j = 0; j < n; j++)
            printf("%5d", (G[i][j] == infinity) ? 0 : G[i][j]);
        printf("\n");
    }
}

void deepCrawl(vertex){
    if (vertexInCrawl(vertex)){
        return;
    }
    сrawl[сrawlCount] = vertex;
    сrawlCount++;
    
    for (int i = 0; i < n; i++) {
        if (G[vertex][i]){
            printf("%c -> %c ", 65 + vertex, 65 + i);
            deepCrawl(i);
        }
    }
}

void widthCrawl(vertex){
    int v[MAX], vcount = 0;
    for (int i = 0; i < n; i++) {
        if (G[vertex][i]){
            if (vertexInCrawl(i) == 0){
                printf("%c -> %c ", 65 + vertex, 65 + i);
                сrawl[сrawlCount] = i;
                сrawlCount++;
                v[vcount] = i;
                vcount++;
            }
        }
    }
    
    for (int i = 0; i < vcount; i++) {
        widthCrawl(v[i]);
    }
}


int vertexInCrawl(int vertex){
    for (int i = 0; i < n; i++) {
        if (сrawl[i] == vertex){
            return 1;
        }
    }
    return 0;
}

void initdCrawl(){
    for (int i = 0; i < n; i++) {
        сrawl[i] = -1;
    }
}

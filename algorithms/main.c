//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>

void lcs_matrix(void);
void lcs(void);
void print(int i, int j);
void print_matrix_b(char matrix[20][20]);
void print_matrix_c(int matrix[20][20]);
int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

void number_of_routes_with_obstacles(void);


int main(int argc, const char * argv[]) {
   
    lcs_matrix();
    number_of_routes_with_obstacles();
           
    return 0;
}


void lcs_matrix(void){
    printf("Enter 1st sequence:");
    scanf("%s", x);
    printf("Enter 2nd sequence:");
    scanf("%s", y);
   
    lcs();
    print_matrix_c(c);
    print_matrix_b(b);
    printf("\nThe Longest Common Subsequence is ");
    print(m, n);
    printf("\n");
}

void lcs()
{
    m = strlen(x);
    n = strlen(y);
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (i = 0; i <= n; i++)
        c[0][i] = 0;

    //c, u и l обозначают поперечное, восходящее и нисходящее направления соответственно(cross upper lower)
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
}

void print(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'c')
    {
        print(i - 1, j - 1);
        printf("%c", x[i - 1]);
    }
    else if (b[i][j] == 'u')
        print(i - 1, j);
    else
        print(i, j - 1);
}

void print_matrix_b(char b[20][20]){
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_c(int matrix[20][20]){
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}


//количество маршрутов с препятствиями

void number_of_routes_with_obstacles(){
    n = 5;
    m = 5;
    
    int A[n][m];
    int OB[n][m];
    
    //препятствия
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            OB[i][j] = 0;
        }
    }
    OB[1][2] = 1;
    OB[3][2] = 1;
    OB[2][3] = 1;
    printf("Матрица препятствий \n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%i ", OB[i][j]);
        }
        printf("\n");
    }
    //-----
    
    int i, j;
    for(j = 0; j < m; j++){
        if (OB[0][j] != 1) {
            A[0][j] = 1; // Первая строка заполнена единицами
        }else{
            A[0][j] = 0;
        }
    }
    
    for(i = 1; i < n; i++)
    {
        if (OB[i][0] != 1) {
            A[i][0] = 1;
        }else{
            A[i][0] = 0;
        }
        for(j = 1; j < m; j++)
        {
            if (OB[i][j] != 1) {
                A[i][j] = A[i][j-1] + A[i-1][j];
            }else{
                A[i][j] = 0;
            }
        }
    }
    
    printf("Количество маршрутов с препятствиями:");
   
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%i ", A[i][j]);
        }
        printf("\n");
    }
    
}



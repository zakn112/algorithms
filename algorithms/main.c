//
//  main.c
//  algorithms
//
//  Created by Андрей Закусов on 18.02.2020.
//  Copyright © 2020 Андрей Закусов. All rights reserved.
//

#include <stdio.h>
#include <math.h>


void bodyMassIndex(void);
void max4numbers(void);
void exchangeValues1(void);
void exchangeValues2(void);
void solutionQuadraticEquation(void);
void seasonByMonth(void);



int main(int argc, const char * argv[]) {
   
    bodyMassIndex();
    max4numbers();
    exchangeValues1();
    exchangeValues2();
    solutionQuadraticEquation();
    seasonByMonth();
    
    return 0;
}

void bodyMassIndex(){
    double mass, height;
    printf("Введите массу в киллограммах: ");
    scanf("%lg", &mass);
    
    printf("Введите ваш рост в метрах: ");
    scanf("%lg", &height);
    
    printf("Ваш индекс массы тела: %lg \n", mass / ( height * height));
}

void max4numbers(){
    int a, b, c, d;
    int min;
    printf("Введите 4 числа:");
    scanf("%i %i %i %i", &a, &b, &c, &d);
    
    min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;

    printf("Минимальное число: %i \n", min);
    
}

void exchangeValues1(){
    int a, b;
    int c;
    printf("Введите числа a и b:");
    scanf("%i %i", &a, &b);
    
    printf("Было a = %i и b = %i\n", a, b);
    
    c = a;
    a = b;
    b = c;
   
    printf("Стало a = %i и b = %i\n", a, b);
    
}

void exchangeValues2(){
    int a, b;
    printf("Введите числа a и b:");
    scanf("%i %i", &a, &b);
    
    printf("Было a = %i и b = %i\n", a, b);
    
    a *= b;
    b = a/b;
    a = a/b;
   
    printf("Стало a = %i и b = %i\n", a, b);
    
}

void solutionQuadraticEquation(){
    double a, b, c;
    printf("Введите коэффициенты a, b и c квадратного уравления вида a*x^2 + b*x + c = 0:");
    scanf("%lg %lg %lg", &a, &b, &c);
    
    double d, x1, x2;
    
    d = b * b - 4 * a * c;
    if (d < 0){
        printf("Корней нет");
        return;
    }
    
    x1 = (-b + sqrt(d))/(2*a);
    if (d == 0){
        printf("Один корень x = %lg\n", x1);
        return;
    }
    
    x2 = (-b - sqrt(d))/(2*a);
    
    printf("Два корня x1 = %lg, x2 = %lg\n", x1, x2);
    
}

void seasonByMonth(){
    int num;
    
    while (1) {
        printf("Введите номер месяца (-1 чтобы выйти):");
        scanf("%i", &num);
        
        if (num == -1){
            return;
        }
        num ++;
        num = (num - 12*(num/12))/3 + 1;
        if (num == 1) printf("Зима\n");
        else if (num == 2) printf("Весна\n");
        else if (num == 3) printf("Лето\n");
        else if (num == 4) printf("Осень\n");
        else printf("Не известно\n");
    }
    
}


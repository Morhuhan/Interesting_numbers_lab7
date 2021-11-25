#include <stdio.h>

int complate(int a, int b, int* I) {
    int i_a = 0;
    for (int i = a; i < b; i++) {       // Цикл для отбора чисел, соотетсвующих условию

        I[0] = i / 100;     // Разбиенеие 3-ех значного числа на отдельные цифры и помещение их в массив I[]            
        I[1] = (i % 100) / 10;
        I[2] = ((i % 100) % 10);

        if ((I[0] != I[1]) && (I[0] != I[2]) && (I[1] != I[2])) {  // Проверка цифр разбитого числа на равенство
            i_a++;
            printf("%d \n", i); 
        }
    }
    return i_a;
}

void check(int* a, int* b) {                         
    int flag = 1;
    int a_check;
    int b_check;
    while (flag) {
        printf("Enter number a \n");
        scanf("%d", &a_check);
        if (a_check < 100 || a_check > 999) {
            printf("ERROR \n");
            continue;
        }
        printf("Enter number b \n");
        scanf("%d", &b_check);
        if ((b_check < 100) || (b_check > 999) || (b_check < a_check) || (b_check == a_check)) {
            printf("ERROR \n");
            continue;
        }
        flag = 0;
    }
    *a = a_check;
    *b = b_check;
}

void main (void) {
    int a, b;
    int I[2];
    check(&a, &b);
    printf("There are %d interesting numbers found in this interval \n", complate(a, b, I)); 
}
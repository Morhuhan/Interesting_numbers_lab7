#include <stdio.h>

int complate(int *A, int a, int b) {

    int I[2];
    int i_a = 0;

    for (int i = 102; i < 202; i++) {       // Цикл для отбора чисел, соотетсвующих условию
        
        I[0] = i / 100;     // Разбиенеие 3-ех значного числа на отдельные цифры и помещение их в массив I[]            
        I[1] = (i % 100) / 10;
        I[2] = ((i % 100) % 10);


        if ((I[0] != I[1]) && (I[0] != I[2]) && (I[1] != I[2])) {  // Проверка цифр разбитого числа на равенство
            A[i_a] = i;     // если число проходит проверку оно помещается в массив A[]
            i_a++; 
        }


    }

    return i_a;

}

void check(int* a, int* b) {                         // Функция проверки правильности введенных чисел
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

    int A[900] = {0};       // В этом массиве будут храниться все подходящие числа, их кол-во не может быть больше 900
    int a, b;

    check(&a, &b);

    complate(A, a, b);



    for (int i = 0; i < 900; i++) {      // Цикл выводит по-элементно массив результатов
        
        if (A[i] == 0) {
            break;
        }

        printf("%d \n", A[i]);

    }

    printf("There are %d interesting numbers found in this interval \n", complate(A, a, b));

}
#include <stdio.h>

void main (void) {
    int I[2];
    int n = 0;
    int a, b;
    int i_a = 0;
    int flag = 1;

    while (flag) {      // Ввод чисел с клавиатуры и проверка их правильности
        printf ("Enter number a \n");
        scanf ("%d", &a);

        if (a < 100 || a > 999) {
            printf ("ERROR \n");
            continue;
        }
        printf ("Enter number b \n");
        scanf ("%d", &b);

        if ((b < 100) || (b > 999) || (b < a) || (b == a)) {
            printf ("ERROR \n");
            continue;
        }
        
        flag = 0;
    }

    int A[900] = {0};       // В этом массиве будут храниться все подходящие числа, их кол-во не может быть больше 900
    for (int i = a; i < b; i++) {       // Цикл для отбора чисел, соотетсвующих условию
        
        I[0] = i / 100;     // Разбиенеие 3-ех значного числа на отдельные цифры и помещение их в массив I[]            
        I[1] = (i % 100) / 10;
        I[2] = ((i % 100) % 10);

        if ((I[0] != I[1]) && (I[0] != I[2]) && (I[1] != I[2])) {  // Проверка цифр разбитого числа на равенство
            A[i_a] = i;     // если число проходит проверку оно помещается в массив A[]
            i_a++;      // Сдвиг каретки
        }

    }
    
    for (int i = 0; i < i_a; i++){      // Цикл выводит по-элементно массив результатов
        printf ("%d \n", A[i]);
    }

    printf ("There are %d interesting numbers found in this interval \n", i_a);
}

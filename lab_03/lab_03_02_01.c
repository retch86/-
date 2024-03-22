#include <stdio.h>

#define N 10
#define M 10
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define OK 0

int scan(int**, int*, int*);
void transf(int**, int*);
int digit_sum(int);
void print(int**, int, int);
void foo(int**, int*, int*);
void swap_str(int**, int**);
void swap_elem(int*, int*);

int main(void)
{
    int mistake;
    int array[N * M];
    int *matrix[N];
    transf(matrix, array);
    int n = 0;
    int m = 0;
    int *p_n = &n;
    int *p_m = &m;
    mistake = scan(matrix, p_n, p_m);
    if (!mistake)
    {
        foo(matrix, p_n, p_m);
        print(matrix, n, m);
    }
    return mistake;
}

// Функция ввода матрицы
int scan(int **matrix, int *n, int *m)
{
    int error_code = OK;
    int check;
    printf("Input size of matrix: ");
    check = scanf("%d%d", n, m);
    if (check != 2)
    {
        printf("Error: Incorrect type");
        error_code = WRONG_TYPE;
    }
    else if (*n < 2 || *n > 10 || *m > 10 || *m < 2)
    {
        printf("Error: Incorrect value");
        error_code = WRONG_VALUE;
    }
    else
    {
        printf("Input matrix:\n");
        for (int i = 0; i < *n && error_code == OK; i++)
        {
            for (int j = 0; j < *m && error_code == OK; j++)
            {
                check = scanf("%d", matrix[i] + j);
                if (check != 1)
                {
                    printf("Error: Incorrect type");
                    error_code = WRONG_TYPE;
                }
            }
        }
    }
    return error_code;
}

// Преобразование матрицы
void transf(int **matrix, int *array)
{
    for (int i = 0; i < N; i++)
        matrix[i] = array + (M * i);
}

// Функция находит сумму цифр числа
int digit_sum(int uu)
{
    int sum = 0;
    int temp;
    if (uu < 0)
        uu *= -1;
    // Складываю остаток и уменьшаю число
    while (uu > 0)
    {
        temp = uu % 10;
        sum += temp;
        uu /= 10;
    }
    return sum;
}

// Функция вывода матрицы
void print(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
    }
}

// Функция удаления строки и столбца содержащие число
// С наименьшей суммой цифр
void foo(int **matrix, int *n, int *m)
{
    int i, j, temp_i, temp_j, sum;
    int flag = 1;
    sum = 0;
    // Поиск числа с наименьшей суммой цифр
    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *m; j++)
        {
            if (flag == 1 || sum > digit_sum(matrix[i][j]))
            {
                flag = 0;
                sum = digit_sum(matrix[i][j]);
                temp_i = i;
                temp_j = j;
            }
        }
    }

    // Удаляю строчку с числом с наим. сум. цифр
    for (i = temp_i; i < *n - 1; i++)
        swap_str(matrix + i, matrix + i + 1);
    *n -= 1;  // Уменьшаю размер матрицы

    // Удаляю столбец с числом м наим. сум. цифр
    for (i = 0; i < *n; i++)
    {
        for (j = temp_j; j < *m - 1; j++)
            swap_elem(matrix[i] + j, matrix[i] + j + 1);
    }
    *m -= 1; // Уменьшаю размер матрицы
}

void swap_str(int **a, int **b)
{
    int *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_elem(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
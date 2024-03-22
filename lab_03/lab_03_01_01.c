#include <stdio.h>

#define N 10
#define M 10
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define OK 0

int scan(int**, int*, int*);
void foo(int**, int*, int, int);
void print(int*, int);
void transf(int**, int*);

int main(void)
{
    int mistake;
    int array[N * M];
    int *matrix[N];
    transf(matrix, array);
    int list[N];
    int n = 0;
    int m = 0;
    int *p_n = &n;
    int *p_m = &m;
    mistake = scan(matrix, p_n, p_m);
    if (!mistake)
    {
        foo(matrix, list, n, m);
        print(list, n);
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
    else if (*n < 1 || *n > 10 || *m > 10 || *m < 1)
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

// Фунцкия проверяет строку на симметричность
// И вносит значение k в список
void foo(int **matrix, int *list, int n, int m)
{
    if (m == 1)
    {
        for (int i = 0; i < n; i++)
            list[i] = 1;
    }
    else
    {
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            // Цикл идет до середины строки
            for (int j = 0; j < m / 2; j++)
            {
                // Проверяется равны ли симметричные значения
                if (matrix[i][j] == matrix[i][m - j - 1])
                    k = 1;
                else
                {
                    k = 0;
                    break;
                }
            }
            list[i] = k;
        }
    }
}

// Функция вывода списка
void print(int *list, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
}

// Преобразование матрицы
void transf(int **matrix, int *array)
{
    for (int i = 0; i < N; i++)
        matrix[i] = array + (M * i);
}
#include <stdio.h>

#define N 10
#define M 10
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define OK 0

int scan(int**, int*, int*);
void transf(int**, int*);
void print(int**, int, int);
void change(int**, int, int);

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
        change(matrix, n, m);
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
    else if (*n < 1 || *n > 10 || *m > 10 || *m < 1 || *m != *n)
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

// Функция меняет местами элементы выделенной области
void change(int **matrix, int n, int m)
{
    int i, j, temp;
    for (i = 0; i < n / 2; i++)
    {
        for (j = i; j < m; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n - i - 1][j];
            matrix[n - i - 1][j] = temp;
        }
        m -= 1;
    }
}
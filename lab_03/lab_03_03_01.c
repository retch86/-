#include <stdio.h>

#define N 10
#define M 10
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define OK 0

int scan(int**, int*, int*);
void transf(int**, int*);
void print(int**, int, int);
void sort(int**, int*, int, int);
void swap_str(int**, int**);
void swap_elem(int*, int*);

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
        sort(matrix, list, n, m);
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

void sort(int **matrix, int *list, int n, int m)
{
    int i, j, temp, index;
    // Заношу в список наибольшее число строки
    for (i = 0; i < n; i++)
    {
        temp = 0;
        for (j = 0; j < m; j++)
        {
            if (matrix[i][j] > temp)
                temp = matrix[i][j];
        }
        list[i] = temp;
    }

    // Использую индексы элементов из списка
    // как индексы строк матрицы и располагаю
    // строки по уменьшению относительно их
    // наибольших элементов
    for (i = 0; i < n; i++)
    {
        index = i;
        // Сортирую список
        for (int j = i + 1; j < n; j++)
        {
            if (list[j] > list[index])
                index = j;
        }
        swap_elem(list + i, list + index);
        // И сразу сортирую строки матрицы
        swap_str(matrix + i, matrix + index);
    }
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




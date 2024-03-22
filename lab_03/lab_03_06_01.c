#include <stdio.h>

#define N 10
#define M 10
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define OK 0

int scan(int**, int*, int*);
void transf(int**, int*);
void print(int**, int, int);

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
        print(matrix, n, m);
    return mistake;
}

// Функция ввода матрицы
int scan(int **matrix, int *p_n, int *p_m)
{
    int error_code = OK;
    int check;
    // Ввод размера матрицы
    printf("Input size of matrix: ");
    check = scanf("%d%d", p_n, p_m);
    if (check != 2)
    {
        printf("Error: Incorrect type");
        error_code = WRONG_TYPE;
    }
    else if (*p_n < 1 || *p_n > 10 || *p_m > 10 || *p_m < 1 || *p_n != *p_m)
    {
        printf("Error: Incorrect value");
        error_code = WRONG_VALUE;
    }
    else
    {
        int k, l, elem, i, n, m;
        n = *p_n;   // Количество строк
        m = *p_m;   // Количество столбцов
        k = 0;      // Индекс начала строки
        l = 0;      // Индекс начала столбца
        elem = 1;   // Порядковый элемент

        while (k < n && l < m)
        {
            // Заполнение первой строки из оставшихся
            for (i = l; i < m; i++)
            {
                matrix[k][i] = elem;
                elem += 1;
            }
            k += 1;
            // Заполнение последнего столбца из оставшихся
            for (i = k; i < n; i++)
            {
                matrix[i][m - 1] = elem;
                elem += 1;
            }
            m -= 1;
            // Заполнение последней строки из оставшихся
            if (k < n)
            {
                for (i = m - 1; i >= l; i--)
                {
                    matrix[n - 1][i] = elem;
                    elem += 1;
                }
                n -= 1;
            }
            // Заполнение первого столбца из оставшихся
            if (l < m)
            {
                for (i = n - 1; i >= k; i--)
                {
                    matrix[i][l] = elem;
                    elem += 1;
                }
                l += 1;
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
#include <stdio.h>

#define N 10
#define M 10
#define SIZE_L 100
#define WRONG_TYPE 1
#define WRONG_VALUE 2
#define OK 0

int scan(int**, int*, int*);
void transf(int**, int*);
void print(int**, int, int);
int digit_sum(int);
int get_list(int**, int*, int, int, int*);
void shift(int*, int);
void change(int**, int*, int, int);

int main(void)
{
    int mistake;
    int array[N * M];
    int *matrix[N];
    transf(matrix, array);
    int list[N];
    int n = 0;
    int m = 0;
    int count = 0;
    int *p_n = &n;
    int *p_m = &m;
    int *p_c = &count;
    mistake = scan(matrix, p_n, p_m);
    if (!mistake)
    {
        // Функции заносят в список числа сумма цифр которых
        // больше 10. Сдвигают элементы списка влево на 3
        // и возвращают значения из списка в матрицу
        mistake = get_list(matrix, list, n, m, p_c);
        if (!mistake)
        {
            shift(list, count);
            change(matrix, list, n, m);
            print(matrix, n, m);
        }
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

int get_list(int **matrix, int *list, int n, int m, int *count)
{
    int error_code = OK;
    int temp = 0;
    // Заношу в список числа
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (digit_sum(matrix[i][j]) > 10)
            {
                list[temp] = matrix[i][j];
                temp += 1;
                *count += 1;
            }
        }
    }
    if (*count == 0)
    {
        printf("Error: Incorrect value");
        error_code = WRONG_VALUE;
    }
    return error_code;
}

// Сдвигаю элементы списка
void shift(int *list, int count)
{
    int current;    // Текущий первый элемент
    for (int i = 0; i < 3; i++)
    {
        current = list[0];
        for (int j = 0; j < count - 1; j++)
            list[j] = list[j + 1];
        list[count - 1] = current;
    }
}

// Заменяю числа в матрице числами из списка
void change(int **matrix, int *list, int n, int m)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (digit_sum(matrix[i][j]) > 10)
            {
                matrix[i][j] = list[temp];
                temp += 1;
            }
        }
    }
}

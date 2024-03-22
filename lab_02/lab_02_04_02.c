#include <stdio.h>

#define SIZE 10
#define OVER_SIZE 100
#define NO_ERRORS 0
#define NO_ELEMENTS 1

int scan(int*, int*);
void print(int*, int);
void sort(int*, int);
void swap(int*, int*);

int main(void)
{
    int list[SIZE];
    int n, mistake;
    int *p_n = &n;
    n = 0;
    mistake = scan(list, p_n);
    sort(list, n);
    print(list, n);
    return mistake;
}

int scan(int *list, int *p_n)
{
    int error_code = NO_ERRORS;
    int i, b, check;
    char ch;
    i = 0;
    printf("Input list:\n");
    while (*p_n < 10)
    {
        check = scanf("%d", &b);
        ch = getchar();
        if (check == 1 && (ch == '\n' || ch == ' '))
        {
            list[i] = b;
            i += 1;
            *p_n += 1;
        }
        else
            break;
    }
    if (*p_n == 10 && (scanf("%d", &b) == 1))
        error_code = OVER_SIZE;
    else if (*p_n == 0)
        error_code = NO_ELEMENTS;
    return error_code;
}

void print(int *list, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
}

void sort(int *list, int n)
{
    int index;
    for (int i = 0; i < n; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (list[j] < list[index])
                index = j;
        }
        swap(list + i, list + index);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

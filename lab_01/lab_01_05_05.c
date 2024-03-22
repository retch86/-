#include <stdio.h>
#include <math.h>

#define NO_ERRORS 0
#define WRONG_TYPE 1
#define WRONG_NUMBER 2

int countf(int);
void getanswer(int);

int main()
{
    int n, check;  // разряд, нат. число, делитель, цифра, проверка..
    int error_code = NO_ERRORS;
    printf("Input any natural number: ");
    check = scanf("%d", &n);
    if (check != 1)
    {
        printf("Erorr: Incorrect type");
        error_code = WRONG_TYPE;
    }
    else if (n <= 0)
    {
        printf("Erorr: Incorrect number");
        error_code = WRONG_NUMBER;
    }
    else
    {
        getanswer(n);
    }
    return error_code;
}

// Функция возвращает количество цифр в числе
int countf(int n)
{
    int a, count, r;
    a = 1;
    count = 0;
    r = n;
    // Цикл делит число на 10 пока число не станет ранвно 0
    while (r != 0 && a != 0)
    {
        a = r / 10;
        r /= 10;
        count += 1;
    }
    return count;
}

void getanswer(int n)
{
    int e, d, i;
    e = countf(n) - 1;
    d = pow(10, e); // возвожу число 10 в нужную степень
    // Вывожу данное число по цифрам, путем деления на d
    while (n != 0)
    {
        i = n / d;
        printf("%d", i);
        n %= d;
        d /= 10;
    }
}
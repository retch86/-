#include <stdio.h>
#include <math.h>

double getanswer(double, double, double);

int main()
{
    double a, b, deg;
    printf("Input a, b and angle: ");
    scanf("%lf%lf%lf", &a, &b, &deg);
    double s = getanswer(a, b, deg);
    printf("S = %.4lf", s);
    return 0;
}

double getanswer(double a, double b, double deg)
{
    double rad = deg * (3.1416 / 180);  // Нахожу заданный угол в радианах
    double c = fabs((b - a) / 2);
    double leg = c / cos(rad);          // Боковая сторона
    double h = leg * sin(rad);          // Высота
    // Нахожу площадь трапеции
    double s = (a + b) / 2 * h;
    return s;
}
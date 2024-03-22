#include <stdio.h>

void getanswer(double, double, double, double);

int main()
{
    setbuf(stdout, NULL);
    double v1, v2, t1, t2;
    printf("Input v1 and t1: ");
    scanf("%lf%lf", &v1, &t1);
    printf("Input v2 and t2: ");
    scanf("%lf%lf", &v2, &t2);
    getanswer(v1, v2, t1, t2);
    return 0;
}

void getanswer(double v1, double v2, double t1, double t2)
{
    // Нахожу общий объем и температуру
    double v_all = v1 + v2;
    double t_all = (t1 * v1 + v2 * t2) / v_all;
    printf("V = %.3lf\nT = %.3lf", v_all, t_all);
}
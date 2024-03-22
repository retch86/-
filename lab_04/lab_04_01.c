#include <stdio.h>
#include <string.h>

char *my_strpbrk(const char *s1, const char *s2)
{
    char *temp = NULL;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    for (size_t i = 0; i < len1; i++)
    {
        for (size_t j = 0; j < len2; j++)
        {
            if (s1[i] == s2[j])
            temp = (char *)(s1 + i);
        }
    }
    return temp;
}

size_t my_strspn(const char *s1, const char *s2)
{
    size_t temp = 0;
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    for (size_t i = 0; i < len1; i++)
    {
        for (size_t j = 0; j < len2; j++)
        {
            if (s1[i] == s2[j])
            {
                temp += 1;
                break;
            }
        }
        if (i == temp)
        break;
    }
}



int main(void)
{
    char *s1 = "Helo";
    char *s2 = "2l";
    char *a = strpbrk(s1, s2);
    char *b = my_strpbrk(s1, s2);

    printf("\nstrpbrk = %c\n", *a);
    printf("my_strpbrk = %c\n\n", *b);
    return 0;
}
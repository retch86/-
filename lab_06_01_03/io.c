#include "products.h"
#include "io.h"
#include "errors.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print_products(product *products, int n, int max_price)
{
    for (int i = 0; i < n; i++)
    {
        if (products[i].price < max_price)
        {
            printf("%s\n", products[i].name);
            printf("%d\n", products[i].price);
        }
    }
}

int read_file(char *filename, product *products, int *array_elements)
{
    FILE *f;
    int rc = OK;
    f = fopen(filename, "r");
    if (f == NULL)
    {
//        printf("Unable to open file\n");
        rc = INVALID_FILENAME;
    }
    else
    {
        int lines_count = 0;
        rc = count_lines(f, &lines_count);
        if (rc == OK)
        {
            rc = read_amount_of_products(f, array_elements, lines_count);
            if (rc == OK)
            {
                rc = read_products(f, products, *array_elements);
                fclose(f);
            }
            else
                fclose(f);
        }
        else
            fclose(f);
    }
    return rc;
}

int read_amount_of_products(FILE *f, int *array_elements, int lines_count)
{
    int rc = fscanf(f, "%d", array_elements);
    if (rc == -1)
    {
        rc = EMPTY_FILE;
//        printf("Empty file\n");
    }
    else if (rc == 0)
    {
        rc = INVALID_FIRST_STRING;
//        printf("No digit\n");
    }
    else if ((*array_elements < 0) || (*array_elements > ARRAY_COUNT))
    {
        rc = INVALID_FIRST_STRING;
//        printf("Incorrect value");
    }
    else if (*array_elements * 2 != (lines_count - 1))
    {
        rc = INVALID_DATA;
//        printf("Incorrect data count");
    }
    else
        rc = OK;
    return rc;
}

int read_products(FILE *f, product *products, int array_elements)
{
    int rc = OK;
    int check;
    char buffer[MAX_PRODUCT_NAME];
    for (int i = 0; (i < array_elements) && (rc == OK); i++)
    {
        check = fscanf(f, "%s", products[i].name);
        if ((check == -1) || (check == 0))
        {
//            printf("Invalid data(product name)\n");
            rc = INVALID_DATA;
        }
        else
        {
            check = fscanf(f, "%s", buffer);
            if (check == -1 || check == 0)
            {
//                printf("Invalid data product price\n");
                rc = INVALID_DATA;
            }
            else
            {
                products[i].price = atoi(buffer);
                if (products[i].price <= 0)
                {
//                   printf("Invalid data product price\n");
                    rc = INVALID_DATA;
                }
                else if (numerical_digit(products[i].price) != strlen(buffer))
                {
//                    printf("Invalid data product price\n");
                    rc = INVALID_DATA;
                }
            }
        }
    }
    return rc;
}

int is_file_exist(char  *filename)
{
    FILE *f;
    int rc = OK;
    f = fopen(filename, "r");
    if (f == NULL)
        rc = INVALID_FILENAME;
    if (rc == INVALID_FILENAME)
    {
        int len = MAX_FILENAME - strlen(filename) - 1;   
        strncat(filename, ".txt", len);
        f = fopen(filename, "r");
        if (f != NULL)
        {
            rc = OK;
            fclose(f);
        }
    }
    else
        fclose(f);
    return rc;
}

int count_lines(FILE *f, int *lines_count)
{
    int flag = OK;
    int rc = OK;
    char ch = fgetc(f);
    int count_str_symbols = 0;
    if (ch == EOF || ch == '\n')
    {
//        printf("Invalid empty file\n");        
        rc = EMPTY_FILE;
    }
    else
    {
        int lines = 0;
        while (!feof(f))
        {
            ch = fgetc(f);
            count_str_symbols += 1;
            if (ch == '\n' || ch == EOF)
            {
                lines++;
                count_str_symbols = 0;
            }
            else if (ch == ' ')
                flag = INVALID_DATA;
            else if (count_str_symbols > MAX_PRODUCT_NAME)
                flag = INVALID_DATA;
        }
        if ((lines - 1) % 2 == 1)
        {
//            printf("Invalid num\n");
            rc = INVALID_DATA;
        }
        else if (flag != OK)
        {
//            printf("Invalid flag\n");
            rc = INVALID_DATA;
        }
        else
            rc = fseek(f, 0, SEEK_SET);
        *lines_count = lines;
    }
    return rc;   
}

int numerical_digit(int number)
{
    int digit = 0;
    while (number != 0)
    {
        digit += 1;
        number /= 10;
    }
    return digit;
}
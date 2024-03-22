#ifndef H_IO
#define H_IO

#include <stdio.h>

#include "products.h"

int read_file(char*, product*, int*);

int read_amount_of_products(FILE*, int*, int);

int read_products(FILE*, product*, int);

void print_products(product*, int, int);

int is_file_exist(char*);

int count_lines(FILE*, int*);

int numerical_digit(int);

#endif
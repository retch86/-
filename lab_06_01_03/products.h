#ifndef H_PRODUCTS
#define H_PRODUCTS

#define MAX_PRODUCT_NAME 25
#define MAX_FILENAME 255
#define ARRAY_COUNT 15


struct products_t
{
    char name[MAX_PRODUCT_NAME + 1];
    int price;
};

typedef struct products_t product;

#endif

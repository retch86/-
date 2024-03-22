#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "products.h"
#include "io.h"
#include "errors.h"

int main(int argc, char *argv[])
{
    product array[ARRAY_COUNT];
    int rc = OK;
    int array_elements;
    if (argc != 3)
    {
//        printf("Incorrect arguments count\n");
        rc = INVALID_ARGC_COUNT;
    }
    if (rc == OK)
    {
        int max_price = atof(argv[2]);
        if (max_price <= 0)
        {
//            printf("Incorrect price in the argumets\n");
            rc = INVALID_ATOI;
        }
        else
        {
            char filename[MAX_FILENAME];
            strncpy(filename, argv[1], MAX_FILENAME - 1);
            filename[sizeof(filename) - 1] = '\0';
            rc = is_file_exist(filename);
            if (rc == OK)
            {
                rc = read_file(filename, array, &array_elements);
                if (rc == OK)
                    print_products(array, array_elements, max_price);
            }
        }
    }
//    printf("\n%d", rc);
    return rc;
}

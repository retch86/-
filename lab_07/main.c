#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define READ_ERROR -1
#define ARG_COUNT_ERROR -2
#define EMPTY_FILE -3
#define FILE_I_OPEN_ERROR -4
#define FILE_READ_ERROR -5
#define MEMORY_ERROR -6
#define INVALID_DATA -7
#define FILE_W_OPEN_ERROR -8

void insertion_sort(int *array, int n)
{
    int j, key;
    for (int i = 0; i < n; i++)
    {
        j = i;
        key = array[i];
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = key;
    }
}

int compare_int(const void *p, const void *q)
{
    return *(int*)p - *(int*)q;
}

//   mysort(array, n, sizeof(int), compare_int);
void mysort(void *base, size_t num, size_t size, int(*compare)(const void*, const void*))
{
    int lo, hi, mid; // low, high, mid indexes
    void* key = NULL;
    void* base_t = NULL;
    void* base_t1 = NULL;
    for (int i = 0; i < num; i++)
    {
        base_t = (char*)base + i * size;
        memcpy(key, base_t, size);
        lo = 0;
        hi = i;
        while (lo < hi)
        {
            mid = lo + ((hi - lo) / 2);
            base_t = (char*)base + mid * size;
            if (compare(key, base_t) < 0)
                hi = mid;
            else
                lo = mid + 1;
        }
        for (int j = i; j >= (lo + 1); --j)
        {
            base_t = (char*)base + j * size;
            base_t1 = (char*)base + (j - 1) * size;
            memcpy(base_t, base_t1, size);
        }
        base_t = (char*)base + lo * size;
        memcpy(base_t, key, size);
    }
}

void binary_insertion_sort(int *array, int n)
{
    int key, lo, hi, mid;
    for (int i = 0; i < n; i++)
    {
        key = array[i];
        lo = 0;
        hi = i;
        while (lo < hi)
        {
            mid = lo + ((hi - lo) / 2);
            if (key < array[mid])
                hi = mid;
            else
                lo = mid + 1;
        }
        for (int j = i; j >= (lo + 1); --j)
            array[j] = array[j - 1];
        array[lo] = key;
    }
}

int read_number_count_from_file(char *filename, int *n)
{
    int rc = OK;
    FILE *f = fopen(filename, "r");
    int scan_buffer;
    if (f != NULL)
    {
        while (!feof(f) && rc == OK)
        {
            if (fscanf(f, "%d", &scan_buffer) == 1)
                *n += 1;
            else
                rc = FILE_READ_ERROR;
//            printf("%d\n", scan_buffer);
        }
        fclose(f);
    }
    else
        rc = FILE_I_OPEN_ERROR;    
    return rc;
}

int read_array_from_file(char *filename, int *array, int n)
{
    int rc = OK;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        for (int i = 0; i < n && rc == OK; i++)
        {
            if (fscanf(f, "%d", array + i) != 1)
                rc = INVALID_DATA;
        }
        fclose(f);
    }
    else
        rc = FILE_I_OPEN_ERROR;
    return rc;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
        printf("\n");
    }
}

int write_array(char *filename, int *array, int n)
{
    int rc = OK;
    FILE *f = fopen(filename, "w");
    if (f == NULL)
        rc = FILE_W_OPEN_ERROR;
    if(!rc)
    {
        for (int i = 0; i < n; i++)
            fprintf(f, "%d\n", array[i]);
        fclose(f);
    }
    return rc;
}


int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    int n = 0; // кол во эл в файле
//    int *pb_array, *pe_array = NULL;
//    int *pb_copy_array, *pe_copy_array = NULL;
    int flag_filter = 0;

    if (argc == 3)
        flag_filter = 0;
    else if (argc == 4 && strcmp(argv[3], "f") == 0)
        flag_filter = 1;
    else
    {
        rc = ARG_COUNT_ERROR;
        printf("u r baka = %d\n", flag_filter);
    }

    if (rc == OK)
    {
        rc = read_number_count_from_file(argv[1], &n);
        if (rc == OK)
        {
            printf("n = %d\n", n);

            int *array = malloc(n * sizeof(int));
            if (array == NULL)
                rc = MEMORY_ERROR;
            if (rc == OK)
            {
                rc = read_array_from_file(argv[1], array, n);
                if (rc == OK)
                {
                    print_array(array, n);
                    mysort(array, n, sizeof(int), compare_int);
                    rc = write_array(argv[2], array, n);
                }
            }
            free(array);
        
        }
    }
    return rc;
}

// test insertion_sort again!
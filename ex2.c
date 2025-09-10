#include <stdio.h>
#include <stdlib.h>
#include "fibo_algorithms.h"


int main()
{
    long *count = (long*) malloc (sizeof(long));
    *count = 0;
    count_mem_fibo(4, count);
    printf("teste para 4 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",count_fibo_rec(4, 0), count_fibo(4), *count);
    *count = 0;
    count_mem_fibo(8, count);
    printf("\nteste para 8 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",count_fibo_rec(8, 0), count_fibo(8), *count);
    *count = 0;
    count_mem_fibo(16, count);
    printf("\nteste para 16 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",count_fibo_rec(16, 0), count_fibo(16), *count);
    *count = 0;
    count_mem_fibo(32, count);
    printf("\nteste para 32 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",count_fibo_rec(32, 0), count_fibo(32), *count);

    printf("-------------------------------------------------------------------------------\n");
    *count = 0;
    count_mem_fibo(128, count);
    printf("teste para 128 \nsegundo: %ld \nterceiro: %ld \n", count_fibo(128), *count);
    *count = 0;
    count_mem_fibo(1000, count);
    printf("\nteste para 1000 \nsegundo: %ld \nterceiro: %ld \n", count_fibo(1000), *count);
    *count = 0;
    count_mem_fibo(10000, count);
    printf("\nteste para 10000 \nsegundo: %ld \nterceiro: %ld \n", count_fibo(10000), *count);

    return 0;
}
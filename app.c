#include <stdio.h>
#include <stdlib.h>
#include "fibo_algorithms.h"


int main()
{
    printf("teste para 4 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",fibo_rec(4), fibo(4), mem_fibo(4));
    printf("\nteste para 8 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",fibo_rec(8), fibo(8), mem_fibo(8));
    printf("\nteste para 16 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",fibo_rec(16), fibo(16), mem_fibo(16));
    printf("\nteste para 32 \nprimeiro: %ld \nsegundo: %ld \nterceiro: %ld \n",fibo_rec(32), fibo(32), mem_fibo(32));

    printf("-------------------------------------------------------------------------------\n");

    printf("teste para 128 \nsegundo: %ld \nterceiro: %ld \n", fibo(128),mem_fibo(128));
    printf("\nteste para 1000 \nsegundo: %ld \nterceiro: %ld \n", fibo(1000),mem_fibo(1000));
    printf("\nteste para 10000 \nsegundo: %ld \nterceiro: %ld \n", fibo(10000),mem_fibo(10000));

    return 0;
}
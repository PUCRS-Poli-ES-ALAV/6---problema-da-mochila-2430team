#include <stdio.h>
#include <stdlib.h>

long fibo_rec(long n)
{
    if (n < 0)
    {
        fprintf(stderr, "invalid number");
        return -1;
    }

    if (n == 1 || n == 0)
    {
        return n;
    }

    return fibo_rec(n - 1) + fibo_rec(n - 2);
}

long fibo(long n) 
{
    long f[n + 1];
    f[0] = 0;
    f[1] = 1;

    for (long i = 2; i <= n; i++) 
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

long lookup_fibo(long *f, long n)
{
    if (f[n] >= 0)
    {
        return f[n];
    }
    if (n <= 1)
    {
        f[n] = n;
    }
    else {
        f[n] = lookup_fibo(f, n - 1) + lookup_fibo(f, n - 2);
    }
    return f[n];
}

long mem_fibo(long n)
{
    long f[n + 1];
    for (long i = 0; i <= n; i++)
    {
        f[i] = -1;
    }
    return lookup_fibo(f, n);
}




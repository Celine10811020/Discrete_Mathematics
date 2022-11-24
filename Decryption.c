#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

unsigned long findPrime(unsigned int n);

int main()
{
    unsigned int i, j;
    unsigned long num, temp;
    unsigned long n, one, two, phi, t;
    unsigned int e;
    unsigned int m[50] = {};
    unsigned int length;
    char arr[20];
    int val;

    scanf("%lu", &n);
    scanf("%u", &e);

    val=getchar();

    i = 0;
    j = 0;
    while(val=getchar())
    {
        //val = val - 48;
        //printf("val: %d\n", val);
        if(val == 44)
        {
            //printf("%d\n", m[j]);
            j++;
        }else if(val >= 48 && val <= 57)
        {
            m[j] = m[j]*10 + val - 48;
            //printf("%d\n", m[j]);
        }else
        {
            j++;
            break;
        }
    }
    /*arr[i] = '\0';
    m[j] = atoi(arr);
    j++;*/

    one = findPrime(n);
    two = n / one;
    phi = (one-1) * (two-1);

    #pragma omp parallel for
    for(i=1; i<2147483647; i++)
    {
        temp = (1 + (i*phi)) % e;

        if(temp == 0)
        {
            t = (1 + (i*phi)) / e;
            break;
        }
    }

    length = j;

    for(i=0; i<length; i++)
    {
        temp = 1;
        num = (unsigned int)m[i];
        for(j=0; j<t; j++)
        {
            temp *= num;

            if(temp >= n)
            {
                temp %= n;
            }
        }
        printf("%c", (char)temp);
    }

    return 0;
}

unsigned long findPrime(unsigned int n)
{
    unsigned int i;

    #pragma omp parallel for
    for(i=2; i<n; i++)
    {
        if(n%i == 0)
        {
            return i;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

int main()
{
    unsigned int i, j;
    unsigned long temp;
    unsigned long n;
    unsigned int e;
    unsigned int m[100] = {};
    unsigned int length;
    int val;

    scanf("%lu", &n);
    scanf("%u", &e);
    val = getchar();

    i = 0;
    while((val=getchar()) >= 32)
    {
        m[i] = val;
        i++;
    }

    length = i;

    temp = 1;
    #pragma omp parallel for
    for(j=0; j<e; j++)
    {
        temp *= m[0];

        if(temp >= n)
        {
            temp %= n;
        }
    }
    printf("%lu", temp);


    for(i=1; i<length; i++)
    {
        temp = 1;
        #pragma omp parallel for
        for(j=0; j<e; j++)
        {
            temp *= m[i];

            if(temp >= n)
            {
                temp %= n;
            }
        }
        printf(",%lu", temp);
    }
    return 0;
}

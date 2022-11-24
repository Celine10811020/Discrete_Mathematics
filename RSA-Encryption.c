#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void xiangCheng(int i); //(diJiGeShu);
int quMod(int i);
int biDaXiao(int i);
void xiangJian(int i);


char m[100];
int bigNum[100][100] = {};
int bigN[20];
int nDeWeiShu[1];
int jiWeiShu[100];
int ans[100000];
int beiChengShu[100000];
int beiJianShu[100000];
int beiChengShuDeWeiShu[1];
int beiJianShuDeWeiShu[1];

int main()
{
    int i, j, temp;
    long n;
    int e;
    int length, len;
    char asc[100];


    scanf("%ld", &n);

    i = 0;
    while(n != 0)
    {
        bigN[i] = n % 10;
        n = n / 10;

        i++;
    }
    nDeWeiShu[0] = i;

    scanf("%d", &e);
    scanf("%s", m);

    length = strlen(m);

    for(i=0; i<length; i++)
    {
        memset(asc, 0, 100);

        sprintf(asc, "%d", m[i]);

        len = strlen(asc);
        temp = atoi(asc);
        for(j=0; j<len; j++)
        {
            bigNum[i][j] = temp % 10;
            temp = temp / 10;
        }
        jiWeiShu[i] = len;

        //printf("%s ", asc);
    }

    /*printf("\n");
    for(i=0; i<length; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d", bigNum[i][j]);
        }
        printf("\n");
    }*/

    //printf("\n");
    for(i=0; i<length; i++)
    {
        memset(beiChengShu, 0, sizeof(beiChengShu));
        beiChengShu[0] = 1;
        beiChengShuDeWeiShu[0] = 1;

        for(j=0; j<e; j++)
        {
            //printf("di %d ge, cheng di %d ci:\n", i, j);
            xiangCheng(i);
        }

        j = beiChengShuDeWeiShu[0];
        while(beiChengShu[j] == 0)
        {
            j--;
        }
        beiJianShuDeWeiShu[0] = j + 1;

        /*printf("xiangChengJieGuo:\n");
        for(j=0; j<beiJianShuDeWeiShu[0]; j++)
        {
            printf("%d", beiChengShu[j]);
        }
        printf("\n\n");*/

        //beiChengShu shi da an

        temp = quMod(i);

        if(temp == 3)
        {
            printf("0,");
            continue;
        }

        //printf("quModJieGuo:\n");
        for(j=beiJianShuDeWeiShu[0]-1; j>=0; j--)
        {
            printf("%d", beiChengShu[j]);
        }
        if(i == length-1)
        {
            break;
        }
        printf(",");
    }

    /*printf("\n");
    for(i=0; i<length; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d", bigNum[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}

int quMod(int i)
{
    int goOn = biDaXiao(i);

    while(goOn)
    {
        xiangJian(i);

        goOn = biDaXiao(i);

        //printf("goOn: %d\n", goOn);
        //system("PAUSE");
    }

    if(goOn == 3)
    {
        return 3;
    }else
    {
        return 1;
    }
}

void xiangJian(int i)
{
    int j, temp;

    //memset(ans, 0, sizeof(ans));

    for(j=0; j<beiJianShuDeWeiShu[0]; j++)
    {
        if(beiChengShu[j]-bigN[j] >= 0)
        {
            beiChengShu[j] = beiChengShu[j] - bigN[j];
        }else
        {
            beiChengShu[j] = beiChengShu[j]+10 - bigN[j];
            beiChengShu[j+1]--;
        }
    }

    temp = beiJianShuDeWeiShu[0] - 1;
    //printf("temp: %d (%d)\n", temp, ans[temp]);
    while(beiChengShu[temp] == 0)
    {
        temp--;
    }
    beiJianShuDeWeiShu[0] = temp + 1;

    //printf("xiangJian:\n");
    /*for(j=0; j<beiJianShuDeWeiShu[0]; j++)
    {
        beiChengShu[j] = ans[j];
        //printf("%d", ans[j]);
    }*/
    //printf("\n");
}

int biDaXiao(int i)
{
    int j;

    if(beiJianShuDeWeiShu[0] > nDeWeiShu[0])
    {
        return 1;
    }else if(beiJianShuDeWeiShu[0] < nDeWeiShu[0])
    {
        return 0;
    }else //weiShuXiangDeng
    {
        for(j=nDeWeiShu[0]-1; j>=0; j--)
        {
            if(beiChengShu[j] > bigN[j])
            {
                return 1;
            }else if(beiChengShu[j] < bigN[j])
            {
                return 0;
            }
        }

        return 3;
    }
}



void xiangCheng(int i)
{
    int j, k, temp;

    memset(ans, 0, sizeof(ans));

    for(j=0; j<jiWeiShu[i]; j++)
    {
        for(k=0; k<beiChengShuDeWeiShu[0]; k++)
        {
            ans[j+k] = ans[j+k] + bigNum[i][j]*beiChengShu[k];
        }
    }

    temp = jiWeiShu[i] + beiChengShuDeWeiShu[0];
    for(j=0; j<=temp; j++)
    {
        if(ans[j] >= 10)
        {
            ans[j+1] = ans [j+1] + ans[j]/10;
            ans[j] = ans[j] % 10;
        }
    }

    beiChengShuDeWeiShu[0] = temp;

    for(j=0; j<temp; j++)
    {
        beiChengShu[j] = ans[j];

        //printf("%d", ans[j]);
    }
    //printf("\n");
}


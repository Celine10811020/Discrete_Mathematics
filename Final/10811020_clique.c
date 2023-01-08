#include <stdio.h>
#include <stdlib.h>

void findCliques(int now, int index);
int checkClique(int index);
void saveAnswer(int num);
void checkAnswer(int num);
int max(int one, int two);
int min(int one, int two);

int node;
long ansNum = 0;
int maxCliques = 0;
int indexStart;
char store[101] = {};
char graph[101][101] = {};
short answer[1000000][50] = {};
int availableAns[1000] = {};
int ansCount[102][1000] = {};

int main()
{
    int i, j, k, temp, tmp, tp, ttpp;
    int one, two;

    node = 0;
    indexStart = 2147483647;

    while(scanf("%d", &one) != EOF)
    {
        scanf("%d", &two);

        graph[one+1][two+1] = 1;
        graph[two+1][one+1] = 1;

        node = max(node, one+1);
        node = max(node, two+1);

        indexStart = min(indexStart, one);
        indexStart = min(indexStart, two);
    }

    findCliques(0, 1);

    checkAnswer(ansNum);

    for(i=2; i<=maxCliques; i++)
    {
        ansCount[i][0] = 1;
    }

    temp = availableAns[0];

    for(i=1; i<temp; i++)
    {
        tp = availableAns[i];

        ttpp = answer[tp][0];

        tmp = ansCount[ttpp][0];
        ansCount[ttpp][tmp] = tp;
        ansCount[ttpp][0]++;
    }

    for(i=2; i<=maxCliques; i++)
    {
        temp = ansCount[i][0];

        if(temp == 1)
        {
            continue;
        }

        printf("%d\n", i-1);

        for(j=1; j<temp; j++)
        {
            tmp = ansCount[i][j];

            tp = answer[tmp][0];

            printf("{%d", answer[tmp][1]);
            for(k=2; k<tp; k++)
            {
                printf(",%d", answer[tmp][k]);
            }
            printf("}\n");
        }
    }

    return 0;
}

int gogoOn;

void findCliques(int now, int index)
{
    int i;
    int goOn;

    gogoOn = 0;

    for(i=now+1; i<=node; i++)
    {
        store[index] = i;

        goOn = checkClique(index+1);

        if(goOn)
        {
            findCliques(i, index+1);

            if(gogoOn==0 || index==node-1)
            {
                saveAnswer(index+1);
            }

            gogoOn = 1;
        }
    }
}

int checkClique(int index)
{
    int i, j;

    for(i=1; i<index; i++)
    {
        for(j=i+1; j<index; j++)
        {
            if(graph[store[i]][store[j]] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

void saveAnswer(int num)
{
    int i;

    if(num <= 2)
    {
        return;
    }else
    {
        for(i=1; i<num; i++)
        {
            answer[ansNum][i] = store[i] - 1;
        }
    }

    answer[ansNum][0] = num;

    maxCliques = max(maxCliques, num);

    ansNum++;
}

void checkAnswer(int num)
{
    int i, j, k, m, temp, tmp;
    int subString;
    int index;

    availableAns[1] = 0;
    index = 2;

    for(i=1; i<num; i++)
    {
        subString = 0;

        for(j=index-1; j>=1; j--)
        {
            tmp = availableAns[j];

            temp = answer[tmp][0];

            m = 1;
            for(k=1; k<temp; k++)
            {
                if(answer[tmp][k] == answer[i][m])
                {
                    m++;
                }
            }

            if(m == answer[i][0])
            {
                subString = 1;

                break;
            }
        }

        if(subString == 0)
        {
            availableAns[index] = i;
            index++;
        }
    }

    availableAns[0] = index;
}

int max(int one, int two)
{
    if(one > two)
    {
        return one;
    }else
    {
        return two;
    }
}

int min(int one, int two)
{
    if(one < two)
    {
        return one;
    }else
    {
        return two;
    }
}

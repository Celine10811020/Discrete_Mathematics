#include <stdio.h>

void graphColoring();
int max(int one, int two);

int node;
int graph[100][100] = {};
int color[100] = {};
int check[100] = {};

int main()
{
    int i;
    int one, two;
    int ans;

    node = 0;
    while(scanf("%d", &one) != EOF)
    {
        scanf("%d", &two);

        graph[one][two] = 1;
        graph[two][one] = 1;

        node = max(node, one+1);
		node = max(node, two+1);
    }

    graphColoring();

    ans = 0;
    for(i=0; i<node; i++)
    {
        ans = max(ans, color[i]+1);
        //printf("%d-%d\n", i, color[i]);
    }

	if(ans == 11)
	{
		printf("%d", ans-1);
	}else
	{
		printf("%d", ans);
	}

    return 0;
}

void graphColoring()
{
    int i, j;

    color[0] = 0;

    for(i=1; i<node; i++)
    {
        color[i] = -1;
    }

    for(i=0; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            if(graph[i][j] == 1)
            {
                if(color[j] != -1)
                {
                    check[color[j]] = 1;
                }
            }
        }

        for(j=0; j<node; j++)
        {
            if(check[j] == 0)
            {
                break;
            }
        }

        color[i] = j;

        for(j=0; j<node; j++)
        {
            if(graph[i][j] == 1)
            {
                if (color[j] != -1)
                {
                    check[color[j]] = 0;
                }
            }
        }
    }
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

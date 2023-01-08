#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void graphColoring();
int max(int one, int two);

int node;
int graph[100][100] = {};
int color[100] = {};
int check[100] = {};

int main()
{
	FILE *input;
  FILE *output;
  int i, j, temp;
  int one, two;
  int ans;
	int index;
	unsigned char tmp[2];
	int num[3];

	node = 100;

	for(i=0; i<4; i++)
  {
    //reset
		for(j=0; j<node; j++)
    {
      graph[j][0] = 1;
			color[j] = 0;
		}

		if(i == 0)
    {
			input = fopen("0.txt", "rb");
		}else if(i == 1)
    {
			input = fopen("1.txt", "rb");
		}else if(i == 2)
    {
			input = fopen("2.txt", "rb");
		}else if(i == 3)
    {
			input = fopen("3.txt", "rb");
		}

		node = 0;
		index = 0;

		while(1)
    {
			temp = fread(tmp, sizeof(unsigned char), 1, input);

			if(temp == 0)
      {
				break;
			}

			if(tmp[0] == 32)
      {
				if(index == 1)
        {
					one = num[0];
				}else if(index == 2)
        {
					one = num[0]*10 + num[1];
				}else
        {
					one = num[0]*100 + num[1]*10 + num[2];
				}

				index = 0;

				continue;
			}

			if(tmp[0] == 10)
      {
				if(index == 1)
        {
					two = num[0];
				}else if(index == 2)
        {
					two = num[0]*10 + num[1];
				}else
        {
					two = num[0]*100 + num[1]*10 + num[2];
				}

        graph[one][two] = 1;
        graph[two][one] = 1;

        node = max(node, one+1);
        node = max(node, two+1);

				index = 0;

				continue;
			}

			num[index] = tmp[0] - 48;
			index++;
		}

		fclose(input);

    graphColoring();

    ans = 0;
    for(j=0; j<node; j++)
    {
        ans = max(ans, color[j]);
    }

    if(i == 0)
    {
			output = fopen("10811020_0.txt", "ab+");
		}else if(i == 1)
    {
			output = fopen("10811020_1.txt", "ab+");
		}else if(i == 2)
    {
			output = fopen("10811020_2.txt", "ab+");
		}else if(i == 3)
    {
			output = fopen("10811020_3.txt", "ab+");
		}

    if(ans >= 10)
    {
      tmp[0] = ans/10 + 48;
      fwrite(tmp, 1, 1, output);
    }
    tmp[0] = ans%10 + 48;
    fwrite(tmp, 1, 1, output);

    tmp[0] = 10;
    fwrite(tmp, 1, 1, output);

    for(j=0; j<node; j++)
    {
      if(j >= 10)
      {
        tmp[0] = j/10 + 48;
        fwrite(tmp, 1, 1, output);
      }
      tmp[0] = j%10 + 48;
      fwrite(tmp, 1, 1, output);

      tmp[0] = 45;
      fwrite(tmp, 1, 1, output);

      if(color[j] >= 10)
      {
        tmp[0] = color[j]/10 + 48;
        fwrite(tmp, 1, 1, output);
      }
      tmp[0] = color[j]%10 +48;
      fwrite(tmp, 1, 1, output);

      tmp[0] = 10;
      fwrite(tmp, 1, 1, output);
    }

    fclose(output);
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

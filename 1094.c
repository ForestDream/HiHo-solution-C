#include<stdio.h>

int n;
int m;
char grid[200][201];
char Hi[4][3][4];
int x, y;

void rotate(char dst[3][4], char src[3][4])
{
    int j;
    
    dst[1][1] = src[1][1];
    for (j=0; j<3; j++)
    {
        dst[j][2] = src[0][j];
        dst[j][0] = src[2][j];
        
        dst[2][2-j] = src[j][2];
        dst[0][2-j] = src[j][0];
    }
}

void position(void)
{
    int i, j, ii, jj, k;
    int flag;
    
    for (i=0; i<n-2; i++)
    {
        for (j=0; j<m-2; j++)
        {
            for (k=0; k<4; k++)
            {
                flag = 1;
                for (ii=0; ii<3; ii++)
                {
                    for (jj=0; jj<3; jj++)
                    {
                        if (grid[i+ii][j+jj] != Hi[k][ii][jj])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    
                    if (flag == 0)
                    {
                        break;
                    }
                }
                
                if (flag == 1)
                {
                    x = i + 2;
                    y = j + 2;
                    printf("%d %d\n", x, y);
                    break;
                }
            }
        }
    }
}

int main(void)
{
    int i;
    
    scanf("%d %d", &n, &m);
    for (i=0; i<n; i++)
    {
        scanf("%s", grid[i]);
    }
    
    for (i=0; i<3; i++)
    {
        scanf("%s", Hi[0][i]);
    }
    
    rotate(Hi[1], Hi[0]);
    rotate(Hi[2], Hi[1]);
    rotate(Hi[3], Hi[2]);
    position();
    
    return 0;
}

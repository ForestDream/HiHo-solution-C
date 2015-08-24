/**************************************
* String Matching Content Length v1.0
**************************************/

#include<stdio.h>
#include<string.h>
#define max(a, b) a>b?a:b

char a[2101];
char b[2101];
char dp[2100][2100];
char dp1[2100][2100];
char ff[2100][2100];

int main(void)
{
    int len_a, len_b;
    int i_a, i_b;
    int j;
    
    scanf("%s%s", a, b);
    len_a = strlen(a);
    len_b = strlen(b);
    
    for (i_a=1; i_a<=len_a; i_a++)
    {
        for (i_b=1; i_b<=len_b; i_b++)
        {
            if (a[i_a-1] == b[i_b-1])
            {
                ff[i_a][i_b] = ff[i_a-1][i_b-1] + 1;
            }
            else
            {
                ff[i_a][i_b] = 0;
            }
            // printf("ff %2d %2d %d\n", i_a, i_b, ff[i_a][i_b]);
        }
    }
    
    for (i_a=1; i_a<=len_a; i_a++)
    {
        for (i_b=1; i_b<=len_b; i_b++)
        {
            dp[i_a][i_b] = max(dp[i_a-1][i_b], dp[i_a][i_b-1]);
            if (ff[i_a][i_b] >= 3)
            {
                dp[i_a][i_b] = max(dp[i_a][i_b], dp1[i_a-3][i_b-3] + 3);
                if (ff[i_a][i_b] > 3)
                {
                    dp[i_a][i_b] = max(dp[i_a][i_b], dp[i_a-1][i_b-1] + 1);
                }
            }
            dp1[i_a][i_b] = max(dp1[i_a-1][i_b], dp1[i_a][i_b-1]);
            dp1[i_a][i_b] = max(dp1[i_a][i_b], dp[i_a][i_b]);
            // printf("dp %2d %2d %d\n", i_a, i_b, dp[i_a][i_b]);
        }
    }
    printf("%d\n", dp[len_a][len_b]);
    return 0;
}

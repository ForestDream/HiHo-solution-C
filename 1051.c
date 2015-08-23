#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int t;
    int n;
    int m;
    int * day;
    int * day_interval;
    int max;
    int tmp;
    int i;
    int j;
    
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        
        day = malloc(n * sizeof(int));
        day_interval = malloc((n + 1) * sizeof(int));
        for (i=0; i<n; i++)
        {
            scanf("%d", &day[i]);
            if (i == 0)
            {
                day_interval[i] = day[i] - 1;
            }
            else
            {
                day_interval[i] = day[i] - day[i-1] - 1;
            }
            
        }
        day_interval[n] = 100 - day[n-1];
        
        if (n > m)
        {
            max = 0;
            for (i=0; i<=n-m; i++)
            {
                tmp = m;
                for (j=i; j<=i+m; j++)
                {
                    tmp += day_interval[j];
                }
                if (max < tmp)
                {
                    max = tmp;
                }
            }
            printf("%d\n", max);
        }
        else
        {
            printf("100\n");
        }
    }
    return 0;
}

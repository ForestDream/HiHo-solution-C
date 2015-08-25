#include<stdio.h>
int n, d[202], i, j, x, y, t;
int main(void){
    scanf("%d", &n);
    for (i=0; i<n; i++)
        for (t=j=0; j<=i; j++){
            scanf("%d", &x);
            y = d[j];
            d[j] = (y>t?y:t) + x;
            t = y;
        }
    for (j=1; j<n; j++)
        if (d[0] < d[j])
            d[0] = d[j];
    printf("%d\n", d[0]);
    return 0;
}

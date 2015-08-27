#include<stdio.h>
int n,m,x,y,f[100001],i,j,k;
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        for(k=1;k<=m/x;k++)
            for(j=m;j>=k*x;j--)
                f[j]=f[j]>(f[j-k*x]+k*y)?f[j]:(f[j-k*x]+k*y);
    }
    printf("%d\n", f[m]);
    return 0;
}

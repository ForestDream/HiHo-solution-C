#include<stdio.h>
int n,m,x,y,f[100001],i,j;
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        for(j=m;j>=x;j--)
            f[j]=f[j]>(f[j-x]+y)?f[j]:(f[j-x]+y);
    }
    printf("%d\n", f[m]);
}

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    int n;
    int i, j, k;
    char * str;
    char * c;
    int * m;
    
    scanf("%d", &t);
    while (t--) {
        
        
        scanf("%d", &n);
        
        str = (char *)malloc((n+1)*sizeof(char));
        c = (char *)malloc((n+1)*sizeof(char));
        m = (int *)malloc((n+1)*sizeof(int));
        
        scanf("%s", str);
        c[0] = str[0];
        m[0] = 1;
        j = 0;
        
        for (i=1; i<n; i++) {
            if (str[i] == c[j]) {
                m[j]++;
            }
            else{
                j++;
                c[j] = str[i];
                m[j] = 1;
            }
        }
        
        for (k=0; k<=j-2; k++) {
            if ((c[k]+1 == c[k+1] && c[k]+2 == c[k+2]) && (m[k] >= m[k+1] && m[k+2] >= m[k+1])) {
                printf("YES\n");
                break;
            }
        }
        if (k > j-2) {
            printf("NO\n");
        }
        free(str);
        free(c);
        free(m);
    }
    return 0;
}

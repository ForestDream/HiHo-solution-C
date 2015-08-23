/* 
* 朴素搜索 
*/

#include<stdio.h>
#include<string.h>

int main(){
    int n;
    
    scanf("%d", &n);
    while (n--) {
        int i, j, k;
        int len;
        int subLen;
        int maxSubLen;
        char str[1000000];
    
        scanf("%s", str);
        len = strlen(str);
        
        maxSubLen = 1;
        for (i=0; i<len-1; i++) {
            subLen = 1;
            for (j=len-1; j>0; j--) {
                for (k=0; k<=(j-i)/2; k++) {
                    if (str[i+k] != str[j-k]) {
                        break;
                    }
                }
                if(k == (j-i)/2 +1){
                    subLen = j-i+1;
                    break;
                }
            }
            if(subLen > maxSubLen){
                maxSubLen = subLen;
            }
        }
        printf("%d\n", maxSubLen);
    }
    return 0;
}

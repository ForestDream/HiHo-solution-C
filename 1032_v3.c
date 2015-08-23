/* 
* 枚举的时候不是把第i个字符作为子字符串的开始，而是作为子字符串的中心
* 当然这是仅考虑子字符串是基数的情况
* 把已知的作为限制条件，减少计算量
*/

#include<stdio.h>
#include<string.h>

int min(int a, int b){
    if (a < b)
        return a;
    else
        return b;
}

int main(){
    int n;
    
    scanf("%d", &n);
    while (n--) {
        int i, j;
        char str[1000000];
        int len;
        int subLen[100000];
        int maxSubLen;
        int maxRight;
        int maxRightCenter;
        
        scanf("%s", str);
        len = strlen(str);
        
        maxSubLen = subLen[0];
        maxRight = 1;
        maxRightCenter = 1;
        
        for (i=1; i<len-1; i++) {
            j = ((min(subLen[2*maxRightCenter-i], subLen[maxRightCenter]-2*(i-maxRightCenter)))+1)/2;
            while (i-j>=0 && i+j<=len-1) {
                if (str[i-j] == str[i+j]) {
                    j++;
                }
            }
            //printf("%d  ", j);
            subLen[i] = 2*j-1;
            if (maxSubLen < subLen[i]) {
                maxSubLen = subLen[i];
            }
            if (maxRight < i+j-1) {
                maxRight = i+j-1;
                maxRightCenter = i;
            }
        }
        printf("%d  %d\n", maxSubLen, maxRight); 
    }
    return 0;
}

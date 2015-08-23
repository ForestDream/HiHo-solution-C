/* 
* update: 在v3的能够处理奇数串的基础上，把所有字符串扩展成奇数串
* 枚举的时候不是把第i个字符作为子字符串的开始，而是作为子字符串的中心
* 当然这是仅考虑子字符串是基数的情况
* 把已知的作为限制条件，减少计算量
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000000

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
        char * str;
        char * strExt; /* 插入特殊字符后的字符串，其长度必为奇数 */
        int len;
        int lenExt; /* 扩展字符串的长度 */
        int subLen;
        int * subLenExt;
        int maxSubLen;
        int maxRight;
        int maxRightCenter;
        
        str = (char *)malloc((MAX+1)*sizeof(char));
        strExt = (char *)malloc((2*MAX)*sizeof(char));
        subLenExt = (int *)malloc((2*MAX-1)*sizeof(int));
        
        scanf("%s", str);
        len = strlen(str);
        
        /* 插入字符串，扩展成奇数长度 */
        for (i=0; i<len-1; i++) {
            strExt[2*i] = str[i];
            strExt[2*i+1] = '|';
        }
        strExt[2*i] = str[i];
        strExt[2*i+1] = '\0';
        lenExt = 2*len-1;
        for (i=0; i<lenExt; i++){
            subLenExt[i] = 1;
        }

        /* 求扩展字符串的回文子串长度，然后计算原字符串相应回文子串的长度 */
        maxSubLen = 1;
        maxRight = 1;
        maxRightCenter = 1;
        
        for (i=1; i<lenExt-1; i++) {
            j = ((min(subLenExt[2*maxRightCenter-i], subLenExt[maxRightCenter]-2*(i-maxRightCenter)))+1)/2;
            
            while (i-j>=0 && i+j<=lenExt-1) {
                if (strExt[i-j] == strExt[i+j]) {
                    j++;
                }
                else{
                    break;
                }
            }
           
            subLenExt[i] = 2*j-1;
            
            if (strExt[i] == '|') {
                if ((subLenExt[i]-1)%4 == 0) {
                    subLen = (subLenExt[i]-1)/2;
                }
                else {
                    subLen = (subLenExt[i]-1)/2+1;
                }
            }
            else {
                if ((subLenExt[i]-1)%4 == 0) {
                    subLen = (subLenExt[i]-1)/2+1;
                }
                else {
                    subLen = (subLenExt[i]-1)/2;
                }
            }
            
            if (maxSubLen < subLen) {
                maxSubLen = subLen;
            }
            if (maxRight < i+j-1) {
                maxRight = i+j-1;
                maxRightCenter = i;
            }
        }
        printf("%d\n", maxSubLen); 
        free(str);
        free(strExt);
        free(subLenExt);
    }
    return 0;
}

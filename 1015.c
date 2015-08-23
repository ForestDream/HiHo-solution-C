
#include<stdio.h>
#include<string.h>

int main(){
    int n;
    char pattern_str[10001];
    char original_str[1000001];
    int next[10001];
    int len_pattern_str;
    int len_original_str;
    int count;
    int i, j;
    
    scanf("%d", &n);
    while (n--) {
        scanf("%s", pattern_str);
        scanf("%s", original_str);
        
        len_pattern_str = strlen(pattern_str);
        len_original_str = strlen(original_str);
        
        /* 计算的pattern_str对应的next数组 */
        next[0] = 0;
        for (i=1; i<len_pattern_str; i++) {
            if (pattern_str[next[i-1]] == pattern_str[i]) {
                next[i] = next[i-1] + 1;
            }
            else if (pattern_str[0] == pattern_str[i]) {
                next[i] = 1;
            }
            else {
                next[i] = 0;
            }
            //printf("[i]%d  %d\n", i, next[i]);
        }
        /* 进行匹配 */
        count = 0;
        i = 0;
        j = 0;
        while (i < len_original_str) {
            while (j < len_pattern_str) {
                //printf("[i]%d [j]%d\n", i, j);
                if (original_str[i] == pattern_str[j]) {
                    j++;
                    i++;
                }
                else {
                    break;
                }
            }
            /* 如果匹配到 */
            if ( j == len_pattern_str ) {
                count++;
            }
            /* 一个字符都没有匹配到 */
            if (j == 0) {
                i++;
            }
            /* 匹配部分字符或者匹配全部字符 */
            if (j > 0) {
                j = next[j-1];
            }
        }
        printf("%d\n", count);
    }
    return 0;
}

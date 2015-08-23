#include<stdio.h>
#include<string.h>
int cnt  = 0;

int grid(char *abc2, int len){
	int i, j, flag, tmp;
	tmp = len;
	// printf("%s[len]%d\n", abc2, len);
	
	for(i=0; i<len-1; i++){
		flag = 0;
		while(abc2[i+1] == abc2[i]){
			// printf("%s %d & %d字符相同\n", abc2, i, i+1);
			len--;
			cnt++;
			flag = 1; //表明abc2[i]后面紧邻的字符和abc2[i]相同
			for(j=i+1; j<len; j++){
				abc2[j] = abc2[j+1];
			}
			abc2[len] = '\0';
			// printf("%s\t[len]%d[cnt]%d\n", abc2, len, cnt);
		}
		if(flag){
			len--;
			cnt++;
			for(j=i; j<len; j++){
				abc2[j] = abc2[j+1];
			}
			abc2[len] = '\0';
			// printf("%s\t[len]%d[cnt]%d\n", abc2, len, cnt);
			i--;
		}
	}
	
	if(tmp > len && len > 1)
		grid(abc2, len);
	return cnt;
}

int main(void){
    int t, len, mcnt, i, j, k;
    char abc[101], abc2[102];
    
    scanf("%d", &t);
    while(t--){
        scanf("%s", abc);
        len = strlen(abc);
        mcnt = 0;
		for(i=0; i<=len; i++){
			for(j=0; j<3; j++){
				abc2[i] = 'A' + j;
				for(k=0; k<=i-1; k++)
					abc2[k] = abc[k];
				for(k=i+1; k<=len; k++)
					abc2[k] = abc[k-1];
				abc2[len+1] = '\0';
				
				cnt = 0;
				grid(abc2, len+1);
				// printf("[cnt]%d\n", grid(abc2, len+1));
				if(cnt > mcnt)
					mcnt = cnt;
			}
		}
        printf("%d\n", mcnt);
    }
    return 0;
}
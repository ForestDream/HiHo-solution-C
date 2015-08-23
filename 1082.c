#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[201];
    int len;
    int i;
    int j;
    
    
    while(gets(str) != NULL)
    {
        len = strlen(str);
        for (i=0; i<=len-9; i++)
        {
            if (str[i] == 'm'-'a'+97 || str[i] == 'M'-'A'+65)
            {
                if ((str[i+1] == 97 || str[i+1] == 65)
                    && (str[i+2] == 'r'-'a'+97 || str[i+2] == 'R'-'A'+65)
                    && (str[i+3] == 's'-'a'+97 || str[i+3] == 'S'-'A'+65)
                    && (str[i+4] == 'h'-'a'+97 || str[i+4] == 'H'-'A'+65)
                    && (str[i+5] == 't'-'a'+97 || str[i+5] == 'T'-'A'+65)
                    && (str[i+6] == 'o'-'a'+97 || str[i+6] == 'O'-'A'+65)
                    && (str[i+7] == 'm'-'a'+97 || str[i+7] == 'M'-'A'+65)
                    && (str[i+8] == 'p'-'a'+97 || str[i+8] == 'P'-'A'+65))
                    {
                        str[i] = 'f';
                        str[i+1] = 'j';
                        str[i+2] = 'x';
                        str[i+3] = 'm';
                        str[i+4] = 'l';
                        str[i+5] = 'h';
                        str[i+6] = 'x';
                    
                        for (j=i+7; j<=len-3; j++)
                        {
                            str[j] = str[j+2];
                        }
                        str[len-2] = '\0';
                        // printf("%s\n", str);
                    }
            }
        }
        printf("%s\n", str);
    }
    
    return 0;
}

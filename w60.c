/**************************************
* String Matching Content Length
**************************************/

#include<stdio.h>
#include<string.h>

char a[2101];
char b[2101];
int smcl;

int main(void)
{
    int ia, ib;
    int iia, iib;
    int len_a, len_b;
    int node_b;
    int len_sub;
    
    scanf("%s%s", a, b);
    len_a = strlen(a);
    len_b = strlen(b);
    
    smcl = 0;
    ia = 0;
    node_b = 0;
    
    while (ia<len_a-2)
    {
        len_sub = 0;
        ib = node_b;
        while (ib<len_b-2)
        {
            if (a[ia] == b[ib] && a[ia+1] == b[ib+1] && a[ia+2] == b[ib+2])
            {
                len_sub += 3;
                iia = ia + 3;
                iib = ib + 3;
                while (a[iia] == b[iib] && iia < len_a && iib < len_b)
                {
                    iia++;
                    iib++;
                    len_sub++;
                }
                // printf("[ia]%d [ib]%d Found %d\n", ia, ib, len_sub);
                ia += len_sub-1;
                ib += len_sub;
                node_b = ib;
                smcl += len_sub;
                break;
            }
            else
            {
                // printf("[ia]%d [ib]%d Not found\n", ia, ib);
                ib++;
            }
        }
        ia++;
    }
    printf("%d\n", smcl);
    return 0;
}

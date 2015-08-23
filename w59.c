/*
* HiHo week 59
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
typedef struct node * pnode;

struct node {
    char func_name[MAX];
    int ts[3];
    int te[3];
    pnode child;
    pnode next_bro;
    pnode father;
};

void dfs(pnode pos){
    int time[3];
    int i;
    
    for (i=2; i>=0; i--) {
        time[i] = pos->te[i] - pos->ts[i];
        if (time[i] < 0) {
            time[i] += 60;
            if (i>0) {
                pos->te[i-1]--;
            }
        }
    }
    printf("%s %02d:%02d:%02d\n", pos->func_name, time[0], time[1], time[2]);
    
    if (pos->child != NULL) {
        dfs(pos->child);
    }
    while (pos->next_bro != NULL) {
        dfs(pos->next_bro);
        pos = pos->next_bro;
    }
}

int main(){
    int n;
    pnode tree;
    pnode pos;
    pnode tmp;
    
    char func[MAX];
    int time[3];
    char flag[6];
    
    int i, j;
    
    scanf("%d", &n);
    
    tree = malloc(sizeof(struct node));
    tree->child = NULL;
    tree->next_bro = NULL;
    tree->father = NULL;
    pos = tree;
    
    for (i=0; i<n; i++) {
        scanf("%s %d:%d:%d %s", func, &time[0], &time[1], &time[2], flag);
        
        /* 对读入的log进行处理，即将该log插入树中 */
        /* 行最后是START，插入新节点，并保存开始时间 */
        if (flag[0] == 'S') {
            // printf("Start Line!\n");
            
            if (pos->child == NULL) {
                tmp = malloc(sizeof(struct node));
                strcpy(tmp->func_name, func);
                for (j=0; j<3; j++){
                    tmp->ts[j] = time[j];
                }
                tmp->child = NULL;
                tmp->next_bro = NULL;
                tmp->father = pos;
                
                pos->child = tmp;
                pos = tmp;
            }
            else {
                pos = pos->child;
                while (pos->next_bro != NULL) {
                    pos = pos->next_bro;
                }
                if (pos->next_bro == NULL) {
                    tmp = malloc(sizeof(struct node));
                    strcpy(tmp->func_name, func);
                    for (j=0; j<3; j++){
                        tmp->ts[j] = time[j];
                    }
                    
                    tmp->child = NULL;
                    tmp->next_bro = NULL;
                    tmp->father = pos->father;
                    
                    pos->next_bro = tmp;
                    pos = tmp;
                }
            }
            // printf("%s %02d:%02d:%02d S\n", pos->func_name, pos->ts[0], pos->ts[1], pos->ts[2]);
        }
        /* 行最后是END，结束时间存入相应的节点 */
        else {
            if (strcmp(pos->func_name, func) == 0) {
                for (j=0; j<3; j++){
                    pos->te[j] = time[j];
                }
                // printf("%s %02d:%02d:%02d E\n", pos->func_name, pos->te[0], pos->te[1], pos->te[2]);
                pos = pos->father;
            }
            else {
                printf("Incorrect performance log\n");
                break;
            }
        }
        
    }
    if (i == n) {
        if (tree->child != NULL) {
            dfs(tree->child);   
        }
    }
    return 0;
}

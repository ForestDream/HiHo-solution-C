
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node * ptr_node;
struct node {
    char ch;
    int weight;
    ptr_node child;
    ptr_node next_sibling;
};

int main() {
    int total;
    int query;
    char word[11];
    int len_word;
    ptr_node head;
    ptr_node position;
    ptr_node tmp_cell;
    int i;
    
    /* 建立空树 */
    head = malloc(sizeof(struct node));
    head->ch = '*';
    head->weight = 0;
    head->child = NULL;
    head->next_sibling = NULL;
    
    /* 将单词依次插入树中 */
    scanf("%d", &total);
    while (total--) {
        scanf("%s", word);
        len_word = strlen(word);
        
        position = head;
        for (i=0; i<len_word; i++) {
            if (position->child == NULL) {
                tmp_cell = malloc(sizeof(struct node));
                tmp_cell->ch = word[i];
                tmp_cell->weight = 1;
                tmp_cell->child = NULL;
                tmp_cell->next_sibling = NULL;
                
                position->child = tmp_cell;
                position = position->child;
            }
            else if (position->child->ch == word[i]) {
                position->child->weight++;
                position = position->child;
            }
            else {
                position = position->child;
                while (position->next_sibling != NULL && position->next_sibling->ch != word[i]) {
                    position = position->next_sibling;
                }
                if (position->next_sibling == NULL) {
                    tmp_cell = malloc(sizeof(struct node));
                    tmp_cell->ch = word[i];
                    tmp_cell->weight = 1;
                    tmp_cell->child = NULL;
                    tmp_cell->next_sibling = NULL;
                    
                    position->next_sibling = tmp_cell;
                    position = position->next_sibling; 
                }
                else if (position->next_sibling->ch == word[i]) {
                    position->next_sibling->weight++;
                    position = position->next_sibling;  
                }
            }
        }
    }
    
    /* 进行查询 */
    scanf("%d", &query);
    while (query--) {
        scanf("%s", word);
        len_word = strlen(word);
        
        position = head->child;
        for (i=0; i<len_word; i++) {
            if (position == NULL) {
                printf("0\n");
                break;
            }
            else if (position->ch == word[i]) {
                if (i<len_word-1) {
                    position = position->child;
                }
                else {
                    printf("%d\n", position->weight);
                }
            }
            else {
                while (position != NULL && position->ch != word[i]) {
                    position = position->next_sibling;
                }
                if (position == NULL) {
                    printf("0\n");
                    break;
                }
                if (position->ch == word[i]) {
                    if (i<len_word-1) {
                        
                        position = position->child;
                    }
                    else {
                        printf("%d\n", position->weight);
                    }
                }
            }
        }
    }
    return 0;
}

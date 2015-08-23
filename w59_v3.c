/*
* HiHo week 59 v3
* 用栈来模拟，栈用链表实现
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node;
typedef struct node * pnode;
typedef pnode stack;

int is_empty(stack s);
stack create(void);
void push(char * func, int * tm, stack s);
char * top(stack s);
void pop(stack s, int * time);
int time_cmp(int * a, int * b);
void set_time(char (* output)[256], int (* out)[3], int time_last, char * func);

struct node
{
    char func_name[256];
    int ts[3];
    pnode next;
};

int main()
{
    char func[256];
    int time[3];
    int old_time[3];
    char action[6];
    int n;
    int i, j;
    stack s;
    char (* output_list)[256];
    int (* output_time)[3];
    int index = 0;
    int time_last;
    int time_start[3];
    int flag = 1;

    scanf("%d", &n);
    s = create();
    output_list = malloc(n/2 * sizeof(char[256]));
    output_time = malloc(n/2 * sizeof(int[3]));
    
    if (n%2 != 0)
    {
        flag = 0;
    }
    else
    {
        for (i=0; i<n; i++)
        {
            scanf("%s %d:%d:%d %s", func, &time[0], &time[1], &time[2], action);
            /* 第一类错误： 当前log时间比上一条log时间早 */
            if(i>0 && time_cmp(time, old_time)<0)
            {
                flag = 0;
                break;
            }

            if (strcmp(action, "START") == 0)
            {
                push(func, time, s);
                strcpy(output_list[index++], func);
            }
            else
            {
                /* 第二类错误：END 数多于 START 数 及 第四类错误：函数出现交叉 */
                if(is_empty(s) || strcmp(top(s), func)!=0)
                {
                    flag = 0;
                    break;
                }

                /* 计算函数运行的时间并保存 */
                pop(s, time_start);
                //printf("%02d:%02d:%02d\n", time_start[0], time_start[1], time_start[2]);
                //printf("%02d:%02d:%02d\n", time[0], time[1], time[2]);
                time_last = time_cmp(time, time_start);
                /* 第三类错误：函数结束时间早于开始时间 */
                if (time_last < 0) {
                    flag = 0;
                    break;
                }
                //printf("%d\n", time_last);
                set_time(output_list, output_time, time_last, func);
                //printf("%d\n", time_last);
            }
            //printf("%s\n", top(s));
            for (j=0; j<3; j++)
            {
                old_time[j] = time[j];
            }
        }
        /* 第二类错误：START 数多于 END 数 */
        if (!is_empty(s))
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        printf("Incorrect performance log\n");
    }
    else
    {
        for (j=0; j<n/2; j++)
        {
            printf("%s %02d:%02d:%02d\n", output_list[j], output_time[j][0], output_time[j][1], output_time[j][2]);
        }
    }
    return 0;
}

int is_empty(stack s)
{
    return s->next == NULL;
}

stack create(void)
{
    stack s;

    s = malloc(sizeof(struct node));
    s->next == NULL;
    return s;
}

void push(char * func, int * tm, stack s)
{
    pnode tmp;
    int j;

    tmp = malloc(sizeof(struct node));
    strcpy(tmp->func_name, func);
    for (j=0; j<3; j++)
    {
        tmp->ts[j] = tm[j];
    }
    tmp->next = s->next;
    s->next = tmp;
}

char * top(stack s)
{
    if(!is_empty(s))
    {
        return s->next->func_name;
    }
    else
    {
        return "";
    }
}

void pop(stack s, int * time)
{
    pnode first;
    int j;

    if (!is_empty(s))
    {
        first = s->next;
        for (j=0; j<3; j++)
        {
            time[j] = first->ts[j];
        }
        //printf("%d %d %d\n", first, s->next, s->next->next);
        s->next = s->next->next;
        //printf("%d %d %d\n", first, s->next, s->next->next);
        free(first);
    }
}

int time_cmp(int * a, int * b)
{
    return (a[0]-b[0])*3600+(a[1]-b[1])*60+(a[2]-b[2]);
}

void set_time(char (* out_list)[256], int (* out_time)[3], int time_last, char * func)
{
    int i = 0;
    int j;
    int dvd = 3600;
    while (strcmp(out_list[i], func) != 0)
    {
        i++;
    }
    for (j=0; j<3; j++)
    {
        out_time[i][j] = time_last/dvd;
        time_last -= out_time[i][j]*dvd;
        dvd /= 60;
    }
    //printf("%02d:%02d:%02d\n", out_time[i][0], out_time[i][1], out_time[i][2]);
}

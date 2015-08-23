#include <stdio.h>
#include <string.h>

long long mod=1000000007;
long long base[20];
long long left, right, cross_sum;
long long digit[20], digit_num, digit_index;

typedef struct aaa node; 
struct aaa {  
    long long sum, num;  //sum代表数的和，num代表数的个数
};  

node dp[20][400];  //状态转移

/* 计算位数是pos，交叉和是target的所有数的和（模1000000007的余数） */
node dfs(long long pos, long long target, long long limit)  //limit 的意义作用
{  
    node t;
    t.sum = 0;
    t.num = 0;
    
    if (pos == 0)  //处理到最后一位，直接判断返回
    {               
        if (target == 100)
        {
            t.num = 1;
        }
        return t;  
    }
    
    /* 已经计算过的直接输出 */
    if (limit == 0 && dp[pos][target].num != -1) 
        return dp[pos][target];
    
    long long tail = limit?digit[pos]:9;
    long long sgn  = ((digit_index-pos)%2)?(-1):(1);  //确定符号  
    long long head;
    
    if (pos == digit_index)
    {
        head = 1;  
    }
    else 
    {
        head = 0;  //确定搜索的起点和终点  
    }
    
    int i;
    /* */
    for (i=head; i<=tail; i++)  
    {  
        node tmp = dfs(pos-1, target-i*sgn, (limit==1)&&(i==digit[pos]));
        
        if (tmp.num > 0)
        {
            t.num += tmp.num;  
            long long q;  
            q = ((((tmp.num % mod) * base[pos]) % mod) * i) % mod;  //结果的同余处理  
            t.sum += (tmp.sum)%mod;  
            t.sum %= mod;  
            t.sum += q;  
            t.sum %= mod;  //每一步都要同余  
        }  
    }  
    if (limit==0) dp[pos][target]=t;  
    return t;  
}

/* 函数cal 计算0~x之间，交叉和是y的所有数的和（模1000000007的余数） */
long long cal(long long x, long long y)  
{  
    long long ans = 0;
    if (x == -1) 
    {
        return 0;  
    }
    if (x == 0)
    { 
        return 0;  
    }

    digit_num = 0;
    while (x)
    {
        digit_num++;
        digit[digit_num] = x%10;
        x /= 10;
    }
    
    for (digit_index = 1; digit_index <= digit_num; digit_index++)
    {
        memset(dp, -1, sizeof(dp));
        ans += dfs(digit_index, y+100, digit_index==digit_num).sum;  //每次加上长度为digit_index交叉和为y的所有数
        ans = (ans + mod) % mod;  
    }
    return ans;  
}  

int main()  
{  
    int i;
    
    base[1] = 1;  
    for (i=2; i<=19; i++)  
    {
        base[i] = (base[i-1]*10) % mod;  
    }
    for (i=1; i<=19; i++)  
    {
        printf("%d\n", base[i]);
    }
    
    scanf("%lld%lld%lld", &left, &right, &cross_sum);
    {  
        printf("%lld\n", (cal(right, cross_sum) - cal(left-1, cross_sum) + mod) % mod);  
    }  
    return 0;  
}
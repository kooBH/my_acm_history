#include <stdio.h>
#include <time.h>


int max6(int,int,int,int,int,int);
int max3(int,int,int);
int main()
{
    int n,wine[10000];
    int score[10000][3]={{0,},{0,},{0,}}; // 1칸전 먹었을때 , 2칸전 먹었을때, 이번꺼 안 먹을 때
    int i;
    /*
     6
    1000 1000 1 1 1000 1000
     * */
    
   
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&wine[i]);
    
    score[0][0] = score[0][1] = wine[0];
    score[1][0] = score[0][1] + wine[1];
    score[1][1] = wine[1];
    score[1][2] = wine[0];
    for(i=2;i<n;i++)
    {
        score[i][0] = (score[i-1][1] > score[i-1][2] ? score[i-1][1] : score[i-1][2])  + wine[i];
        score[i][1] = max3(score[i-2][0],score[i-2][1],score[i-2][2]) + wine[i];
        score[i][2] = max3(score[i-1][0],score[i-1][1],score[i-1][2]);
    }    
    for(i=0;i<n;i++)
        printf("%d %d %d\n",score[i][0],score[i][1],score[i][2]);
    if(n==1)
        printf("%d",wine[0]);
    else
        printf("%d",max6(score[n-1][0],score[n-1][1],score[n-2][0],score[n-2][1],score[n-1][2],score[n-2][2]));
    
    scanf("%s");
    return 0;
}

int max6(int a,int b,int c,int d,int e,int f)
{
    a = (a>b?a:b);
    c = (c>d?c:d);
    e = (e>f?e:f);
    
    a = (a>c?a:c);
    return (a>e?a:e);
}

int max3(int a,int b,int c)
{
    a = a>b?a:b;
    return a>c?a:c;
}
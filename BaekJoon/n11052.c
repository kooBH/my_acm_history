#include <stdio.h>

int main(int argc, char **argv)
{
	int n,p[1001],dp[1001]={0,};
    int i,j;
    
    /*
    
     O(n^2) 문제 였음 O(n)으로 풀려고 했던것이 문제 
    * */
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d", &p[i]);
    
   
    dp[1] = p[1];
    printf("[%d] = %d\n",1,dp[1]);
    for(i=2;i<=n;i++)
    {
        dp[i] = p[i];
        for(j=1;j<=(i/2);j++)
        {
            dp[i] = dp[i] < dp[j] + dp[i-j] ? dp[j] + dp[i-j] : dp[i];
        }          
        
            
        printf("[%d] = %d\n",i,dp[i]);
    }
    printf("%d",dp[n]);
    
    scanf("%s");
    scanf("%s");
	return 0;
}

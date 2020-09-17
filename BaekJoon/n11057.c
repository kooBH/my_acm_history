#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int n,*dp[10],ans=0;;
    int i,j,k;
    scanf("%d",&n);
        
    for(i=0;i<10;i++)
        {
            dp[i] = (int*)malloc(sizeof(int)*(n));
            memset(dp[i],0,sizeof(int)*n);
        }
    
    for(i=0;i<10;i++)
        dp[i][0] = 1;
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<10;j++)
        {
            for(k=j;k<10;k++)
                dp[j][i+1] += dp[k][i];
            dp[j][i+1] = dp[j][i+1]%10007;
        }
    }
    
    for(j=0;j<10;j++)
    {
        for(i=0;i<n;i++)
            printf("%d ",dp[j][i]);
        printf("\n");
    }
    
    for(i=0;i<10;i++)
        ans += dp[i][n-1];
    
    ans %= 10007;
    
    printf("%d",ans);
    scanf("%s");
	return 0;
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int n;
    long long dp[100][10],ans=0;
    int i,j;
    
    dp[0][0]=0;
    for(i=1;i<10;i++)
        dp[0][i]=1;
        
    scanf("%d",&n);
    
    for(i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][1]%1000000000;
        for(j=1;j<9;j++)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
        dp[i][9]=dp[i-1][8]%1000000000;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%3lld ",dp[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<10;i++)
        ans+=dp[n-1][i];
    printf("%lld",ans%1000000000);
    scanf("%s");
    
	return 0;
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int n,a[1001],dp[1001]={0,};
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    for(j=1;j<=a[1];j++)
        {
            if(dp[1 + j] == 0 && 1 + j <=n)               
                  dp[1 + j] = dp[1] + 1;
        }
    
    for(i=2;i<=n;i++)
    {
        if(dp[i] != 0)
            for(j=1;j<=a[i];j++)
            {
                if(dp[i + j] == 0 && i + j <=n)               
                      dp[i + j] = dp[i] + 1;
            }
    }
    
    for(i=1;i<=n;i++)
        printf("%d ",dp[i]);
        
    if(n != 1 && dp[n] == 0)
        printf("-1");
    else if(n==1)
        printf("0");    
    else
        printf("%d",dp[n]);
    scanf("%s");
	return 0;
}

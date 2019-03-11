#include <stdio.h>

int main(int argc, char **argv)
{
    int n,dp[31]={0,};
    int i,j;
    
    scanf("%d",&n);
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    for(i=6;i<=n;i+=2)
        {
            dp[i] += 3*dp[i-2];
            for(j=0;j<=i-4;j+=2)
                dp[i]+=dp[j]*2;        
        }
    /*
     2 -> 3
     4 -> 9
     6 -> 41
     8  -> 153
     12 -> 2131
     * */
    printf("%d",dp[n]);
	return 0;
}

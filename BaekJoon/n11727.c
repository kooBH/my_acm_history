#include <stdio.h>

int main(int argc, char **argv)
{
	int n,dp[1001]={0,};
    
    scanf("%d",&n);
    
    dp[1] = 1;
    dp[2] = 3;
    for(int i =3; i<=n;i++)
        dp[i]= (dp[i-1] + 2*dp[i-2])%10007;
    printf("%d",dp[n]);
    
    scanf("%s");
	return 0;
}

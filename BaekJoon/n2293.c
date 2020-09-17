#include <stdio.h>

int main(int argc, char **argv)
{
	
    int n,k,c[101],dp[10001]={0,};
    int i,j;
    
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&c[i]);
/*
 for(int i=1;i<=n;i++){
   for(int j=0;j<=k;j++){
    if(A[i]<=j){
     dp[j]+= dp[j-A[i]];
    }
   }
  }
   * 
for(i=0; i<n; i++){
    dp[c[i]]++; // 시작하는 할 때 +1 입력해주는 방법
    for(j=c[i]+1; j<=k; j++) // c[i]+1부터
      dp[j] += dp[j-c[i]];
 * */
    for(i=0;i<n;i++ )// 동전
    {
        if(c[i]<= 10000)
            dp[c[i]]++;
        for(j=1;j<=k;j++)//금액 
        {
            if(c[i] <= j)
                dp[j] += dp[j-c[i]];
        }
    }
    
    for(i=1;i<=k;i++)
        printf("%d ",dp[i]);
    
    scanf("%s");
    
	return 0;
}

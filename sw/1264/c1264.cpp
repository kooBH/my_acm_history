#include <stdio.h>
#include <string.h>
#include <algorithm>

#define LEN 500

char x[LEN+1];
char y[LEN+1];
int dp[LEN+1][LEN+1];

int main(){
    int tc;

    int n;
    double ans;

    scanf("%d\n",&tc);
    for(int i=0;i<tc;i++){
        scanf("%d\n",&n);
        scanf("%s",x);
        scanf("%s",y);

        ans = 0;
        for(int j=0;j<n+1;j++)
            memset(dp[j],0,sizeof(int)*(LEN+1));

        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(x[j-1]==y[k-1]){
                    dp[j][k]=dp[j-1][k-1]+1;
                }else{
                    dp[j][k] = std::max(dp[j-1][k],dp[j][k-1]);
                }
            }
        }

        ans = (dp[n][n]/(double)n)*100;
        printf("#%d %.2lf\n",i+1,ans);
    }

    return 0;
}
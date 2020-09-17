#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647

void print_arr(int**,int,int);

int main(int argc, char **argv)
{
	int n,k,c[101],*dp[101];
    int min;
    int i,j,l;
    
    
    /*
     * 3 24
     * 1 7 10
     * -> 3
     * 
     * */
    
    scanf("%d%d",&n,&k);
    for(int i =1; i<=n;i++)
        scanf("%d",&c[i]);
    
    for(i=1;i<=n;i++)
        dp[i] = (int*)malloc(sizeof(int)*(k+1));
    
     for(i=1;i<=n;i++)
         for(j=1;j<=k;j++)
            dp[i][j] = -1;
    
   print_arr(dp,n,k);
    
    for(i=1;i<=n;i++)
    {        
        if(c[i]<=k)
            dp[i][c[i]]=1;
        
        for(j=c[i];j<=k;j++)
        {
            min = INT_MAX;
            
            for(l=1;l<=i;l++)
            {
                if(j-c[i] > 0 && (dp[l][j-c[i]]!= -1 &&  dp[l][j-c[i]] < min) )
                    {
                       // printf("min %d -> %d \n",min,dp[l][j-c[i]]);
                        min = dp[l][j-c[i]];
                    }
            }
            
            if(min != INT_MAX)
                dp[i][j] = min +1;
            //printf("--------------------------------\n");
           // print_arr(dp,n,k);
        }
    
    }
    
    print_arr(dp,n,k);
    
    min = INT_MAX;
    for(i=1;i<=n;i++)
    {
        if(dp[i][k] != -1 &&  min > dp[i][k])
            min = dp[i][k];
    }
    
    if(min == INT_MAX)
        min =  -1;
    
    printf("%d",min);
    scanf("%s");
	return 0;
}

void print_arr(int** dp,int n,int k)
{
    int i,j;
     for(i=1;i<=n;i++)
    {
         for(j=1;j<=k;j++)
         {
           printf("%d ",dp[i][j]);    
         }
        printf("\n");
    }
}
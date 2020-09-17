#include <stdio.h>
#include <stdlib.h>

int max2(int,int);
int max3(int,int,int);

int main(int argc, char **argv)
{
	int i,j;
    int n,m;
    int **map;
    
    scanf("%d%d",&n,&m);
    
    map = (int**)malloc(sizeof(int*)*n);
    
    for(i=0; i<n;i++)
        map[i] = (int*)malloc(sizeof(int)*m);
        
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&map[i][j]);
    
    for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
    
    printf("---------------------------------\n");
    
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            //천장 
            if(i==0)
            {
                if(j == 0)
                    continue;
                else 
                    map[i][j] += map[i][j-1];
            }           
            else 
            {
                if(j==0)
                    map[i][j] += map[i-1][j];
                else
                    map[i][j] +=max3(map[i-1][j],map[i-1][j-1],map[i][j-1]); 
           }
        }
        
      for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
    
    printf("%d",map[n-1][m-1]);
    scanf("%s");
    
	return 0;
}

int max2(int a,int b)
{
    return a> b ? a : b;
}
int max3(int a,int b,int c)
{
    a = a > b ? a : b;
    
    return c > a ? c : a;
}



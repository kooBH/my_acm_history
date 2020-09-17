#include <stdio.h>

int main(int argc, char **argv)
{
	int n,a[1000],s[1000]={0,},c=0;
    int i,j;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    /*
     6
10 20 10 30 20 50
     * */
    s[0] = a[0];
    for(i=1;i<n;i++)
    {
        if(a[i] < s[0])
            s[0] = a[i];
        for(j=1;j<=c;j++)
        {
            if(a[i] > s[j-1] && a[i] < s[j] )
                s[j] = a[i];
        }
        
        if(a[i] > s[c])
            s[++c] = a[i];
          
        printf("%d>>\n",a[i]);
        for(j=0;j<=c;j++)
            printf("%d : %d\n",j,s[j]);
            
    }
    
    printf("%d",c+1);
    scanf("%s");
	return 0;
}

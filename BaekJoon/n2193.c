#include <stdio.h>

int main(int argc, char **argv)
{
    int n,i;
    long long a[90];
    a[0]=1;
    a[1]=1;
    scanf("%d",&n);
    for(i=2;i<n;i++)
        a[i]=a[i-2]+a[i-1];
        
    printf("%lld",a[n-1]);    
    scanf("%s");
	return 0;
}

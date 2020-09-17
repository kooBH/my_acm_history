#include <stdio.h>

int main(int argc, char **argv)
{
    int n,a[10],input;
    int i,j;
    
    scanf("%d",&n);
    a[0]=1;
    a[1]=2;
    a[2]=4;
    for(i=3;i<10;i++)
        a[i]=a[i-3]+a[i-2]+a[i-1];
    for(i=0;i<n;i++)
    {
        scanf("%d",&input);
        printf("%d\n",a[input-1]);
        }
        scanf("%s");
	return 0;
}

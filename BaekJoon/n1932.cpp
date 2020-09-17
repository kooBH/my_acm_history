#include <stdio.h>
int main(int argc, char **argv)
{
/*
         7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 숫자 삼각형의 한 모습이다.
 * 

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
 * 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 숫자는 모두 정수이며, 범위는 0 이상 99 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1≤n≤500)이 주어지고, 둘째 줄부터 n+1줄까지 숫자 삼각형이 주어진다.

출력
첫째 줄에는 최대가 되는 합을 출력한다.

예제 입력  복사
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
예제 출력  복사
30
*/

int size,max=0;
int tri[500]={0,};
int l,r,temp;
int i,j;

scanf("%d",&size);

scanf("%d",&temp);

tri[0]=temp;
printf("0  : %d\n",tri[0]);
for(i=1;i<size;i++)
{
    /*
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
 * 
 *      7
 *    10 15
 *   18 16 15
 * 20 25 20 19
  4  5  2  6  5
  24 30 27 26 24
     * 
     *  
     * */
    scanf("%d",&temp);
    
    l=tri[0];    
    printf("tri[0](%d) += %d\n",tri[0],temp);
    tri[0]+=temp;
    if(i>1)
        r=tri[1];
    
   for(j=1;j<i;j++)
   {
    scanf("%d",&temp);
    //printf("input : %d %d\n",temp,tri[0]);
    if(l>r)
        {
            tri[j]=l+temp;
            printf("tri[%d]=%d+%d\n",j,l,temp);
        
        }
    else
        {tri[j]=r+temp;
            printf("tri[%d]=%d+%d\n",j,r,temp);
        }
    l=r;
    r=tri[j+1];   
   }
    
    scanf("%d",&temp);
    printf("tri[%d](%d)=%d+%d;\n",j,tri[0],temp,l);
    tri[j]=temp+l;
     
    //Debugging
    printf("%-2d : ",i);
    for(j=0;j<size;j++)
    {
       printf("%d ",tri[j]);
    }
    printf("\n");
}

for(i=0;i<size;i++)
{
    if(tri[i]>max)
        max = tri[i];
}
printf("%d",max);
	return 0;
}

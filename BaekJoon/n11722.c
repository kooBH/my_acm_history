#include <stdio.h>
/*
가장 긴 감소하는 부분 수열 풀이
문제집 
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	3366	2165	1850	66.715%
문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.
z`
입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.

예제 입력  복사
6
10 30 10 20 20 10
예제 출력  복사
3
힌트
출처
문제를 만든 사람: baekjoon
알고리즘 분류
보기 
 * */
int main(int argc, char **argv)
{
    
    int num, arr[1001],ans[1001]={0,},max=0;
    int i,j,k;
    
    scanf("%d",&num);
	
    for(i=0;i<num;i++)
        scanf("%d",&arr[i]);
    
    //가장 긴- 이 포인트 
    for (i=0;i<num;i++)
    {
            
    }
    
    
    
    for(i=0;i<num;i++)
    {
            if(ans[i] > max)
                max = ans[i];
    }
    
    printf("%d",max);
    
    return 0;
}
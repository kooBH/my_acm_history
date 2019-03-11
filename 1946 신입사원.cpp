#include <stdio.h>
#include <algorithm>
#include <vector>
#define f(_i,_n) for(_i=0;_i<_n;_i++)
#pragma warning(disable:4996)

using namespace std;
/*
문제
언제나 최고만을 지향하는 굴지의 대기업 진영 주식회사가 신규 사원 채용을 실시한다. 인재 선발 시험은 1차
서류심사와 2차 면접시험으로 이루어진다. 최고만을 지향한다는 기업의 이념에 따라 그들은 최고의 인재들만을 
사원으로 선발하고 싶어 한다.

그래서 진영 주식회사는, 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른
지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 
비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.

이러한 조건을 만족시키면서, 진영 주식회사가 이번 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 
구하는 프로그램을 작성하시오.

입력
첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)가 주어진다. 각 테스트 케이스의 첫째 줄에 
지원자의 숫자 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 각각의 지원자의 서류심사 성적, 
면접 성적의 순위가 공백을 사이에 두고 한 줄에 주어진다. 두 성적 순위는 모두 1위부터 N위까지 동석차 없이 결정된다고 가정한다.

출력
각 테스트 케이스에 대해서 진영 주식회사가 선발할 수 있는 신입사원의 최대 인원수를 한 줄에 하나씩 출력한다.
*/
typedef struct {
  int a;
  int b;

}c;

void quickSort(c arr[], int left, int right);
int main() {
  int T, N;
  int i,j;
  int ans;
  c p[100001];
  int b_top;
  scanf("%d", &T);
  //p = new c[N];
  while(T--) {
    scanf("%d",&N);
    ans = N;
    f(i, N) {
      scanf("%d%d",&p[i].a,&p[i].b);
    }  
    quickSort(p, 0, N - 1);
    b_top = N;
    for (i = 0; i < N;i++) {
      if (p[i].b > b_top) {
        ans--;
      }
      if (p[i].b < b_top)b_top = p[i].b;
      /*
       자기보다 서류 점수가 높은 친구들 중에
       자기보다 면접점수도 높은 친구가 있다면 탈락이다
       그래서 서류등수를 내려가면서 그 등수까지의
       면접킹의 등수만 비교하면 될것이다.
       */
    }
  printf("%d\n",ans);
  }
  return 0;
}
void quickSort(c arr[], int left, int right) {
  int i = left, j = right;
  int pivot = arr[(left + right) / 2].a;
  int temp;
  do
  {
    while (arr[i].a < pivot)
      i++;
    while (arr[j].a > pivot)
      j--;
    if (i <= j)
    {
      temp = arr[i].a;
      arr[i].a = arr[j].a;
      arr[j].a = temp;
      temp = arr[i].b;
      arr[i].b = arr[j].b;
      arr[j].b = temp;
      i++;
      j--;
    }
  } while (i <= j);

  /* recursion */
  if (left < j)
    quickSort(arr, left, j);

  if (i < right)
    quickSort(arr, i, right);
}
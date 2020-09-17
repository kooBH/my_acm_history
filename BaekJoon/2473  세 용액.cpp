#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#define ull unsigned long long
#define ll long long
#define f(_i,_n) for(_i=0;_i<_n;_i++)
using namespace std;
#pragma warning(disable:4996)

int main() {
/*
  3 fluid -> can be bigger than 2*10^9
  dealing with long
*/
  ll *data;
  int N,l,r,i;
  ll ans[3];
  ll t1,min;
  scanf("%d",&N);
  data = new ll[N];
  f(i, N)scanf("%lld",&data[i]);
  sort(data, data + N);

  ans[0] = 0;
  ans[1] = 1;
  ans[2] = 2;
  min = abs(data[0] + data[1] + data[2]);
  for (i = 0; i < N - 2; ++i) {
    l = i + 1;
    r = N - 1;
    //현재 i 에서의 최적값을 저장하기 위한 변수
    while (l < r) {
      t1 = data[l] + data[r] + data[i];

      if (abs(t1) < min){
        min = abs(t1);
        ans[0] = i;
        ans[1] = l;
        ans[2] = r;
      }
      //지역적으로 r,l로 0에 근사하려 접근함
      //근사한 정도는 계속 변화하기 때문에 현재 i에서의 최적값을
      //x,y에 저장해야함
      if (t1> 0)--r;
      else if (t1 == 0) { i = N; break; }
      else ++l;
    }
  }
  printf("%lld %lld %lld",data[ans[0]],data[ans[1]],data[ans[2]]);

  return 0;
}
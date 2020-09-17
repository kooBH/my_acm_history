#include <stdio.h>
#include <algorithm>
#define ull unsigned long long
#define f(_i,_n) for(_i=0;_i<_n;_i++)

#pragma warning(disable:4996)
/*
? https://www.geeksforgeeks.org/window-sliding-technique/
*/
int main() {
  int N, *data;
  int i, j;
  int sum, pre, post;
  scanf("%d",&N);
  data = new int[N];

  f(i, N) scanf("%d", &data[i]);
  std::sort(data, data + N, 
    [](int a, int b) {
    return abs(a) < abs(b);
    }
  );

  f(i, N)printf("%d ",data[i]);
  printf("\n");
  sum = INT_MAX;
  f(i, (N - 1)) {
    if (abs(data[i] + data[i + 1]) < sum) {
      sum = abs(data[i] + data[i + 1]);
      pre = i;
      post = i + 1;
    }
  }
  pre = data[pre];
  post = data[post];
  if(post > pre)
    printf("%d %d", pre, post);
  else
    printf("%d %d", post, pre);

  return 0;
}
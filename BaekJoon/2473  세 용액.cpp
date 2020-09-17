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
    //���� i ������ �������� �����ϱ� ���� ����
    while (l < r) {
      t1 = data[l] + data[r] + data[i];

      if (abs(t1) < min){
        min = abs(t1);
        ans[0] = i;
        ans[1] = l;
        ans[2] = r;
      }
      //���������� r,l�� 0�� �ٻ��Ϸ� ������
      //�ٻ��� ������ ��� ��ȭ�ϱ� ������ ���� i������ ��������
      //x,y�� �����ؾ���
      if (t1> 0)--r;
      else if (t1 == 0) { i = N; break; }
      else ++l;
    }
  }
  printf("%lld %lld %lld",data[ans[0]],data[ans[1]],data[ans[2]]);

  return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#define f(_i,_n) for(_i=0;_i<_n;_i++)
#pragma warning(disable:4996)

using namespace std;
/*
����
������ �ְ��� �����ϴ� ������ ���� ���� �ֽ�ȸ�簡 �ű� ��� ä���� �ǽ��Ѵ�. ���� ���� ������ 1��
�����ɻ�� 2�� ������������ �̷������. �ְ��� �����Ѵٴ� ����� �̳信 ���� �׵��� �ְ��� ����鸸�� 
������� �����ϰ� �;� �Ѵ�.

�׷��� ���� �ֽ�ȸ���, �ٸ� ��� �����ڿ� ������ �� �����ɻ� ������ �������� ���� �� ��� �ϳ��� �ٸ�
�����ں��� �������� �ʴ� �ڸ� �����Ѵٴ� ��Ģ�� ������. ��, � ������ A�� ������ �ٸ� � ������ B�� ������ 
���� ���� �ɻ� ����� ���� ������ ��� �������ٸ� A�� ���� ���ߵ��� �ʴ´�.

�̷��� ������ ������Ű�鼭, ���� �ֽ�ȸ�簡 �̹� �ű� ��� ä�뿡�� ������ �� �ִ� ���Ի���� �ִ� �ο����� 
���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �׽�Ʈ ���̽��� ���� T(1 �� T �� 20)�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ� 
�������� ���� N(1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N�� �ٿ��� ������ �������� �����ɻ� ����, 
���� ������ ������ ������ ���̿� �ΰ� �� �ٿ� �־�����. �� ���� ������ ��� 1������ N������ ������ ���� �����ȴٰ� �����Ѵ�.

���
�� �׽�Ʈ ���̽��� ���ؼ� ���� �ֽ�ȸ�簡 ������ �� �ִ� ���Ի���� �ִ� �ο����� �� �ٿ� �ϳ��� ����Ѵ�.
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
       �ڱ⺸�� ���� ������ ���� ģ���� �߿�
       �ڱ⺸�� ���������� ���� ģ���� �ִٸ� Ż���̴�
       �׷��� ��������� �������鼭 �� ���������
       ����ŷ�� ����� ���ϸ� �ɰ��̴�.
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
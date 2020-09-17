#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ull unsigned long long
#define f(_i,_n) for(_i=0;_i<_n;_i++)

//����� ����
#pragma warning(disable:4996)

int main() {
  
  int N, *arr,*data;
  int i, j;
  int cur,max;
  scanf("%d", &N);

  arr = new int[N];
  
  data = new int[N];
  memset(data, 0, sizeof(int)*N);
  for (i = 0; i < N; i++) {
    scanf("%d",&arr[i]);
  }
  cur = 0;
  max = 0;
  data[0] = arr[0];
  // Algorithm block
  for (i = 1; i < N; i++) {
    for (j = 0; j < i; j++) {
      /*
       data[j] �� ���� j+1�� ������� ������ ������ ���� ����
       �ϰ� ��������� -�� ����
       arr[i]�� data[0]~data[j]�� ��ü�� �� �ִ� �� �����ϴ°�? �� �˰���
      */
      //���
      if (data[j] > 0 && arr[i] > data[j] && (data[j+1]==0)|( arr[i] < data[j+1]) ) {
        data[j + 1] = arr[i];
      }
      //�ϰ�
      else if(data[j] < 0 && arr[i] < -data[j] && (data[j+1]==0)|(arr[i] > -data[j+1])){
        data[j + 1] = -(arr[i]);
      }
      //��� -> �ϰ�
      else if (data[j]>0 && arr[i] < data[j] && (data[j+1]==0)) {
        data[j + 1] = -(arr[i]);
      }
      //������ ����
      else if(data[j]==0){
        break;
      }

    }
  }

  for (i = 0; i < N; i++)
    printf("%3d ",arr[i]);
  printf("\n");
  for (i = 0; i < N; i++)
    printf("%3d ", data[i]);
  printf("\n");


  return 0;
}
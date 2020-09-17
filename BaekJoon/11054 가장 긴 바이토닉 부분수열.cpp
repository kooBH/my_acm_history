#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ull unsigned long long
#define f(_i,_n) for(_i=0;_i<_n;_i++)

//제출시 제거
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
       data[j] 는 길이 j+1의 바이토닉 수열의 마지막 숫자 포함
       하강 시퀸스라면 -를 붙임
       arr[i]로 data[0]~data[j]중 교체할 수 있는 게 존재하는가? 의 알고리즘
      */
      //상승
      if (data[j] > 0 && arr[i] > data[j] && (data[j+1]==0)|( arr[i] < data[j+1]) ) {
        data[j + 1] = arr[i];
      }
      //하강
      else if(data[j] < 0 && arr[i] < -data[j] && (data[j+1]==0)|(arr[i] > -data[j+1])){
        data[j + 1] = -(arr[i]);
      }
      //상승 -> 하강
      else if (data[j]>0 && arr[i] < data[j] && (data[j+1]==0)) {
        data[j + 1] = -(arr[i]);
      }
      //미지의 영역
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
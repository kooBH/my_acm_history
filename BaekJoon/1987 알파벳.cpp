#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long
#define f(_n) for(auto _i=0;_i<_n;_i++)

#pragma warning(disable:4996)
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0 ,1 };

/*
�ð� ����	�޸� ����	����	����	���� ���	���� ����
2 ��	128 MB	17714	6046	3700	31.787%
����
���� Rĭ, ���� Cĭ���� �� ǥ ����� ���尡 �ִ�. ������ �� ĭ���� �빮�� ���ĺ��� �ϳ��� ���� �ְ�, ���� ��� ĭ (1�� 1��) ���� ���� ���� �ִ�.

���� �����¿�� ������ �� ĭ ���� �� ĭ���� �̵��� �� �ִµ�, ���� �̵��� ĭ�� ���� �ִ� ���ĺ��� ���ݱ��� ������ ��� ĭ�� ���� �ִ� ���ĺ�����
�޶�� �Ѵ�. ��, ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.

���� ��ܿ��� �����ؼ�, ���� �ִ��� �� ĭ�� ���� �� �ִ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ������ ĭ�� ���� ����� ĭ�� ���Եȴ�.

�Է�
ù° �ٿ� R�� C�� ��ĭ�� ���̿� �ΰ� �־�����. (1<=R,C<=20) ��° �ٺ��� R���� �ٿ� ���ļ� ���忡 ���� �ִ� C���� �빮�� ���ĺ�����
��ĭ ���� �־�����.

���
ù° �ٿ� ���� ���� �� �ִ� �ִ��� ĭ ���� ����Ѵ�.

���� �Է� 1
2 4
CAAB
ADCB
���� ��� 1
3
*/

#define AA 65 //ASCII 'A'
bool alpha[26];
bool path[20][20];
char map[20][20];
int step(int,int);
int ans;
int max;
int R, C;

int main() {
  int i = 0;
  while (true) {
  
    i++;
    if (i > 1000)
      i = 0;
  }
  /*
  scanf("%d%d",&R,&C);
  ans = 0;
  max = 0;
  getchar();
  for (auto i = 0; i < R; i++){
    for (auto j = 0; j < C; j++)
        scanf("%c", &map[i][j]);
    getchar();
  }

  for (auto i = 0; i < R; i++) {
    for (auto j = 0; j < C; j++)
      printf("%c ",map[i][j]);
    printf("\n");
  }
  step(0, 0);
  printf("%d",max);
  */
  return 0;
}
//take a step on map[x][y]
int step(int x,int y) {
  int nx, ny;
  printf("cur : %d %d\n", x, y);
    //�̿��� ���ĺ�
  if (alpha[map[y][x] - AA])return 0;
  if (path[y][x])return 0;

  alpha[map[y][x]-AA] = true;
  path[y][x] = true;
  ans++;

 
  f(26) {
    printf("%c|%d ", AA + _i, alpha[_i]);
  }
  printf("\n");
  for (auto i = 0; i < R; i++) {
    for (auto j = 0; j < C; j++)
      printf("%d ", path[i][j]);
    printf("\n");
  }

  if (ans > max)max = ans;

  f(4) {
    nx = x + dx[_i];
    ny = y + dy[_i];

    if (nx < 0 || nx == C || ny < 0 || ny == R)continue;

    if (!step(nx, ny)) {
      
    }

  }
  ans--;
  alpha[map[y][x] - AA] = false;
  path[y][x] = false;
  
  return 0;
}
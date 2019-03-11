#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long
#define f(_n) for(auto _i=0;_i<_n;_i++)

#pragma warning(disable:4996)
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0 ,1 };

/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	17714	6046	3700	31.787%
문제
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는
달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1<=R,C<=20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이
빈칸 없이 주어진다.

출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.

예제 입력 1
2 4
CAAB
ADCB
예제 출력 1
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
    //이용한 알파벳
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
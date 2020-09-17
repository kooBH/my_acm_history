#include <iostream>
#include <stdlib.h>
#include <algorithm>
using std::cin;
using std::cout;
/*
문제
n*n의 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 
그리고 그 곳의 대나무를 다 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동을 한다. 그리고 또 그곳에서 대나무를 먹는다. 
그런데 단 조건이 있다. 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 
많이 있어야 한다. 만약에 그런 지점이 없으면 이 판다는 불만을 가지고 단식 투쟁을 하다가 죽게 된다(-_-)

이 판다의 사육사는 이런 판다를 대나무 숲에 풀어 놓아야 하는데, 어떤 지점에 처음에 풀어 놓아야 하고, 어떤 곳으로 
이동을 시켜야 둘 다 소중한 생명이지만 판다가 최대한 오래 살 수 있는지 고민에 빠져 있다. 우리의 임무는 이 사육사를
도와주는 것이다. n*n 크기의 대나무 숲이 주어져 있을 때, 이 판다가 최대한 오래 살려면 어떤 경로를 통하여 움직여야 하는지 구하여라.

입력
첫째 줄에 대나무 숲의 크기 n(1 ≤ n ≤ 500)이 주어진다. 그리고 둘째 줄부터 n+1번째 줄까지 대나무 숲의 정보가 주어진다.
대나무 숲의 정보는 공백을 사이로 두고 각 지역의 대나무의 양이 정수 값으로 주어진다. 대나무의 양은 1,000,000보다 작거나
같은 자연수이다.

출력
첫째 줄에는 판다가 최대한 살 수 있는 일수(K)를 출력한다.
*/

int N;
int map[501][501];
int dp[501][501];
int dx[4] = { -1,0,1,0 };
int dy[4] = {0,-1,0 ,1};

int dfs(int x,int y) {
  int i, j, k;
  int nx, ny;

  if (dp[y][x]) return dp[y][x];
  dp[y][x] = 1;

  for (i = 0; i < 4; i++) {
    nx = x + dx[i];
    ny = y + dy[i];

    if (nx < 0 || nx == N || ny < 0 || ny == N)continue;

      if(map[ny][nx] > map[y][x]){
        dp[y][x] = std::max(dp[y][x], dfs(nx,ny) + 1);
      }
    

  }
  return dp[y][x];
}

int main() {
  int i, j;
  int x, y;
  int ans=1;
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
 
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      cin >> map[i][j];


  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
        ans = std::max(dfs(j, i),ans);


  cout << ans;
  return 0;
}
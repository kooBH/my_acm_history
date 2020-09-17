#include <iostream>

#define tt unsigned long long
#define max_path 9223372036854775807
using std::cin;
using std::cout;
/*
N×N 게임판에 수가 적혀져 있다. 이 게임의 목표는 가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 점프를 해서 가는 것이다.

각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다. 반드시 오른쪽이나 아래쪽으로만 이동해야 한다. 
0은 더 이상 진행을 막는 종착점이며, 항상 현재 칸에 적혀있는 수만큼 오른쪽이나 아래로 가야 한다. 한 번 점프를 할 때, 
방향을 바꾸면 안된다. 즉, 한 칸에서 오른쪽으로 점프를 하거나, 아래로 점프를 하는 두 경우만 존재한다.

가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 규칙에 맞게 이동할 수 있는 경로의 개수를 구하는 프로그램을 작성하시오.

가장 왼쪽 위 칸에서 가장 오른쪽 아래 칸으로 문제의 규칙에 맞게 갈 수 있는 경로의 개수를 출력한다. 
경로의 개수는 2^63-1보다 작거나 같다.
*/

int main() {
  tt **map, **dp;
  tt N;
  tt i, j,cur;
  cin >> N;

  map = new tt*[N];
  for (i = 0; i < N; i++)map[i] = new tt[N];

  dp = new tt*[N];
  for (i = 0; i < N; i++)dp[i] = new tt[N];


  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      cin >> map[i][j];

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      dp[i][j] = 0;
  dp[0][0] = 1;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++){
      cur = map[i][j];
      if (cur == 0)continue;
      /* 아래로 */
      if (i + cur < N)dp[i + cur][j] += dp[i][j];
     /* 오른쪽으로 */
      if (j + cur < N)dp[i][j+cur] += dp[i][j];
    }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)cout << dp[i][j] << " ";
    cout << "\n";
  }

  cout << dp[N - 1][N - 1];
  return 0;
}
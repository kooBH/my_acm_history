
#include <iostream>
#include <list>
#pragma warning(disable:4996)
using std::cin;
using std::cout;
using std::list;

typedef struct { int x, y; }xy;
int dfs(int**map, int **dp, int x, int y);

int M, N;



int dfs(int**map, int **dp, int x, int y) {
  cout << x << " " << y<<"\n";
  if (y == M - 1 && x == N - 1) {
    return 1;
  }
  if (dp[y][x] != -1) {
    return dp[y][x];
  }
  dp[y][x] = 0;

  if (x != 0 && (map[y][x-1] < map[y][x])) {
    dp[y][x] += dfs(map, dp, x-1, y);
  }
  if (x != N-1 && (map[y][x+1] < map[y][x])) {
    dp[y][x] += dfs(map, dp, x+1, y);
  }
  if (y != 0 && (map[y-1][x] < map[y][x])) {
    dp[y][x] += dfs(map, dp, x, y-1);
  }
  if (y != M-1 && (map[y+1][x] < map[y][x])) {
    dp[y][x] += dfs(map, dp, x, y+1);
  }
  /*
  for (int i = 0; i < 4; i++) {
    int nx = dx[i] + x;
    int ny = dy[i] + y;

    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
      if (map[y][x] > map[nx][ny]) {
        dp[y][x] += dfs(nx, ny);
      }
    }
  }
  */
  return dp[y][x];
}

int main()
{
  int i, j;
  int **map;
  int **dp;
  list<xy> bfs;
  xy cur;

  cin >> M >> N;

  map = new int*[M];
  for (i = 0; i < M; i++)map[i] = new int[N];

  dp = new int*[M];
  for (i = 0; i < M; i++)dp[i] = new int[N];

  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++)
      scanf("%d", &map[i][j]);

  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++)
      dp[i][j] = -1;

  dfs(map, dp, 0, 0);
  /*
  bfs.push_back(xy{ 0, 0 });

  while (bfs.size() > 0) {
    cur = bfs.back();
    bfs.pop_back();
    cout << "cur : " << cur.x << " " << cur.y << "\n";
    if (!dp[cur.y][cur.x])
    {
      continue;
    }

    if (cur.x == N - 1 && cur.y == M - 1)
    {
      dp[M - 1][N - 1] = 1;
      continue;
    }

    if (dp[cur.y][cur.x] != -1) 
      continue;

    dp[cur.y][cur.x] = 0;

    if (cur.x != 0) {
      if (map[cur.y][cur.x - 1] < map[cur.y][cur.x]){
        bfs.push_back(xy{ cur.x - 1,cur.y });
        dp[cur.y][cur.x]++;
    }
    }

    if (cur.x != N - 1) {
      if (map[cur.y][cur.x + 1] < map[cur.y][cur.x]){
        bfs.push_back(xy{ cur.x + 1,cur.y });
      dp[cur.y][cur.x]++;
    }
    }

    if (cur.y != 0) {
      if (map[cur.y - 1][cur.x] < map[cur.y][cur.x]) {
      bfs.push_back(xy{ cur.x,cur.y - 1 });
      dp[cur.y][cur.x]++;
    }
    }

    if (cur.y != M - 1) {
      if (map[cur.y + 1][cur.x] < map[cur.y][cur.x]) {
      bfs.push_back(xy{ cur.x,cur.y + 1 });
      dp[cur.y][cur.x]++;
    }
    }

  }
  */
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++)
      cout << dp[i][j] << " ";
    cout << "\n";
    }

  cout << dp[0][0];

  return 0;
}

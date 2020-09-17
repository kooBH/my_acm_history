#include <iostream>

using std::cin;
using std::cout;

/*
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.

덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.
첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

중복조합 ? 

N,K -> (n+1)H(k-1) : 0~N 개니까 n+1, k-1개를 맘껏 고르고 모자라는 걸 하나 더하면 되니까 k-1
(n+1)H(k-1) = (k + n -1)C( k -1)
*/
int main() {
  int N, K;
  /* K N*/
  int i, j;
  unsigned long long**dp;
  cin >> N >> K;
  
  N = K + N - 1;
  K = K - 1;
  if (K == 0) {
    cout << 1;
    return 0;
  }
  dp = new  unsigned long long*[K + 1];
  for (i = 0; i < K + 1; i++)dp[i] = new  unsigned long long[N + 1];

  for (i = 0; i <= N; i++)dp[0][i] = 1;
  for (i = 1; i <= N; i++)dp[1][i] = i;
  for (i = 1; i <= K; i++)dp[i][i] = 1;

  for (i = 2; i <= K; i++) {
    for (j = i + 1; j <= N; j++)
      dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % 1000000000;
  }

  for (i = 0; i <= K; i++) {
    for (j = 0; j < i; j++)cout << " |";
    for (j = i; j <= N; j++)cout << dp[i][j] << "|";
    cout << "\n";
  }

  cout << dp[K][N];

  return 0;
}
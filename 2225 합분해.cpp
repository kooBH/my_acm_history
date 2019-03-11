#include <iostream>

using std::cin;
using std::cout;

/*
0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

������ ������ �ٲ� ���� �ٸ� ���� ����(1+2�� 2+1�� ���� �ٸ� ���). ���� �� ���� ���� ���� �� �� ���� �ִ�.
ù° �ٿ� ���� 1,000,000,000���� ���� �������� ����Ѵ�.

ù° �ٿ� �� ���� N(1 �� N �� 200), K(1 �� K �� 200)�� �־�����.

�ߺ����� ? 

N,K -> (n+1)H(k-1) : 0~N ���ϱ� n+1, k-1���� ���� ���� ���ڶ�� �� �ϳ� ���ϸ� �Ǵϱ� k-1
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
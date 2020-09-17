#include <iostream>

using std::cin;
using std::cout;

 /* �ڿ��� �� ���� �� �־����� �� ���� ��� �� 10, 007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
   nCk = n!/k!(n-k)!

   Pascal's rule
   (n+1)C(k+1) = nCk + nC(k+1)
 
 */

int main() {
  int N, K;
  /* K N*/
  int i, j;
  unsigned long long**dp;
  cin >> N >> K;

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
      dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) %10007 ;
  }

  for (i = 0; i <= K; i++) {
    for (j = 0; j < i; j++)cout << " |";
    for (j = i ; j <= N; j++)cout << dp[i][j] << "|";
    cout << "\n";
  }

  cout << dp[K][N];

  return 0;
}
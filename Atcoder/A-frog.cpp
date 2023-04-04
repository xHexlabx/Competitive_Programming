#include <bits/stdc++.h>
using namespace std;

const int N = 100007;
int n, h[N], dp[N];

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &h[i]);
    dp[i] = INT_MAX;
  }
  dp[0] = 0;
  for(int i=0; i<n; i++) {
    dp[i+1] = min(dp[i+1], dp[i]+abs(h[i]-h[i+1]));
    dp[i+2] = min(dp[i+2], dp[i]+abs(h[i]-h[i+2]));
  }
  printf("%d", dp[n-1]);
  return 0;
}
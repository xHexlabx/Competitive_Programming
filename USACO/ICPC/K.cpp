#include <bits/stdc++.h>
#define LL long long
const int kM = 30;
const int kN = 1e6 + 10;

int n, q;
std::string s;
LL cnt[kM][kM], sum;

namespace Trie {

  const int kNode = kN << 3;

  int nodenum = 1, tr[kNode][30], sz[kNode];

  void Insert() {

    int now = 1;
    
    for (int i = 0, len = s.length(); i < len; ++ i) {
      int ch = s[i] - 'a';
      if (!tr[now][ch]) tr[now][ch] = ++ nodenum;
 
      for (int j = 0; j < 26; ++ j) {
        if (j == ch) continue;
        cnt[ch][j] += sz[tr[now][j]];
      }
 
      now = tr[now][ch];
      ++ sz[now];
    }
    for (int j = 0; j < 26; ++ j) {
      sum += sz[tr[now][j]];
    }
  }
}

int main() {

  std::ios::sync_with_stdio(0), std::cin.tie(0);

  std::cin >> n >> q;

  for (int i = 1; i <= n; ++ i) {
    std::cin >> s;
    Trie::Insert();
  }

  while (q --) {

    std::string t; std::cin >> t;
    LL ans = 0;
    for (int i = 0; i < 26; ++ i) {
      for (int j = i + 1; j < 26; ++ j) {
        ans += cnt[t[i] - 'a'][t[j] - 'a'];
      }
    }
    std::cout << ans + sum << "\n";
  }

  return 0;
}
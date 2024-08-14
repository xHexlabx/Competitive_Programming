By:Luckyblock

*/

#include <bits/stdc++.h>

#define LL long long

//=============================================================

int n;

LL m, sum;

//=============================================================

LL exgcd(LL a_, LL b_, LL &x_, LL &y_) {

  if (!b_) {

    x_ = 1, y_ = 0;

    return a_;

  }

  LL d_ = exgcd(b_, a_ % b_, y_, x_);

  y_ -= a_ / b_ * x_;

  return d_;

}

//=============================================================

int main() {

  //freopen("1.txt", "r", stdin);

  std::ios::sync_with_stdio(0), std::cin.tie(0);

  std::cin >> n >> m;

  for (int i = 1; i <= n; ++ i) {

    int a; std::cin >> a;

    sum = (sum + a) % m;

  }

 

  LL x1, y1;

  LL d1 = exgcd(n, 1ll * n * (n + 1) / 2ll, x1, y1);

  x1 = (x1 % m + m) % m, y1 = (y1 % m + m) % m;

 

  LL x2, y2;

  LL d2 = exgcd(d1, m, x2, y2);

  x2 = (x2 % m + m) % m;

 

  LL k = -sum / d2;

  x1 = (x1 * k % m * x2 % m + m) % m;

  y1 = (y1 * k % m * x2 % m + m) % m;

  std::cout << sum + k * d2 << "\n" << x1 << " " << y1 << "\n";

  return 0;

}
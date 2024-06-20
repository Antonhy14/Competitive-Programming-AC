#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (auto i = (l); i < (r); i++)
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define pb push_back

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using ld = long double;
using lli = long long;
using ii = pair<int, int>;

const int N = 2005;

struct item {
  int weight;
  int cost;
};

int dp[N];
item items[N];
int mx;
int n;

template <class T>
void umax(T& a, T b) {
  a = max(a, b);
}

void knapsack01() {
  fore (i, 0, n) {
    item& cur = items[i];
    for (int weight = mx; weight >= cur.weight; weight--) {
      umax(dp[weight], dp[weight - cur.weight] + cur.cost);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> mx >> n;
  fore (i, 0, n)
    cin >> items[i].weight >> items[i].cost;
  fill_n(dp, mx + 1, 0);
  knapsack01();
  cout << dp[mx] << '\n';
  return 0;
}

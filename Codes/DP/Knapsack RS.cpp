// AC = AntonhyCoder
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define cnl cout << '\n'
#define nl '\n'
#define sp(x,n) fixed << setprecision(x) << n
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define len(x) int(x.length())
#define fore(i,l,r) for(auto i=l;i<r;i++)
#define pb push_back
#define pf push_front
#define lsb(x) (x & -x)

using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pair<int, int>>;
using ii = pair<int, int>;
/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/
// 1LL *: convierte el siguiente numero a long long int
const int N = 1e5 + 5;
const int INF = 1e9;

int v[2*N];
int t[2*N];

pair<int, vi> knapsack(int smax, int n) {
    vector<vi> dp(n+1, vi(smax+1, -INF));
    fore(i,0,smax+1) dp[0][i] = 0;

    fore(i, 1, n+1) {
        for(int s = smax; s >= 0; --s) {
            if(s >= t[i-1]) {
                dp[i][s] = max(dp[i-1][s], dp[i-1][s - t[i-1]] + v[i-1]);
            }
            else dp[i][s] = dp[i-1][s];
        }
    }

    vi items;
    int s = smax;
    for(int i = n; i>0 && s>0; --i) {
        if(dp[i][s] != dp[i-1][s]) {
            items.pb(i-1);
            s-= t[i-1];
        }
    }

    return {dp[n][smax], items};
}


int main(){
    cin.tie(0) -> sync_with_stdio(0), cout.tie(0);

    int smax, n;
    cin >> smax >> n;

    fore(i,0,n) cin >> t[i] >> v[i];

    auto[res, items] = knapsack(smax, n);
    cout << res << nl;
    for(auto& x: items) cout << x << " ";

    cout << '\n';    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define nl cout<<"\n"
#define sp(x,n) fixed<<setprecision(x) << n
#define all(x) x.begin(),x.end()
#define fore(i,l,r) for(auto i=l;i<r;i++)
#define pb push_back
#define pf push_front
/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/
int a,b,c,n;
vector<ll> nums(n+1);

ll fun(ll n) {
  if(nums[n]!=0) return nums[n];
  
  if(n==3) return c;
  else if(n==2) return b;
  else if(n<=1) return a;

  nums[n] = fun(n-1) + fun(n-2) + fun(n-3);

  return nums[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> a >> b >> c;
  vector<ll> v = {a,b,c}, prefix(n+1);

  int q;
  // cin >> q;
  fun(n);

  for(auto x: nums) cout << x<< " ";

  cout << "\n";

	return 0;
}

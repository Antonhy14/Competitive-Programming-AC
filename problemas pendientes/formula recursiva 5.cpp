#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define nl cout<<"\n"
#define sp(x,n) fixed<<setprecision(x) << n
#define all(x) x.begin(),x.end()
#define fore(i,l,r) for(int i=l;i<r;i++)
#define pb push_back
#define pf push_front
/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/
ll f5(ll n, ll m) {
    if(n==1) return -1*f5(n-2,m);
    else if(n>3) return 2 +f5(n-1,m);
    else if(n==2) return 2*m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,m;
    cin >> n >> m;
    ll res = f5(n,m);
    cout << res;
    
    return 0;
}
// https://omegaup.com/arena/problem/Formula-Recursiva-Cinco/

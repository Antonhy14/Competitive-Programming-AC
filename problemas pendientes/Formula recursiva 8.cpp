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
ull f8(ull n) {
    if(n<4) return 10;
    return f8(n-2) + f8(n-4) + 30;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ull n;
    cin >> n;
    ull res = f8(n);
    cout << res;
    
    return 0;
}

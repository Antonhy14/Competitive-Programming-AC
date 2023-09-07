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
ull f4(ull n){
    if(n<=3) return 1;
    return f4(n-1) + f4(n-2) + f4(n-3); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ull n;
    cin >> n;
    ull res = f4(n);
    cout << res;
    
    return 0;
}
// https://omegaup.com/arena/problem/Formula-Recursiva-Cuatro/

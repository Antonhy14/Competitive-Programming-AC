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
ull resX[100000]={};
ull resA[100000]={};
ull crazyFunc(ull x, ull a) {
    // cout << x << " " << a << endl;
    if(resX[x]!=0) return resX[x];
    else if(resA[a]!=0) return resA[a];
    else if(x==0) return 2*a;
    else if(a==0) return (x+1)/2;
    return crazyFunc(x/2,a) + crazyFunc(x,a/2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ull x,a;
    cin >> x >> a;
    ull r = crazyFunc(x,a);
    cout << r;
    
    return 0;
}
// https://omegaup.com/arena/problem/La-funcion-loca/

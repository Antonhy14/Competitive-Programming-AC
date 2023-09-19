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
bool orden(string a, string b) {
    if(a[0]>=65&&b[0]<=90) a[0]+=32;
    if(a[0]>=65&&b[0]<=90) b[0]+=32;
    return a<b;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> v;
    
    fore(i,0,n) {
        string str;
        cin >> str;
        v.pb(str);
    }
    
    sort(all(v),orden);
    for(auto x:v) cout << x << endl;
    if(v[0]<v[1]) cout << v[0];
    else cout << v[1];
    
    return 0;
}

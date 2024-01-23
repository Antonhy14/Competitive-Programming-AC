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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, p;
    cin >> n >> p;
    
    vector<int> in[n+1], out[n+1];
    set<int> s;
    
    fore(i,0,p) {
        int l,r,c;
        cin >> l >> r >> c;
        
        in[l].pb(c);
        in[r].pb(c);
        
        s.insert(c);
    }
    
    multiset<int> ms;
    fore(i,1,n+1) {
        for(auto pi:in[i]) ms.insert(pi);
        
        for(auto x: s) {
            int mayor =0;
            if(ms.count(x)) mayor = ms.count(x);
            cout << mayor << " ";
        }
        
        for(auto pi:out[i]) ms.erase(ms.find(pi));
    }

    cout << "\n";
    
    return 0;
}

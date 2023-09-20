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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int cad,pref;
    cin >> cad >> pref;
    vector<string> v;
    vector<vector<int>> res;
    
    fore(i,0,cad) {
        string str;
        cin >> str;
        v.pb(str);
    }
    
    fore(i,0,pref) {
        string str;
        cin >> str;
        vector<int> aux;
        for(auto x:v) {
            string aux = x.substr(0,str.length());
            if(str==x) aux.pb(i+1);
        }
        res.pb(aux);
    }
    for(auto x:v) {
        cout << x.size() << " ";
        if(x.size()<=10) for(auto y:x) cout << y << " ";
        else fore(i,0,10) cout << x[i] << " ";
    }
    
    return 0;
}
// Sin entregas
// https://omegaup.com/arena/problem/Busqueda-de-cadenas-por-prefijos/

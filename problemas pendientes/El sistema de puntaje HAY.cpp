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
    
    map<string,int> dicc;
    int n,m;
    cin >> n >> m;
    
    fore(i,0,n) {
        string str;
        int aux;
        cin >> str >> aux;
        dicc[str] = aux;
    }
    fore(i,0,m) {
        string str,strVal="";
        ull res=0;
        while(getline(cin,str)) {
            if(str==".") break;
            strVal+= ' ' + str;
        }
        for(auto x: dicc) {
            string strVal2 = strVal;
            while(strVal2.find(x.first)!=string::npos) {
                res+=x.second;
                //auto it = strVal2.find(x.first)+x.first.length();
                strVal2.erase(0, strVal2.find(x.first)+x.first.length());
                // cout << strVal << endl << endl;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}
// https://omegaup.com/arena/problem/puntaje-hay/

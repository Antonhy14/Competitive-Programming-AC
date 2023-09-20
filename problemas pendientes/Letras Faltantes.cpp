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
    
    int l1,l2;
    while(cin >> l1 >> l2) {
        string str,str2;
        cin >> str >> str2;
        string aux=str,aux2=str2;
        sort(all(aux));
        sort(all(aux2));
        auto it = aux2.find(aux);
        if(it==string::npos) cout << "no entiendo\n";
        else {
            fore(i,0,str2.length()) {
                if(str.empty()) break;
                fore(j,0,str.length()) {
                    if(str2[i]==str[j]) {
                        str.erase(str.begin()+j);
                        str2.erase(str2.begin()+i);
                        i--;
                    }
                    else break;
                }
            }
            cout << str2 << endl;
        }
    }
    
    return 0;
}
// WA 0
// https://omegaup.com/arena/problem/LetrasFaltantes/

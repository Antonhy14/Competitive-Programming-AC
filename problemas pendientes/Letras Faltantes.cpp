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
        sort(all(str));
        sort(all(str2));
        auto it = str2.find(str);
        if(it==string::npos) cout << "no entiendo\n";
        else {
            str2.erase(it,str.length());
            cout << str2 << endl;
        }
    }
    
    return 0;
}
//https://omegaup.com/arena/problem/LetrasFaltantes/

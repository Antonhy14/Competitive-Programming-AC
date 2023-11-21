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
bool isPali(string str) {
    if(str.length()<=1) return 1;
    if(str.front()==str.back()) {
        str.erase(0, 1);
        str.erase(str.length()-1, 1);

        return isPali(str);
    }
    return 0;
}
vector<string> substrs(string str) {
    vector<string> res;
    for (int len = 1; len <= str.length(); len++) {
        for (int i = 0; i <= str.length() - len; i++) {
            string aux;
            for (int j = i; j < i + len; j++) {
                aux+= str[j];
            }   
            if(isPali(aux)) res.pb(aux);
        }
    }
    return res;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	

    string str;
    cin >> str;

    vector<string> res = substrs(str);

    for(auto x: res) cout << x << endl;

    cout << "\n";

	return 0;
}

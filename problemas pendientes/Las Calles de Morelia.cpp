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
int cont(vector<string>& v, int x) {
  string aux = v.front();
  aux = aux.substr(aux.length()-x, x);

  for(auto str:v) {
    str= str.substr(str.length()-x, x);
    if(aux!=str) return 0;
  }
  return 1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, fracc=0, lomas=0, calle=0;
  cin >> n;
  cin.ignore();
  vector<string> v;

  for(int i=0; i<n; ++i) {
    string str;
    getline(cin, str);

    if(str[0]=='C' || str[0]=='c') calle++;
    else if(str[0]=='F' || str[0]=='f') fracc++;
    else if(str[0]=='L' || str[0]=='l') lomas++;

    string aux = str.substr(str.length()-3, 3);
    v.push_back(aux);
  }  

  int c = cont(v, 1);
  c+= cont(v,2);
  c+= cont(v,3);

  cout << c << endl << "Lomas: " << lomas << endl << "Calle: " << calle << endl << "Fracc: " << fracc;

  cout << "\n";

  return 0;
}

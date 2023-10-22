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
int findShortestSubstr(string& str) {
	int l=0, r=0, resp=str.length(), one=0, two=0, three=0,ok=0;
	
  while(l<str.length()) {
		if(one>0 && two>0 && three>0) {
			if(l==0 && r==2) resp=3;
			else if(r-l<resp) resp=r-l;
			ok=1;
      
			if(str[l]==49) one--;
			else if(str[l]==50) two--;
			else if(str[l]==51) three--;
		  l++;
		}
      
		else if(one==0 || two==0 || three==0) {
			if(r+1<=str.length()) {
				if(str[r]==49) one++;
				else if(str[r]==50) two++;
				else if(str[r]==51) three++;
				r++;
			}
        
			else {
				if(str[l]==49) one--;
				else if(str[l]==50) two--;
				else if(str[l]==51) three--;
				l++;
			}
    }
	}
  
	if(resp==str.length() && ok==0) return 0;
	return resp;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin >> n;
    vector<string> v;

    fore(i,0,n) {
    	string aux;
    	cin >> aux;
    	v.pb(aux);
	}

	for(auto x:v) {
		int resp = findShortestSubstr(x);
		cout << resp << endl;
	}

    return 0;
}
// https://codeforces.com/problemset/problem/1354/B ||Accept
// Two Pointer :D

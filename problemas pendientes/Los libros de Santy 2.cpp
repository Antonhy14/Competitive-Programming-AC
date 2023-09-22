#include<iostream>
#include<algorithm>
using namespace std;
#define ull unsigned long long
#define ll long long int
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
ull binarySearch(ll x, ll (&v)[], int size) {
	int l=0,r=size-1,guess;
	while(0==0) {
		guess= (l+r)/2;
		
		if(x==v[guess]) return guess;
		else if(x>v[guess]) l=guess+1;
		else if(x<v[guess]) r=guess-1;
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q;
	cin >> n >> q;
	ll nums[n];
	
	fore(i,0,n)	cin >> nums[i];
	
	sort(nums,nums+n); 
	
	fore(i,0,q) {
		ll aux;
		cin >> aux;
		ll res = binarySearch(aux,nums,n);
		cout << res << " ";
	}
    
    return 0;
}
// TLE 13%
// https://omegaup.com/arena/problem/Los-libros-de-Santy-2/

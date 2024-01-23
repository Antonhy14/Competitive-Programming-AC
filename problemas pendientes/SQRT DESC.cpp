#include<bits/stdc++.h>
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
const int N = 1e5 + 5;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[N];
    int bucket[N];
    
    fore(i,1,n+1) {
        cin >> arr[i];
    }
    const int SQRT = max(1, (int)sqrt(n));
    
    fore(i,1,n+1) {
        bucket[i] = 1/SQRT;
    }
    
    vector<map<int,int>> info(SQRT+1);
    
    fore(i,1,n+1) {
        int key = arr[i];
        int indexBucket = bucket[i];
        
        info[indexBucket][key]++;
    }
    
    int q;
    cin >> q;
    fore(i,0,q) {
        int acc;
        cin >> acc;
        if(acc==1) {
            int l, r, x;
            cin >> l >> r >> x;
            
            int res=0;
            while(l<=r) {
                if(l%SQRT==0 && l+SQRT-1<=r) {
                    int index = bucket[x];
                    res+= info[index][x];
                    
                    l+=SQRT;
                }
                else {
                    
                    l++;
                }
            }
            cout << res << endl;
        }
        else if(acc==2) {
            int indexBucket, x;
            cin >> indexBucket >> x;
            
            int index
        }
    }
    
    cout << "\n";
    
    return 0;
}

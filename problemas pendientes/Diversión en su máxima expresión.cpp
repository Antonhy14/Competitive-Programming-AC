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
const int N = 1e5+5;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[N];
    int bucket[N];
    
    fore(i,1,n+1) cin >> arr[i];
    
    const int SQRT = max(1, (int)sqrt(n));
    
    fore(i,1,n+1) {
        bucket[i] = i / SQRT;
    }
    

    vector<map<int,int>> info(n/SQRT+1);
    
    fore(i,1,n+1) {
        int key = arr[i];
        int index = bucket[i];
        
        info[index][key]++;
    }
    
    int q;
    cin >> q;
    vector<int> ans;
    
    fore(i,0,q) {
        int acc;
        cin >> acc;
        
        if(acc==1) {
            int l, r;
            cin >> l >> r;
            
            if(l>r) swap(l,r);
            
            // Reordenar el arreglo
            for(int j=r; j>l; j--) {
                info[bucket[j]][arr[j]]--;
                info[bucket[j-1]][arr[j-1]]--;
                
                swap(arr[j], arr[j-1]);
                info[bucket[j]][arr[j]]++;
                info[bucket[j-1]][arr[j-1]]++;
            }
            
        }
        else if(acc==2) {
            int l, r, x;
            cin >> l >> r >> x;
            
            if(l>r) swap(l,r);
            
            int res=0;
            while(l<=r) {
                if(l%SQRT==0 && l+SQRT-1<=r) {
                    int index = bucket[l];
                    res+= info[index][x];
                    l+= SQRT;
                }
                else {
                    if(arr[l]==x) {
                        res++;
                    }
                    l++;
                }
            }
            ans.pb(res);
        }
    }
    for(auto x:ans) cout << x << endl;
    
    cout << "\n";
    
    return 0;
}

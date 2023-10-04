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
bool DFS(vector<vector<int>>& grafo, int nodeAct, deque<int>& camino, vector<bool>& visited) {
    visited[nodeAct] = true;
    camino.pb(nodeAct);
    
    for (auto x: grafo[nodeAct]) {
        if (!visited[x]) {
            if(DFS(grafo, x, camino, visited)) return 1;
        }
        else if(x==camino.front()) {
            camino.pb(x);
            return 1;
        }
    }
    camino.pop_back();
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,c;
    cin >> n >> c;
    vector<vector<int>> grafo(n);
    vector<int> res;
    
    fore(i,0,c) {
        int x,y;
        cin >> x >> y;
        grafo[x].pb(y);
    }
    fore(i,0,n) {
        vector<bool> visited(n+1);
        deque<int> camino;
        
        if(DFS(grafo, i, camino, visited)); res.pb(i);
        // nl;
    }
    // nl;
    for(auto x:res) cout << x << " ";
    
    return 0;
}

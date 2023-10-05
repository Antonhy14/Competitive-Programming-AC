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
void dfs(vector<vector<vector<int>>>& grafo, int node, int dest, vector<bool>& visited, stack<int>& path, vector<stack<int>>& paths) {
	visited[node]=true;
	path.push(node);
    if(node==dest) {
        paths.pb(path);
        visited[node]=false;
        path.pop();
    }
	
	fore(i,1,grafo[node].size()) {
		if(grafo[node][i].empty()) continue;
		if(!visited[i]) {
			dfs(grafo,i,dest,visited,path,paths);
		}
	}
	path.pop();
}
vector<int> analizePath(vector<vector<vector<int>>>& grafo, int node, int dest) {
	vector<int> res;
	
	
	stack<int> path;
	vector<stack<int>> paths;
	vector<bool> visited(grafo[node].size());
	dfs(grafo,node,dest,visited,path,paths);

    for(auto& pth: paths) {   
	    map<int,int> x;
    	int c=0;
    	while(!pth.empty()) {
    		int aux = pth.top();
    		pth.pop();
    		
    		if(pth.empty()) break;
    		else {
    		    for(auto prod:grafo[aux][pth.top()]) {
    				if(x.find(prod)==x.end()) x[prod]=1;
    				else x[prod]++;
    		    }
    		}
    		c++;
    	}
        for(auto cont:x) {
    		if(cont.second==c) res.pb(cont.first);
    	}
    }

	return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<vector<vector<int>>> grafo(n+1,vector<vector<int>>(n+1));
    
    fore(i,0,m) {
    	int x,y,z;
    	cin >> x >> y >> z;
    	grafo[x][y].pb(z);
    	grafo[y][x].pb(z);
	}
	
	int q;
	cin >> q;
	vector<vector<int>> res;
	
	fore(i,0,q) {
		int x,y;
		cin >> x >> y;
		vector<int> aux;
		
		if(!grafo[x][y].empty()) {
			for(auto z:grafo[x][y]) aux.pb(z);
		}
		else {
			aux=analizePath(grafo,x,y);
		}
		
		res.pb(aux);
	}
	
	for(auto& aux:res) {
		if(aux.empty()) cout << "*";
		else for(auto z: aux) cout << z << " ";
		
		nl;
	}
	
    return 0;
}

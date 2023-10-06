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
class Graph{
	private:
		int V;
		vector<vector<vector<int>>> matAd;
	public:
		Graph (int v) :V(v) {
			matAd.resize(V,vector<vector<int>>(V));
		}
		void addEdge(int x, int y, int z) {
			matAd[x][y].pb(z);
			matAd[y][x].pb(z);
		}
		void dfs(int node, int dest, vector<bool>& visited, stack<int>& path, vector<stack<int>>& paths) {
			visited[node] = true;
			path.push(node);
			
			if(node==dest) paths.pb(path);
			
			fore(i,1,V) {
				if(matAd[node][i].empty()) continue;
				if(!visited[i]) {
					dfs(i, dest, visited, path, paths);
				}
			}
			
			visited[node] = false;
			path.pop();
		}
		void showRes(set<int>& results) {
			if(results.empty()) cout << "*";
			else for(auto& x :results) cout << x << " ";
			nl;
		}
		void calcPath(int src, int dest) {
			vector<bool> visited(V);
			vector<stack<int>> paths;
			stack<int> path;
			
			dfs(src, dest, visited, path, paths);
			set<int> res;
			
			for(auto& pth: paths) {
				map<int,int> prods;
				int c=0;
				
				while(!pth.empty()) {
					int aux = pth.top();
					pth.pop();
					
					if(pth.empty()) break;
					else {
						for(auto x : matAd[aux][pth.top()]) {
							if(prods.find(x)==prods.end()) prods[x]=1;
							else prods[x]++;
						}
					}
					c++;
				}
				
				for(auto& p:prods) {
					if(p.second==c) res.insert(p.first);
				}
			}
			showRes(res);
		}
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	Graph graph(n+1);
	
	fore(i,0,m) {
		int x,y,z;
		cin >> x >> y >> z;
		graph.addEdge(x,y,z);	
	}
	
	int q;
	cin >> q;
	
	fore(i,0,q) {
		int x,y;
		cin >> x >> y;
		graph.calcPath(x,y);
	}
	
	
	return 0;
}
// RTE 15%
// https://omegaup.com/arena/problem/Exportaciones-ITLAC22/
// Cambios en la estructura y la comprobación de los productos.

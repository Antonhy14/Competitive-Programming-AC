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
// Funcion que hara el ordenamiento topologico
vector<int> topologySort(vector<vector<int>>& graph, vector<int>& inDegree) {
	vector<int> res; // Almacena el resultado del orden de ejecucion de la tareas
	priority_queue<int, vector<int>, greater<int>> qu; // En este caso, se ocupa que la tareas se realizan en basa a su dependencia y numero

	// Empezamos con los nodos que no tienen ninguna dependencia externa, no proviene de ningun lado
	fore(node,0,graph.size()) {
		if(inDegree[node]==0) qu.push(node);
	}

	while(!qu.empty()) {
		// Tomamos el siguiente en la fila de espera
		int curr = qu.top();
		qu.pop();

		// Agregamos este al resultado y seguimos a reducir el grado de entrada de sus dependientes
		res.pb(curr+1);

		for(auto subNode:graph[curr]) {
			inDegree[subNode]--; // Quitamos una dependencia del nodo
			if(inDegree[subNode]==0) qu.push(subNode); // Si ya no tiene ninguna dependencia, entonces lo agregamos a la fila de espera
		}
	}
	return res; // Regresamos el resultado de nuestro ordenmiento
}
int main() {
  ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,c;
	cin >> n >> c;
	vector<vector<int>> graph(n);
	vector<int> inDegree(n, 0);

	fore(i,0,c) {
		int x,y;
		cin >> x >> y;
		graph[x-1].pb(y-1);
		inDegree[y-1]++; // Cada que se agrega una entrada a un nodo y se incrementa su grado de entrada
	}

	vector<int> res = topologySort(graph, inDegree);

	// Validamos que se hayan usado todos los nodos, en caso de que no es porque se encontro un ciclo, asi que, no se pudo hacer TopoSort
	if(res.size()==n) for(auto x: res) cout << x << " ";
	else cout << "Sandro fails";

	return 0;
}
// https://www.spoj.com/problems/TOPOSORT/

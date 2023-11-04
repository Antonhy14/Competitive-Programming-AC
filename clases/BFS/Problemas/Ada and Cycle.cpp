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
// Representacion de cada nodo, numero y distancia hasta a el
struct Edge {
	int node, dist;
};
// BFS para encontrar el ciclo mas corto
int BFS(vector<vector<int>>& matrix, Edge start) {
	// Registro de los nodos visitados
	vector<bool> visited(matrix.size(), 0);
	// Lista de espera
	queue<Edge> qu;

	// Inicia recorrido
	qu.push(start);

	while(!qu.empty()) {
		// Tomamos el siguiente de la lista de espera
		Edge curr = qu.front();
		qu.pop();

		// Vemos los vecinos del nodo actual
		for(auto subNode: matrix[curr.node]) {
			if(!visited[subNode]) { // Si no se ha visitado...
				visited[subNode] = 1; // Lo marcamos como visitado
				qu.push({subNode, curr.dist+1}); // Lo agregamos a la fila de espera y aumentamos la distancia actual en 1

				if(subNode==start.node) return curr.dist+1; // Si regresamos al inicio, entonces encontramos el ciclo mas corto
			}
		}
	}
	return 0; // Si no encontramos algun ciclo, 0 como valor de referencia
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> matrix(n);
	fore(i,0,n) {
		fore(j,0,n) {
			int aux;
			cin >> aux;
			if(aux) matrix[i].pb(j); // Si hay alguna conexion
		}
	}

	fore(i,0,n) {
		int res = BFS(matrix, {i,0});
		if(res) cout << res << endl; // Si es mayor de 0...
		else cout << "NO WAY\n"; // Si es 0...
	}

  return 0;
}
// https://www.spoj.com/problems/ADACYCLE/

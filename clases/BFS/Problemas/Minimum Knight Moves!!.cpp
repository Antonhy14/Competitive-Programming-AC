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
// Representación de cada casilla, su posición y la distancia que toma llegar ahí.
struct BoardBox{
	int x, y , distance;
};

// Todos los movimiento posibles del caballo, en forma (x,y)
vector<pair<int,int>> movs = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};

// Función para validar que el movimiento este en el tablero
bool valid(int x, int y) {
	return x>=0&&x<8 && y>=0&&y<8;
}	

// BFS para encontrar el camino más corto
int BFS(pair<int,int> start, pair<int,int> end) {
	vector<vector<int>> visited(8, vector<int>(8,0)); // Guardar si la casilla ya fue visitada
  queue<BoardBox> qu; // Cola de espera

	qu.push({start.first, start.second, 0}); // Iniciar el recorrido

	while(!qu.empty()) {
		BoardBox current = qu.front(); // Tomamos la siguient casilla pendiente a visitar
		qu.pop();

		if(current.x==end.first && current.y==end.second) return current.distance; // Comprabamos si no hemos llegado ya

		fore(i,0,8) {
			// Preparamos exploración de una casilla
			int newX = current.x + movs[i].first;
			int newY = current.y + movs[i].second;

			if(valid(newX, newY) && !visited[newX][newY]) { // Si es posible ir...
				visited[newX][newY] = 1; // La marcamos como visitada
				qu.push({newX,newY, current.distance + 1}); // La dejamos en lista de espera y aumentamos en 1 la distancia recorrida
			}
		}
	}
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

	int n;
	cin >> n;
	vector<int> res;

	fore(i,0,n) {
		// Recibimos las posiciones de inicio y fin
		char x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;

		pair<int,int> start = {x1-97,y1-49};
		pair<int,int> end = {x2-97,y2-49};

		res.pb(BFS(start, end)); // Guardamos los resultados
	}
	for(auto x: res) cout << x << endl; // Mostramos resultados.

  return 0;
}
// https://www.spoj.com/problems/NAKANJ/

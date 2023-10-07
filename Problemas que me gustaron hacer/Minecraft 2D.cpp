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
bool valid(int x, int y, int r, int c) { // Funcion para comprobar si el lugar a donde voy esta en rango
	if(x>=0 && x<r && y>=0 && y<c) return 1;
	return 0;
}
vector<string> mov={"ARRIBA","ABAJO","IZQUIERDA","DERECHA"}; // vector de movimientos hechos
int mX[] = {-1,1,0,0}; 
int mY[] = {0,0,-1,1};
// arreglos con los movimiento que se pueden hacer.

void bfs(vector<vector<char>>& lab, pair<int,int> start, pair<int,int> end, stack<string>& movs) {
	int rows = lab.size();
	int columns = lab[0].size();
	vector<vector<bool>> visited(rows,vector<bool>(columns)); // aqui cada nodo es un elemento de la matriz
	queue<pair<int,int>> qu; // cola para hacer la bfs
	vector<vector<pair<int,int>>> nodeParent(rows,vector<pair<int,int>>(columns)); // vector que guarda de donde viene cada nodo
	
	qu.push(start);
	visited[start.first][start.second] = 1;
	
	while(!qu.empty()) {
		pair<int,int> current = qu.front();
		qu.pop();
		
		fore(i,0,4) {
			int newX = current.first+ mX[i]; //*op1
			int newY = current.second+ mY[i]; //*op1
			// intentar avanzar a un nodo proximo
			
			if(valid(newX,newY,rows,columns)) {
				if(lab[newX][newY]!='#' && !visited[newX][newY]) { // en este caso '#' representa una pared(no conexion) asi que si se encuentra pues no se recorre vea
					qu.push({newX,newY});
					visited[newX][newY]=1;
					nodeParent[newX][newY] = current; // esto se actualiza en cada exploracion asi que al final queda puesto el nodo correcto
					
					if(newX==end.first && newY==end.second) { // si ya llegamos toca rehacer el camino
						pair<int,int> curr = end; // empezamos desde el fin y con un stack, asi indicaremos los pasos a seguir de inicio a fin
						while(curr!=start) {
							fore(j,0,4) {
								// hacer la operacion contraria(op1) para ver que movimiento se hizo
								if(curr.first-mX[j]==nodeParent[curr.first][curr.second].first && curr.second-mY[j]==nodeParent[curr.first][curr.second].second) {
									movs.push(mov[j]);
									break;
									// se agrega a la lista y finaliza
								}
							}
							curr=nodeParent[curr.first][curr.second];
							// ve de que nodo venia
						}
						return;
					}
				}
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<char>> lab(n,vector<char>(n));
    pair<int,int> start,end;
    
    fore(i,0,n) {
    	fore(j,0,n) {
	    	cin>> lab[i][j];
	    	if(lab[i][j]=='X') start = {i,j}; // encontrar donde esta Steve
	    	else if(lab[i][j]=='H') end = {i,j}; // encontrar donde esta su casa
		}
	}
    
    stack<string> movs;
    bfs(lab,start,end,movs);
    
    while(!movs.empty()) {
    	cout << movs.top() << endl;
    	movs.pop();
	}
	
    return 0;
}
/*
	#: pared
	.: espacio libre
	X: posicion de Steve
	H: su casa
*/
// AC
// https://omegaup.com/arena/problem/Minecraft-2D/

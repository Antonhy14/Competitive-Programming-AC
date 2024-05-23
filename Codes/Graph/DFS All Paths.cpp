const int N = 1e5 + 5;

vi graph[N]; // Grafo
bool visited[N]; // lista de vistidos
vector<stack<int>> paths; // lista de todos lo caminos posible
stack<int> path; // el camino que se lleva

// DFS para saber todos los caminos posibles entre dos nodos.
void DFS(int u, int t) {
    visited[u] = true; // para el camino actual lo marcamos como visitado
    path.push(u); // lo agregamos a la ruta actual
    // si ya llega al objetivo
    if(u==t) 
        paths.pb(path); // agregamos el camino actual a lista de caminos
  
    // exploramos para el camino actual los vecinos disponibles
    for (auto v: graph[u]) {
        // y si podemos
        if (!visited[v]) {
            DFS(v, t); // seguimos explorando
        }
    }
    // una vez vemos todos los vecinos del nodo actual
    visited[u] = false; // lo marcamos como no visitado, para en dado caso que debamos volver a pasa desde otra ruta, podemos tomarlo
    path.pop(); // y lo borramos del camino actual.
}
// mostramos los caminos que podemos tomar para ir de un nodo a otro
void showPaths() {
    for(auto& s: paths) {
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cnl;
    }
}

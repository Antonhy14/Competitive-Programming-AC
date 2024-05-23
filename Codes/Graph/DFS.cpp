const int N = 1e5 + 5;
// Grafo, con lista de adyacencia
vector<int> graph[N];
// Arreglo de los nodos ya visitados, para evitar bucles
bool vis[N];

void dfs(int u) {
    // a cada noodo que se le aplique dfs, se marca como visitado
    vis[u] = true;

    // vemos los vecinos del nodo actual
    for(auto v:graph[u]) {
        // y si no lo hemos visto
        if(!vis[v]) 
            dfs(v); // hacemos la dfs
    }
}

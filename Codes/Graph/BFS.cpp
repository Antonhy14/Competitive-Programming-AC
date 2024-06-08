const int N = 1e5 + 5; // maximo numero de nodos
const int INF = 1e9; // valor para llenar la lista de distancias

vector<int> graph[N]; // el grafo con lista de adyacencia
int dist[N]; // lista con las distancias que cuesta llegar a cada nodo

// codigo base de bfs
void bfs(int s) {
    fill(dist, dist + N, INF); // se llena la lista de distancias de INF
    queue<int> q; // cola que lleva el orden en el que se deben hacer las exploraciones

    dist[s] = 0; // llegar al nodo de inicio toma nos toma 0
    q.push(s); // iniciamos la exploracion

    while(!q.empty()) {
        int curr = q.front(); // tomamos el nodo al frente de la cola...
        q.pop(); // y lo borramos

        // explorar los vecinos del nodo actual
        for(auto& next: graph[curr]) {
            // si no hemos llegado...
            if(dist[next]==INF) {
                // actualizamos la distancia
                dist[next] = dist[curr] + 1; // con la que toma llegar al nodo actual mas 1

                q.push(next); // y agregamos este nodo a la cola
            }
        }
    }
}

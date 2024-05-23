const int N = 1e5 + 5;

int n, m;
ll dist[N]; // aqui se guardara el coste que tiene llegar a cada nodo

struct Edge{
    int v; // a donde vamos
    ll dist; // cuanto cuesta
};
vector<Edge> graph[N]; // el grafo

struct State{
    int u; // el nodo actual
    ll dist; // el costo de seguir con la ruta actual

    bool operator < (const State& x) const{
        return !(dist < x.dist);
        // En las priority queues, se ordena de manera contraria a lo establecido.
    }
};

const ll INF = 1e18 + 5; // valor grande para poder elegir el mejor

void Dijkstra(int s, int t) {
    fill(dist, dist + n + 1, INF);
    // llenamos todo con un valor grande para que no compare con 0
    priority_queue<State> pq;

    dist[s] = 0; // empezamos la ruta
    pq.push({s, 0}); // agregamos a la pq

    while(!pq.empty()) {
        auto curr = pq.top(); // elegimos la mejor expansion
        pq.pop();

        if(curr.dist!=dist[curr.u]) continue;
        // si no coincide lo que llevamos con lo almacenada, omitimos esta expansion.
        // que no coincida quiere decir que esta ya no es la mejor ruta

        // para un unico objetivo
        // if(curr.u == t) break;


        // visitamos lo vecinos de curr
        for(auto& e: graph[curr.u]) {
            ll newDist = curr.dist + e.dist; // cuanto nos costaria esta expansion

            // si es mejor tomar esta ruta
            if(newDist < dist[e.v]) {
                // entonces, la actualizamos e intentamos expandirnos por esta ruta
                dist[e.v] = newDist;
                pq.push({e.v, newDist});
            }
        }
    }
}

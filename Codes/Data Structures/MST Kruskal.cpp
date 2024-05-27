// MST con el algoritmo de Kruskal
struct Graph{
    // forma de cada arista
    struct Edge{
        int src; // de donde
        int dest; // a donde
        ll weight; // peso
    };

    int V; // cantidad de nodos del grafo
    vector<Edge> edges; // todas las conexiones
    vi pr, frds; // padres y la cantidad de amigos que hay en cada grupo

    Graph(int v): V(v), pr(v), frds(v, 1) {
        iota(all(pr), 0); // cada quien es su propio padre en un unicio y tiene un solo amigo
    }
    // funcion para agregar las aristas que usaremos para unir el arbol
    void addEdge(int src, int dest, int weight) {
        edges.pb({src, dest, weight});
    }
    // funcion para saber quien es padre de quien
    int find(int u) {
        if(pr[u]!=u) 
            pr[u] = find(pr[u]);

        return pr[u];
    }
    // funcion para unir
    void unite(int u, int v) {
        // el subarbol mas pequeño se une al arbol mas grande
        if(frds[u] < frds[v])
            swap(u, v);
        // hacemos amigos
        frds[u]+= frds[v];
        pr[v] = pr[u];
    }
    // se toman las mejores aristas para hacer el arbol
    void MST() {
        vector<Edge> res; // se guarda las aristas tomadas
        // se hace orden por peso
        sort(all(edges), [&] (const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });
        // vemos las aristas
        for(auto& edge: edges) {
            int u = find(edge.src);
            int v = find(edge.dest);
            // si no son parte del mismo grupo
            if(u!=v) {
                res.pb(edge);
                unite(u, v); // se hacen amigos
            }
        }
        // Vemos las conexiones que tomamos
        for(auto& edge: res)
            cout << edge.src << " -> " << edge.dest << ": " << edge.weight << nl;
    }
};

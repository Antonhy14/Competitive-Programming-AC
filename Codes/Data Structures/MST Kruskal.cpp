// MST con el algoritmo de Kruskal
struct Graph{
    // forma de cada arista
    struct Edge{
        int src; // de donde
        int dest; // a donde
        int weight; // peso
    };

    vector<Edge> edges; // todas la conexiones
    vi pr, lenST; // padres y la longitud de los subarboles
    int V; // cantidad de nodos del grafo

    // v es la cantidad de nodos que hay en el grafo
    Graph(int v): V(v), pr(v), lenST(v, 1) {
        iota(all(pr), 0); // cada quien es su propio padre en un unicio
    }
    // funcion para agregar las aristas que usaremos para unir el arbol
    void addEdge(int src, int dest, int weight) {
        edges.pb({src, dest, weight});
    }
    // funcion para saber quien es padre de quien
    int find(int u) {
        if(pr[u]!=u) {
            pr[u] = find(pr[u]);
        }
        return pr[u];
    }
    // funcion para unir
    void unite(int u, int v) {
        u = find(u), v = find(v); // unimos por padres(subarboles)
        
        if(u!=v) {
            // el subarbol mas pequeño se une al arbol mas grande, ayuda en operaciones futuras
            if(lenST[u] < lenST[v]) 
                swap(u, v);
            // unimos subarboles
            lenST[u]+= lenST[v];
            pr[v] = u;
        }
    }
    // se toman las mejores aristas para hacer el arbol
    void MST() {
        vector<Edge> result; // se guarda las aristas tomadas
        // se hace orden por peso
        sort(all(edges), [&] (Edge a, Edge b) {
            return a.weight < b.weight;
        });

        // vemos las aristas
        for(auto& edge: edges) {
            int u = find(edge.src); 
            int v = find(edge.dest);
            // si no son parte del mismo subarbole
            if(u!=v) {
                unite(u, v); // se unen
            }
        }
    }
};
// *nota: se puede modificar el orden para unir por las conexiones mas caras.

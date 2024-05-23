// Algoritmo de los amigos :D
struct DSU {
    // Aqui guardamos, quien los representantes de cada grupo y la cantidad de amigos que tiene cada grupo
    vector<int> pr, frds;
    int groups; // cantidad de grupos que hay en total
    
    // n es la cantidad de personas que hay en total.
    // para 0 indexado solo se quita el +1
    // el groups no se suma 1 porque agregaria a una persona que no existe
    DSU(int n): pr(n+1), groups(n), frds(n+1, 1) {
        iota(all(pr), 0); // cada quien es su mismo representante al inicio
    }
    // funcion que busca al representante
    int find(int u) {
        return pr[u]==u ? u: find(pr[u]);
    }
    // funcion para hacer amigos
    void unite(int u, int v) {
        // unimos por representantes
        u = find(u), v = find(v);
        // solo si no son partes del mismo grupo los unimos
        if(u!=v) {
            // para facilitar proximos operaciones, unimos a quien mas amigos con quien tenga menos. (rank)
            if(frds[u] < frds[v]) 
                swap(u, v);
                
            // unimos grupos
            frds[u]+= frds[v]; 
            pr[v] = u;
            groups--;
        }
    }
    // si tiene el mismo representante son amigos
    bool areFriends(int u, int v) {
        return find(u)==find(v);
    }
    // cuantos amigos tiene...
    int getFriends(int u) {
        return frds[find(u)];
    }

    // *nota: para matrices, cada amigo es un punto en ella, asi que debe modificarse para esos casos la estructura. la cantidad amigos sera de n*n o n*m
};

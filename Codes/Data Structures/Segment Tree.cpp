struct SegmTree{
    int l, r; // rango del segmento
    ll sum; // lo que guarda
    SegmTree* left; // su hijo de la izquierda
    SegmTree* right; // su hijo de la derecha

    // Inicializar los valores del rango
    SegmTree(int a, int b): l(a), r(b) {}

    void pull() {
        sum = left->sum + right->sum; // modificar lo que guarda este segmento
    }

    // Construir la base del Segment Tree
    void build(const vi& v) {
        if(l==r) { // Si ya estoy en un nodo hoja, le doy un valor
            sum = v[l]; 
            return;
        }
        // Si no, calculo la mitad para agregarle dos hijos
        int m = (l+r) / 2;

        left = new SegmTree(l, m);
        right = new SegmTree(m+1, r);
        left -> build(v);
        right -> build(v);

        pull(); // y modifico los valores
    }

    // Actualizaciones
    void update(int i, int x) {
        if (l == r) sum = x; // si es el nodo que busco, le cambio el valor
        else { // si no, sigo buscando
            int m = (l + r) / 2;
            // veo en donde esta, y sigo buscando hasta encontrarlo
            if (i <= m) left->update(i, x);
            else if(i >= m) right->update(i, x);
            // mientras voy regresando, modifico los segmentos que dependen del nodo que quiero modificar
            pull();
        }
    }

    // consultas en rango
    ll query(int x, int y) {
        if(r <  x || y < l) return 0; // si no forma para de la query, regreso un valor invalido o que no afecte al resultado
        if(x<=l && r<=y) return sum; // si este segmento abarca toda la consulta, regreso lo que tenga almacenado
        // Sino, bajo a sus hijos hasta que se cumpla
        ll a = left -> query(x, y); 
        ll b = right -> query(x, y);

        return a + b; // y regreso los resultado de los dos hijos
    }
};

// En el main, crea un nodo raiz con rango de [0, n-1] o [1,n], despues llama la funcion build con el vector que tenga los valores originales
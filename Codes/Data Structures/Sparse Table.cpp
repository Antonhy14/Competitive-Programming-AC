const int N = 1e5 + 5; // maximo de elementos
const int K = 17; // maximo log2 que podemos utilizar

int n; // cantidad de elementos para el caso actual
int arr[N]; // lista de elementos
int lg[N]; // log2 de cada numero
int sp[N][K]; // la Sparse Table

void precompute() {
    // Primero llenamos el todas los bloques de 2^0 con los elementos dados
    fore(i,0,n+1) {
        sp[i][0] = arr[i];
    }
    // Para no tener que usar la funcion log2 que agrega "tiempos fantasma" precomputamos los log2 que talvez usemos
    fore(i,2,n+1) {
        lg[i] = lg[i >> 1] + 1; // i >> 1, dice que vaya a la mitad
    }

    // precomputamos el resto de bloques posibles
    fore(k, 1, K) {
        for(int l = 0; l < n; ++l) {
            int r = l + (1 << k - 1); // desplaza 1 bit k-1 veces, lo mismo que hacer 2^k-1
            if(r>=n) continue; // si ya no se pueden hacer mas bloque de 2^k, omitimos

            sp[l][k] = min(sp[l][k-1], sp[r][k-1]);
            // precomputamos, tomando el menor que ya teniamos de los bloques que abarcan el nuevo rango
            // por ejemplo, para 2^2, usamos dos bloque de 2^1 y el menor de estos lo guarda en el bloque que inicie en l y que sea de 2^2 actual
        }
    }
}

void showSP() {
    fore(k,0,K) {
        cout << "2^" << k << ": ";
        for(int l = 0; l < n; ++l) {
            int r = l + (1 << k);
            if(r>n) continue;

            cout << sp[l][k] << ' ';
        }
        cnl;
    }
}

// query de log(n), n es el largo de la query
int query1(int l, int r) {
    int res = INT_MAX; // nuestro resultado lo inicializamos con un numero grande
    int lenq = r-l+1; // obtenemos el largo que abarga la query

    // 1 >> k: quita los k bits de la derecha.
    // &: para saber si es una potencia de 2(en realidad no pero es lo que entendi xd)

    for(int k = K-1; k>=0; --k) {
        if((lenq >> k) & 1) { // si es un k que podemos tomar, lo usamos, o sea si al restar esta potenciar de lenq no se pasa de 0
            res = min(res, sp[l][k]); // el minimo de la cubeta que inicia en l y es de 2^k
            l+= (1 << k); // movemos l con la longitud de la cubeta que usamos
        }
    }

    return res; // regresamos la respuesta
}

// query O(1)
int query2(int l, int r) {
    int k = lg[r-l+1]; // obtenemos el log2 que no exede la query

    // tomamos una cubeta de 2^k desde l y otra desde r-2^k+1 hasta r(que tambien seria de 2^k) las comparmos y regresamos el menor
    return min(sp[l][k], sp[r - (1 << k) + 1][k]);
}

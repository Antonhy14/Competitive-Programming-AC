#define lsb(x) (x & -x)
const int N = 1e5 + 5;

int a[N];
int n;
vector<ll> fenwick;

// Update
void update(int index, int delta) {
    for(; index <= n; index+= lsb(index)) 
        fenwick[index]+= delta;
}
// Queries en un lugar
ll query(int index) {
    ll sum=0;
    for(; index >0; index-= lsb(index)) 
        sum+= fenwick[index];
    return sum;
}
// Queries en rango
ll query(int l, int r) {
    return query(r) - query(l-1);
}
// Inicializa el conjunto con los valores iniciales.
void build() {
    fore(i, 1, n+1) {
        fenwick[i] += a[i];
        int pr = i + lsb(i);

        if(pr<=n) fenwick[pr]+= fenwick[i];
    }
}
// *nota: si se llena con numeros generados la estructura, entonces, se debe usar la funcion build con la lista de dichos numeros.
// Pero si es con numero que se van dando en la ejecucion del programa se usa update directamente.
// ** que se use build no quiere decir que no se usara update

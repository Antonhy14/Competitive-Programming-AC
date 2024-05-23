const int N = 1e5 + 5; // numero total
const int SQRT = max(1, int(sqrt(N))) + 5; // raiz
int arr[N]; // arreglo con los datos originales
int indexed[N]; // arreglo que dice a que cubeta pertence cada elemento
int bucket[SQRT]; // las cubetas que nos dice que hay en ella

void precompute() {
    fore(i, 1, N) {
        indexed[i] = i/SQRT;
        bucket[indexed[i]]; // aqui se prepara con los datos que ya se tienen.
    }
}

void update(int i, int x) {
    bucket[indexed[i]]; // ...
}

void query(int l, int r) {
    while(l%SQRT==0 && l+SQRT<=n) {
        // ...
        l+= SQRT;
    }
    while(l<=r) {
        // ...
        l++;
    }
}

// Para saber si solo un número es o no primo
bool prime(int n) {
    // Todo numero par no es primo, excepto el 2, 1 tampoco cuenta como primo.
    if(n%2==0 && n!=2 || n<=1) 
        return false;

    // pasando la raiz del numero, ya no hay divisores,
    for(int i = 3; i*i<=n; i+=2){
        // si en algun momento tiene un divisor, ya no es primo
        if(n%i==0)
            return false;
    }
    // si no se encuentra otro divisor, entonces es primo.
    return true;
}

// Con Criba, para saber si varios números son primos.
const int N = 1e5 + 1;
vector<int> primes(N, 1);
void criba() {
    // 0 y 1 no son primos
    primes[0] = primes[1] = 0;

    // por cada numero no tachado de primo, se tacha todos sus multiplos
    // al final quedan solo los primos
    for(int p = 2; p*p <= N; p++) {
        if(primes[p]) {
            for(int i = p*p; i<=N; i+=p) {
                primes[i] = 0;
            }
        }
    }
}

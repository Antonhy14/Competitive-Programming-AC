// AC = AntonhyCoder
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define cnl cout << '\n'
#define nl '\n'
#define sp(x,n) fixed << setprecision(x) << n
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define len(x) int(x.length())
#define fore(i,l,r) for(auto i=l;i<r;i++)
#define pb push_back
#define pf push_front
#define lsb(x) (x & -x)

using vi = vector<int>;
using vii = vector<pair<int, int>>;
using ii = pair<int, int>;
/*
    Valores ASCII
    'A' = 65 'Z' = 90
    'a' = 97 'z' = 122
    '0' = 48 '9' = 57
*/
// 1LL *: convierte el siguiente numero a long long int
/*
	Problema: Encontrar todas la posibles formas de llegar desde la casilla (1, 1) hasta la casilla (n, m).
	Mostrar en modulo de 10^9 + 7

	1 <= n, m << 500
*/

const int N = 500 + 5;
const int MOD = 1e9 + 7;

int n, m;
ll mem[N][N]; // memorizar
bitset<N> done[N]; // saber si ya lo calculamos

ll dp(int i, int j) {
	// Casos base
    if(i==n && j==m) { // llegamos al final
    	return 1;
    }
    if(i > n || j > m) { // casilla invalida
    	return 0;
    }

    ll& ans = mem[i][j];
    if(!done[i][j]) { // no esta hecho
    	done[i][j] = true; // lo hacemos

    	ans = (dp(i+1, j) + dp(i, j+1)) % MOD; // y calculamos
    }

    return ans; // regresamos el resultado
}

int main(){
    cin.tie(0) -> sync_with_stdio(0), cout.tie(0);

    cin >> n >> m;

    cout << dp(1, 1);

    cout << '\n';
    
    return 0;
}

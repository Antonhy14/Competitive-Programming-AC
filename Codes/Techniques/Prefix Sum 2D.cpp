const int N = 1e3 + 5;

int mat[N][N]; // la matriz se usa 1 indexada(aqui)
ll pref[N][N]; // global para que este llena de 0's
void prefixSum2D() {
    // llenar la prefix (no se si es el o la prefix xd)
    fore(r, 1, N) {
        fore(c, 1, N) {
            pref[r][c] = 
                pref[r-1][c] + // le sumamos lo que hay en la prefix en la parte superior
                pref[r][c-1] - // le sumamos lo que hay en la prefix a la izquierda
                pref[r-1][c-1] + // en los dos pasamos anteriores se llega hasta la esquina superior izquierda, por lo que esta se suma dos veces, por eso debemos borrarla para que no haya demas
                mat[r][c]; // agregamos el nuevo valor. puede estar de cualquier forma
        }
    }

    // responder consultas
    int r1, c1, r2, c2;
    ll res = pref[r2][c2] - // a la prefix en el rango mayor
    pref[r1-1][c2] - // le quitamos lo que hay en la prefix en la parte superior
    pref[r2][c1-1] + // le quitamos lo que hay en la prefix a la izquierda
    pref[r1-1][c1-1]; // en los dos pasamos anteriores se llega hasta la esquina superior izquierda, por lo que esta se resta dos veces, por eso debemos sumarla para que no haya de menos
}

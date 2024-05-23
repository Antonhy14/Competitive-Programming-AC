vector<int> v; // vector ordenado con los elementos
int binary_search(int x) {
    int l=0, r = v.size()-1; // inicio y fin de donde vamos a buscar

    while(l<=r) {
        int m = (l+r)/2; // calcular la mitad

        if(v[m]==x) // si es el numero que buscamos, lo retornamos
            return m;
        else if(x<v[m]) // si el numero que buscamos es mas chico, acortamos la derecha
            r = m-1;
        else if(x>v[m]) // si el numero que buscamos es mas grande, acortamos la izquierda
            l = m+1;
    }
    return -1; // y en caso no encontrarse en el vector, regresamos -1
}
// *nota: debe estar ordenado el vector/lista para que funcione

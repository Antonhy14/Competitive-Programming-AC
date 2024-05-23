vector<int> v; // vector ordenado con los elementos
int ternary_search(int x) {
    int l=0, r = v.size()-1; // inicio y fin de donde vamos a buscar

    while(l<=r) {
        int m1 = l + ((r-l) / 3); // calcular mitad 1
        int m2 = r - ((r-l) / 3); // calcular mitad 2

        // si es el numero que buscamos, lo retornamos
        if(v[m1]==x) 
            return m1+1;
        else if(v[m2]==x)
            return m2+1;
        else if(x<v[m1]) // si el numero que buscamos es mas chico que la primera mitad, acortamos la derecha
            r = m1-1;
        else if(x>v[m2]) // si el numero que buscamos es mas grande que la segunda mitad, acortamos la izquierda
            l = m2+1;
        else 
            l = m1+1, r = m2-1; // si nada de lo anterior ocurre, recortamos ambas mitades
    }
    return -1; // y en caso no encontrarse en el vector, regresamos -1
}
// *nota: debe estar ordenado el vector/lista para que funcione

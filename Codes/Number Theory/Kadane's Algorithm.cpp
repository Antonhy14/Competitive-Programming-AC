void Kadane_Algorithm(vector<int>& nums) {
    // Al principio la suma maxima y la actual son el inicio del vector
    int res = nums[0], curr = nums[0];
    // Los indices tambien
    int l = 0, r = 0, temp = 0;

    fore(i, 1, sz(nums)) {
        // Si el numero nuevo es una mejor solucion que todo lo que llevamos...
        if(nums[i] > curr + nums[i]) {
            // La suma actual pasa a ser ese numero
            curr = nums[i];
            // Y nuestro inicio temporal sera la posiciones de ese elemento
            temp = i;
        }
        // Sino entonces solo lo añadimos a la suma actual
        else 
            curr+= nums[i];

        // Si hemos encontrado una mejor solucion a la que llevamos...
        if(curr > res) {
            // El resultado pasa a ser la respuesta actual
            res = curr;
            // El inicio temporoal nos dice en que posicion es que inicia ese subarreglo
            l = temp;
            // Y la posicion del elemento actual es donde termina el subarreglo
            r = i;
        }
    }

    // Se muestra cual es la solucion
    // Primero, los elementos que conforman ese subarreglo
    fore(i, l, r+1)
        cout << nums[i] << " ";
    cnl;
    // Despues la suma maxima conseguida
    cout << res;
}

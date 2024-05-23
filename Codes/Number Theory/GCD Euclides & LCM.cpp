int gcd(int a, int b) {
    if(b==0) 
    	return a;  // Si mcd(a,0) finaliza y devuelve el mcd, si no hay pues 1
    return gcd(b, a%b); // Si b!=0 entonces llama la funcion otra vez con a=b y b=a%b
}

int lcm(int a, int b) {
	return (a*b) / gcd(a, b);
}

// la función gcd ya existe en c++
__gcd(a, b);

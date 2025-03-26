template <const int M>
struct Modular {
	int v;
	Modular(int a = 0): v(a) {}
	Modular(ll a): v(a % M) {
		if(v < 0) v+= M;
	}
 
	Modular operator+(Modular m) {
		return Modular((v + m.v) % M);
	}
 
	Modular operator-(Modular m) {
		return Modular((v - m.v + M) % M);
	}
 
	Modular operator*(Modular m) {
		return Modular((1LL * v * m.v) % M);
	}
 
	Modular operator/(Modular m) {
		return Modular(v) * m.inv();
	}
 
	Modular inv() {
		return fpow(M - 2);
	}
 
	Modular fpow(int k) {
		if(k == 0) return 1;
		if(k == 1) return *this;
 
		if(k % 2) return fpow(k - 1) * *this;
 
		auto aux = fpow(k / 2);
		return aux * aux;
	}
};
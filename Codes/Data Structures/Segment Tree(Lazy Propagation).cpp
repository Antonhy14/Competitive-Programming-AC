struct SegmTree{
    int l, r; 
    ll sum; 
    int lazy; // Para manejar las actualizaciones perezosas
    SegmTree* left; 
    SegmTree* right; 

    SegmTree(int a, int b): l(a), r(b), lazy(0) {}

    void pull() {
        sum = left->sum + right->sum; 
    }

    void push() {
        if (lazy != 0) {
            sum += (r - l + 1) * lazy; // Aplica el marcado pendiente
            if (l != r) { // Si no es una hoja, propaga el marcado a los hijos
                left->lazy += lazy;
                right->lazy += lazy;
            }
            lazy = 0; // Resetea el marcado
        }
    }

    void build(const vi& v) {
        if(l == r) { 
            sum = v[l]; 
            return;
        }
        
        int m = (l+r) / 2;
        left = new SegmTree(l, m);
        right = new SegmTree(m+1, r);
        left->build(v);
        right->build(v);
        pull(); 
    }

    void update(int x, int y, int val) {
        push();
        if(x > r || y < l) return; 
        if(x <= l && r <= y) {
            lazy += val; // Aplica el marcado perezoso
            push();
            return;
        }
        
        left->update(x, y, val);
        right->update(x, y, val);
        pull();
    }

    ll query(int x, int y) {
        push();
        if(r <  x || y < l) return 0; 
        if(x <= l && r <= y) return sum; 
        
        ll a = left->query(x, y); 
        ll b = right->query(x, y);
        return a + b; 
    }
};
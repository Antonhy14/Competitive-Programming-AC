int arr[N];

struct SegmTree{
    int n;
    vi tree;

    SegmTree(int size): tree(4 * size), n(size) {}

    void build(int node, int l, int r) {
        if(l==r) tree[node] = arr[l];
        else {
            int m = (l+r) / 2;

            build(2 * node, l, m);
            build(2 * node + 1, m+1, r);

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void build() {
        build(1, 1, n);
    }

    int query(int l, int r, int node, int s, int e) {
        if(r < s || e < l) return 0;
        if(l <= s && e <= r) return tree[node];

        int m = (s+e) / 2;

        int left = query(l, r, 2 * node, s, m);
        int right = query(l, r, 2 * node + 1, m+1, e);

        return left + right;
    }

    int query(int l, int r) {
        return query(l, r, 1, 1, n);
    }

    void update(int i, int delta, int node, int s, int e) {
        if(s == e) tree[node] = arr[i] = delta;
        else {
            int m = (s + e) / 2;

            if(i <= m) update(i, delta, 2 * node, s, m);
            else update(i, delta, 2 * node + 1, m+1, e);

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int i, int delta) {
        update(i, delta, 1, 1, n);
    }
};
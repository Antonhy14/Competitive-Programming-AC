struct SegmTree {
    int n;
    vi tree;

    SegmTree(int size): tree(4*size), n(size) {}

    void build(const vi &v, int idx, int l, int r) {
        if (l == r) tree[idx] = v[l];
        else {
            int m = (l + r) / 2;

            build(v, 2 * idx, l, m);
            build(v, 2 * idx + 1, m + 1, r);

            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    void build(const vi &v) {
        build(v, 1, 1, sz(v));
    }

    void update(int i, int x, int idx, int l, int r) {
        if (l == r) tree[idx] = x;
        else {
            int m = (l + r) / 2;

            if (i <= m) update(i, x, 2 * idx, l, m);
            else update(i, x, 2 * idx + 1, m + 1, r);

            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    void update(int i, int x) {
        update(i, x, 1, 1, n);
    }

    int query(int x, int y, int idx, int l, int r) {
        if (r < x || y < l) return -INF;
        if (x <= l && r <= y) return tree[idx];

        int m = (l + r) / 2;

        int left = query(x, y, 2 * idx, l, m);
        int right = query(x, y, 2 * idx + 1, m + 1, r);

        return max(left, right);
    }

    int query(int x, int y) {
        return query(x, y, 1, 1, n);
    }
};
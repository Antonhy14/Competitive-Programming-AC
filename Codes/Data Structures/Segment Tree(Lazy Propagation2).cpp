struct SegmTree {
    int n;
    vi tree, lazy;

    SegmTree(int size) : tree(4 * size), lazy(4 * size, 0), n(size) {}

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

    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {
            tree[idx] += lazy[idx];
            if (l != r) {
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void update(int x, int y, int val, int idx, int l, int r) {
        push(idx, l, r);

        if (r < x || y < l) return;
        if (x <= l && r <= y) {
            lazy[idx] += val;
            push(idx, l, r);

            return;
        }

        int m = (l + r) / 2;

        update(x, y, val, 2 * idx, l, m);
        update(x, y, val, 2 * idx + 1, m + 1, r);

        tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
    }

    void update(int x, int y, int val) {
        update(x, y, val, 1, 1, n);
    }

    int query(int x, int y, int idx, int l, int r) {
        push(idx, l, r);
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
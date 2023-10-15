template <class T> struct Stree {
	int n; T neut = inf; //remember to edit
	vector <T> tree;
	Stree(int n) : n(n) { tree.assign((n + 1) << 1, neut); }
	T merge(T &a, T &b) { return max(a, b); } //remember to edit
	void update(int k, T x) {
		k += n;
		tree[k] = merge(tree[k], x); // depends on the problem, edit
		for (k >>= 1; k; k >>= 1) tree[k] = merge(tree[k << 1], tree[k << 1 | 1]);
	}
	T query(int l, int r) {
		l += n, r += n;
		T ans = neut;
		while (l <= r) {
			if (l & 1) ans = merge(ans, tree[l++]);
			if (!(r & 1)) ans = merge(ans, tree[r--]);
			l >>= 1, r >>= 1;
		}
		return ans;
	}
};

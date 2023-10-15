/// Complexity: O(|N|*log|N|)
/// Tested: Not yet
struct node {
  node *left, *right;
  int v;
  node() : left(this), right(this), v(0) {}
  node(node *left, node *right, int v) :
    left(left), right(right), v(v) {}
  node* update(int l, int r, int x, int value) {
    if (l == r) return new node(nullptr, nullptr, v + value);
    int m = (l + r) / 2;
    if (x <= m)
      return new node(left->update(l, m, x, value), right, v + value);
    return new node(left, right->update(m + 1, r, x, value), v + value);
  }
};

///faster segtree persistent from cp-algorithms
///be careful with lazy creation

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(new_val + v->sum);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

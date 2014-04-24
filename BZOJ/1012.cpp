#include <cstdio>
#include <algorithm>
using namespace std;
struct Tree {
    Tree *lson, *rson;
    int l, r;
    int mx;
    void pushup() {
        mx = max(lson->mx, rson->mx);
    }
    Tree(int l, int r) : l(l), r(r) {
        mx = -1;
        if(l == r) {
            return ;
        }
        int m = l + r >> 1;
        lson = new Tree(l, m);
        rson = new Tree(m + 1, r);
    }
    int query(int L, int R) {
        if(L <= l && r <= R) {
            return mx;
        }
        if(L > r || R < l) return -1;
        return max(lson->query(L, R), rson->query(L, R));
    }
    void insert(int i, int val) {
        if(i < l || i > r) {
            return ;
        }
        if(l == r) {
            mx = val;
            return ;
        }
        lson->insert(i, val);
        rson->insert(i, val);
        pushup();
    }
} *tree;
int main() {
    int M, D, last = 0, end = 0, x;
    char op[10];
    scanf("%d%d",&M,&D);
    tree = new Tree(1, M);
    while(M--) {
        scanf("%s%d",op, &x);
        if(op[0] == 'Q') {
            last = tree->query(end - x + 1, end);
            printf("%d\n", last);
        } else {
            tree->insert(++end, (x + last) % D);
        }
    }
    return 0;
}

#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../../template/template.cpp"
#include "../../../data-structure/segtree/li-chao-tree.hpp"

int main() {
    using Tree = LiChaoTree<ll, LLINF>;
    Tree empty(vector<ll>{});
    Tree default_empty;
    for(Tree* tree : {&empty, &default_empty}) {
        tree->add_line(1, 2);
        tree->add_line(-1, -2);
        tree->add_segment(3, 4, -10, 10);
        tree->add_segment(3, 4, 0, 0);

        // Empty construction must not prevent later assignment and normal use.
        *tree = Tree(vector<ll>{3, -2, 0, 3});
        assert(tree->get_min(0) == LLINF);
        tree->add_line(2, 3);
        tree->add_segment(-1, -4, 0, 3);
        assert(tree->get_min(-2) == -1);
        assert(tree->get_min(0) == -4);
        assert(tree->get_min(3) == 9);
    }

    INT(a, b);
    print(a + b);
}

struct BinaryTrie {
    static const int B = 64;
    using ull = uint64_t;
    struct Node {
        int cnt;
        Node *child[2];
        Node() : cnt(0), child{nullptr, nullptr} {}
    };
    Node *root;
    BinaryTrie() : root(nullptr) {}
    int count(ull val) const {
        if(!root) {
            return 0;
        }
        Node *now = root;
        for(int i = B - 1; i >= 0; i--) {
            now = now->child[(val >> i) & 1ULL];
            if(!now) {
                return 0;
            }
        }
        return now->cnt;
    }
    Node *insert(Node *now, ull val, int i = B - 1) {
        if(!now) {
            now = new Node();
        }
        now->cnt++;
        if(i < 0) {
            return now;
        }
        bool dir = (val >> i) & 1ULL;
        now->child[dir] = insert(now->child[dir], val, i - 1);
        return now;
    }
    void insert(ull val) {
        if(count(val)) {
            return;
        }
        root = insert(root, val);
    }
    Node *erase(Node *now, ull val, int i = B - 1) {
        assert(now);
        now->cnt--;
        if(now->cnt == 0) {
            return nullptr;
        }
        if(i < 0) {
            return now;
        }
        bool dir = (val >> i) & 1ULL;
        now->child[dir] = erase(now->child[dir], val, i - 1);
        return now;
    }
    void erase(ull val) {
        if(count(val) == 0) {
            return;
        }
        root = erase(root, val);
    }
    ull min_element(Node *now, ull val, int i = B - 1) {
        assert(now);
        if(i < 0) {
            return 0;
        }
        bool dir = (val >> i) & 1ULL;
        if(!now->child[dir]) {
            dir = !dir;
            return (1ULL << i) | min_element(now->child[dir], val, i - 1);
        } else {
            return min_element(now->child[dir], val, i - 1);
        }
    }
    ull min_element(ull val = 0) { return min_element(root, val); }
};
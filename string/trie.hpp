struct Trie {
    const char base;
    struct Node {
        vector<int> child; // 子の頂点番号 存在しなければ-1
        vector<int> ac;    // 受理状態になる文字列のid集合
        char c;            // 頂点を表す文字
        int common;        // このnodeを共有する文字列の個数
        Node(char c) : c(c), common(0) { child.assign(26, -1); }
    };
    vector<Node> nodes;
    char root;
    Trie(char base) : root(0), base(base) { nodes.emplace_back(Node(root)); }
    void insert(const string &s, int wid) {
        int now = 0;
        for(int i = 0; i < (int)s.size(); i++) {
            int &nxt = nodes[now].child[s[i] - base];
            if(nxt == -1) {
                nxt = (int)nodes.size();
                nodes.emplace_back(Node(s[i]));
            }
            nodes[now].common++;
            now = nxt;
        }
        nodes[now].common++;
        nodes[now].ac.emplace_back(wid);
    }
    void insert(const string &s) { insert(s, nodes[0].common); }
    // prefixを持つ文字列があるかどうか調べたい場合は、引数prefixにtrueをセットする
    bool search(const string &s, bool prefix = false) {
        int now = 0;
        for(int i = 0; i < (int)s.size(); i++) {
            int &nxt = nodes[now].child[s[i] - base];
            if(nxt == -1) {
                return false;
            }
            now = nxt;
        }
        return (prefix ? true : (nodes[now].ac.size() > 0));
    }
    int count() const { return (nodes[0].common); }
    int size() const { return ((int)nodes.size()); }
};
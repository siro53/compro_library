#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "../../../template/template.cpp"
#include "../../../data-structure/persistent/persistent-queue.hpp"

int main() {
    int Q;
    cin >> Q;
    vector<PersistentQueue<int>> ques(Q + 1);
    REP(i, Q) {
        int mode, t, x;
        cin >> mode >> t;
        auto que = ques[t + 1];
        if(mode == 0) {
            cin >> x;
            ques[i + 1] = que.push(x);
        } else {
            cout << que.front() << '\n';
            ques[i + 1] = que.pop();
        }
    }
}
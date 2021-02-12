template <typename T> struct SWAG {
    struct Data {
        T x, sum;
        Data() {}
        Data(T x, T sum) : x(x), sum(sum) {}
    };
    using F = function<T(T, T)>;
    stack<Data> frontStack, backStack;
    F f;

    SWAG(F f) : f(f) {}

    bool empty() { return (frontStack.empty() && backStack.empty()); }

    size_t size() { return frontStack.size() + backStack.size(); }

    void pop() {
        assert(!empty());
        if(frontStack.empty()) {
            frontStack.emplace(backStack.top().x, backStack.top().x);
            backStack.pop();
            while(!backStack.empty()) {
                T s = f(backStack.top().x, frontStack.top().sum);
                frontStack.emplace(backStack.top().x, s);
                backStack.pop();
            }
        }
        frontStack.pop();
    }

    void push(T val) {
        if(backStack.empty()) {
            backStack.emplace(val, val);
        } else {
            T s = f(backStack.top().sum, val);
            backStack.emplace(val, s);
        }
    }

    T fold_all() {
        assert(!empty());
        if(frontStack.empty()) {
            return backStack.top().sum;
        } else if(backStack.empty()) {
            return frontStack.top().sum;
        } else {
            return f(frontStack.top().sum, backStack.top().sum);
        }
    }
};
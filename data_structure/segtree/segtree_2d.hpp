template<class S, S (*op)(S, S), S (*e)()>
class segtree_2d {
private:
    int H, W;
    vector<vector<S>> node;
 
    S prod_w(int i, int lj, int rj) {
        S vl = e(), vr = e();
        for(lj += W, rj += W; lj < rj; lj >>= 1, rj >>= 1) {
            if(lj & 1) vl = op(vl, node[i][lj++]);
            if(rj & 1) vr = op(node[i][--rj], vr);
        }
        return op(vl, vr);
    }
 
public:
    segtree_2d(int h, int w) {
        H = 1, W = 1;
        while(H < h) H <<= 1;
        while(W < w) W <<= 1;
        node.resize(2*H, vector<S>(2*W, e()));
    }
 
    void set(int i, int j, S val) {
        i += H, j += W;
        int tmp = j;
        node[i][j] = val;
        while(i) {
            j = tmp;
            while(j) {
                node[i][j] = op(node[i][j], val);
                j >>= 1;
            }
            i >>= 1;
        }
    }
 
    S get(int i, int j) { return node[i+H][j+W]; }
 
    S prod(int li, int lj, int ri, int rj) {
        S vl = e(), vr = e();
        for(li += H, ri += H; li < ri; li >>= 1, ri >>= 1) {
            if(li & 1) vl = op(vl, prod_w(li++, lj, rj));
            if(ri & 1) vr = op(prod_w(--ri, lj, rj), vr);
        }
        return op(vl, vr);
    }
};
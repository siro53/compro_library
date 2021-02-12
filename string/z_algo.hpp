// すべて0-indexed
// n := |S| とする。
// s[i,j] := sの[i,j]の範囲の連続部分文字列とする。このとき、
// s[0, n-1](= s)とs[i, n-1]の最長共通接頭辞の長さを記録した配列を返す。
// 計算量はO(|S|)
vector<int> z_algo(const string &s) {
    int c = 0, n = (int)s.size();
    vector<int> z(n, 0);
    for(int i = 1; i < n; i++) {
        if(i + z[i - c] < c + z[c]) {
            z[i] = z[i - c];
        } else {
            int j = max(0, c + z[c] - i);
            while(i + j < n && s[j] == s[i + j]) {
                j++;
            }
            z[i] = j;
            c = i;
        }
    }
    z[0] = n;
    return z;
}
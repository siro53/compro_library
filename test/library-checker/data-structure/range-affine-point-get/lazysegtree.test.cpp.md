---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.14.2/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../template/template.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include \"../../../template/template.cpp\"\n#include \"../../../data-structure/segtree/lazy-segtree.hpp\"\
    \n#include \"../../../modint/modint.hpp\"\n\nusing mint = ModInt<MOD2>;\n\nstruct\
    \ MonoidAct {\n    struct S {\n        mint sum;\n        int len;\n        S()\
    \ {}\n        S(mint sum, int len): sum(sum), len(len) {}\n    };\n    using F\
    \ = pair<mint, mint>;\n\n    using value_type_S = S;\n    using value_type_F =\
    \ F;\n    inline static S op(const S &a, const S &b) {\n        return S(a.sum\
    \ + b.sum, a.len + b.len);\n    }\n    inline static S e() { return S(0, 0); }\n\
    \    inline static S mapping(const F &f, const S &x) {\n        return S(f.first\
    \ * x.sum + f.second * x.len, x.len);\n    }\n    inline static F composition(const\
    \ F &f, const F &g) {\n        return {f.first * g.first, f.first * g.second +\
    \ f.second};\n    }\n    inline static F id() { return {1, 0}; }\n};\n\nint main()\
    \ {\n    INT(N, Q);\n    LazySegtree<MonoidAct> seg(N);\n    REP(i, N) {\n   \
    \     INT(a);\n        seg.set(i, MonoidAct::S(a, 1));\n    }\n    REP(qid, Q)\
    \ {\n        INT(type);\n        if (type == 0) {\n            INT(l, r, b, c);\n\
    \            seg.apply(l, r, {b, c});\n        } else {\n            INT(i);\n\
    \            print(seg.get(i).sum);\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
- /verify/test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp.html
title: test/library-checker/data-structure/range-affine-point-get/lazysegtree.test.cpp
---

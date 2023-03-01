---
title: 実行時 modint
documentation_of: //data-structure/modint/dynamic-modint.hpp
---

実行時 modint。

入力時にmodが与えられるような問題で用いる。それ以外の場合は `modint/modint.hpp` を使う。

なぜわざわざ実行時 modint だけ別で構造体を作っているのかは、[barrett reduction と modint について](https://scrapbox.io/comproMEMO/barrett_reduction_%E3%81%A8_modint_%E3%81%AB%E3%81%A4%E3%81%84%E3%81%A6)に書いた。
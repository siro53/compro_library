---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/siro53/compro_library\n"
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.17/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\"\"\"Run oj-bundle and prepend the library's source\
    \ URL.\"\"\"\n\nimport subprocess\nimport sys\n\n\nSOURCE_COMMENT = b\"// Source:\
    \ https://github.com/siro53/compro_library\\n\"\n\n\ndef main():\n    args = sys.argv[1:]\n\
    \    try:\n        result = subprocess.run([\"oj-bundle\", *args], stdout=subprocess.PIPE)\n\
    \    except FileNotFoundError:\n        print(\"oj-bundle not found: install online-judge-verify-helper\"\
    , file=sys.stderr)\n        return 127\n\n    if result.returncode != 0:\n   \
    \     return result.returncode\n\n    if \"-h\" not in args and \"--help\" not\
    \ in args:\n        sys.stdout.buffer.write(SOURCE_COMMENT)\n    sys.stdout.buffer.write(result.stdout)\n\
    \    return 0\n\n\nif __name__ == \"__main__\":\n    sys.exit(main())\n"
  dependsOn: []
  isVerificationFile: false
  path: scripts/bundle.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: scripts/bundle.py
layout: document
redirect_from:
- /library/scripts/bundle.py
- /library/scripts/bundle.py.html
title: scripts/bundle.py
---

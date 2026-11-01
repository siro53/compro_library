#!/usr/bin/env python3
"""Run oj-bundle and prepend the library's source URL."""

import subprocess
import sys


SOURCE_COMMENT = b"// Source: https://github.com/siro53/compro_library\n"


def main():
    args = sys.argv[1:]
    try:
        result = subprocess.run(["oj-bundle", *args], stdout=subprocess.PIPE)
    except FileNotFoundError:
        print("oj-bundle not found: install online-judge-verify-helper", file=sys.stderr)
        return 127

    if result.returncode != 0:
        return result.returncode

    if "-h" not in args and "--help" not in args:
        sys.stdout.buffer.write(SOURCE_COMMENT)
    sys.stdout.buffer.write(result.stdout)
    return 0


if __name__ == "__main__":
    sys.exit(main())

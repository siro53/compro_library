#!/usr/bin/env python3
"""Run oj-bundle and annotate each expanded library at its insertion point."""

import re
import subprocess
import sys


SOURCE_COMMENT = b"// Source: https://github.com/siro53/compro_library\n"


def annotate_libraries(source):
    seen = set()
    output = []
    for line in source.splitlines(keepends=True):
        match = re.match(rb'^#line \d+ "(.*)"\r?\n?$', line)
        if match:
            path = match.group(1)
            if path not in seen:
                if seen:
                    output.append(SOURCE_COMMENT)
                seen.add(path)
        output.append(line)
    return b"".join(output)


def main():
    args = sys.argv[1:]
    try:
        result = subprocess.run(["oj-bundle", *args], stdout=subprocess.PIPE)
    except FileNotFoundError:
        print("oj-bundle not found: install online-judge-verify-helper", file=sys.stderr)
        return 127

    if result.returncode != 0:
        return result.returncode

    output = result.stdout
    if "-h" not in args and "--help" not in args:
        output = annotate_libraries(output)
    sys.stdout.buffer.write(output)
    return 0


if __name__ == "__main__":
    sys.exit(main())

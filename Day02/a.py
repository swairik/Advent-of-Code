import sys
import re

def redirect_IO_to_file():
    sys.stdin = open('in.txt', 'r')
    sys.stdout = open('out.txt', 'w')

def closeIO():
    sys.stdin.close()
    sys.stdout.close()

def read_lines_from_file(sep = None):
    if(sep == None):
        sep = '\n'
    with open('in.txt') as f:
        lines = f.read().split(sep)
    return lines

def fn(v):
    v = str(v).lstrip('0')
    if(len(v) % 2 == 1):
        return False
    if(v[:int(len(v) / 2)] == v[int(len(v) / 2):]):
        # print(v)
        return True
    return False


def solve():
    ranges = read_lines_from_file()
    vals = [(int(left), int(right)) for left, right in re.findall(r'(\d+)-(\d+)', ranges[0])]
    # print(vals)
    ans = 0

    for l, r in vals:
        for i in range(l, r + 1):
            if fn(i):
                ans += i

    print(ans)

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


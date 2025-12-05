import sys

def redirect_IO_to_file():
    sys.stdin = open('in.txt', 'r')
    sys.stdout = open('out.txt', 'w')

def closeIO():
    sys.stdin.close()
    sys.stdout.close()

def read_lines_from_file():
    with open('in.txt') as f:
        lines = f.read().split('\n')
    return lines


def solve():
    pass

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


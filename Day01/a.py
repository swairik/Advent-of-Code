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
    lines = read_lines_from_file()
    pos = 50
    cntZero = 0
    for line in lines:
        if(line[0] == 'L'):
            pos = (pos - int(line[1:]) + 100) % 100
        else:
            pos = (pos + int(line[1:])) % 100
        
        cntZero += (pos == 0)

    print(cntZero)

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


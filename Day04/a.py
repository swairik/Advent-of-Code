import sys

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


def solve():
    def is_valid(x, y, n, m):
        return x >= 0 and x < n and y >= 0 and y < m

    paper_roll_lines = read_lines_from_file()
    ans = 0
    for i in range(len(paper_roll_lines)):
        for j in range(len(paper_roll_lines[i])):
            if(paper_roll_lines[i][j] != '@'):
                continue
            surround_paper_rolls = 0
            for xx in range(-1, 2, 1):
                for yy in range(-1, 2, 1):
                    x = i + xx
                    y = j + yy
                    if(is_valid(x, y, len(paper_roll_lines), len(paper_roll_lines[i])) and paper_roll_lines[x][y] == '@'):
                        surround_paper_rolls += 1
            if(surround_paper_rolls <= 4):
                ans += 1

    print(ans)

    
if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


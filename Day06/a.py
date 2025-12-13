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
    numbers = read_lines_from_file()
    num_lst = []
    op_lst = []
    for num_row in numbers:
        try:
            nums = list(map(int, num_row.split()))
            num_lst.append(nums)
        except ValueError:
            op_lst.extend(num_row.split())

    ans = 0
    for j in range(len(num_lst[0])):
        tmp = 0 if op_lst[j] == '+' else 1
        for i in range(len(num_lst)):
            if(op_lst[j] == '*'):
                tmp *= num_lst[i][j]
            else:
                tmp += num_lst[i][j]

        ans += tmp

    print(ans)

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


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
    def get_merged_list(lst):
        lst = sorted(lst)
        res = [(lst[0][0], lst[0][1])]
        for items in lst:
            l, r = items[0], items[1]
            if items[0] <= res[-1][1]:
                l = res[-1][0]
                r = max(res[-1][1], items[1])
                res.pop()
            res.append((l, r))
        return res

    input = read_lines_from_file()
    ingredient_list = []
    ans = 0
    for inp in input:
        if(inp.count('-') == 1):
            ingredient_list.append(tuple(map(int, inp.split('-'))))        

    ingredient_list = get_merged_list(ingredient_list)
    for l, r in ingredient_list:
        ans += (r - l + 1)

    print(ans)

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


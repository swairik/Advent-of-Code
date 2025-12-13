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
    for i in range(len(numbers) - 1):
        num_lst.append(numbers[i])
    
    op_lst = [x for x in numbers[-1].split()]

    curr_pos = 0
    next_possible = True
    op_pos = 0
    ans = 0
    while(next_possible):
        next_possible = False
        space_pos = -1
        for i in range(len(num_lst)):
            space_pos = max(space_pos, num_lst[i].find(' ', curr_pos))

        if(op_pos == len(op_lst) - 1):
            space_pos = len(num_lst[0])
        else:
            next_possible = True

        # print(curr_pos, space_pos)

        tmp = 0 if op_lst[op_pos] == '+' else 1
        for j in range(curr_pos, space_pos):
            curr_num = 0
            for i in range(len(num_lst)):
                if(num_lst[i][j] != ' '):
                    curr_num = curr_num * 10 + int(num_lst[i][j])

            if(op_lst[op_pos] == '*'):
                tmp *= curr_num
            else:
                tmp += curr_num
            # print(curr_num, tmp)

        ans += tmp
            
        curr_pos = space_pos + 1
        op_pos += 1
        

    # print(num_lst)
    # print(op_lst)
    print(ans)


if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


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
    batteries = read_lines_from_file()
    ans = 0
    for battery_line in batteries:
        stack = [0] * (len(battery_line) + 1)
        mx_battery_joltage = 0
        for i in range(len(battery_line) - 1, -1, -1):
            stack[i] = max(stack[i + 1], int(battery_line[i]))

        # print(stack)

        for i in range(0, len(battery_line) - 1):
            joltage = (int(battery_line[i]) * 10) + stack[i + 1]
            mx_battery_joltage = max(mx_battery_joltage, joltage)

        ans += mx_battery_joltage

    print(ans)

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


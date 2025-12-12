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
    battery_lines = read_lines_from_file()
    ans = 0
    for battery_line in battery_lines:
        mx_battery_joltage = 0
        pos = 0
        n = len(battery_line)
        left = 12
        while(left > 0):
            max_pos = n - left
            batteries = battery_line[pos : max_pos + 1]
            max_val = max(batteries)
            while battery_line[pos] != max_val:
                pos += 1
            pos += 1
            left -= 1
            mx_battery_joltage = (mx_battery_joltage * 10) + int(max_val)
        # print(mx_battery_joltage)
        ans += mx_battery_joltage
    print(ans)

'''
    123456789012
    
'''

if __name__ == '__main__':
    redirect_IO_to_file()

    solve()

    closeIO()


import sys

sys.stdin = open('in.txt', 'r')
sys.stdout = open('out.txt', 'w')

s = input().split(',')
# print(s)

a = [0] * 9

for i in s:
    a[int(i)] += 1

print(a)

days = 256

for i in range(days):
    cnt = 0
    for i in range (9):
        if i == 0:
            cnt = a[i]
            a[i] = 0
        else :
            a[i - 1] = a[i]
            a[i] = 0
        # print("{} : {} ".format(i, cnt))
    a[6] += cnt
    a[8] += cnt

print("sum = {}".format(sum(a)))
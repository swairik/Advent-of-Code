with open('in.txt') as f:
    lines = f.read().strip().split('\n')

ans = 0

vals = []
symbols = []

for line_no, line in enumerate(lines):
    for pos, char in enumerate(line):
        if char == '.':
            continue
        try:
            val = int(char)
        except ValueError:
            symbols.append((line_no, pos))

mesh_mark = [[False] * len(lines[0]) for _ in len(lines)]

mesh_mark[0][1] = True

print(mesh_mark)

# for symbol in symbols:


for line_no, line in enumerate(lines):
    temp = 0
    for pos, char in enumerate(line):
        if char == '.':
            continue
        try:
            val = int(char)

        except ValueError:
            continue

print(symbols)

print(ans)

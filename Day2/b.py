with open('in.txt') as f:
    games = f.read().strip().split('\n')

RED = 12
GREEN = 13
BLUE = 14

ans = 0

for id, game in enumerate(games):
    g = game.split(':')[1]

    color_cnt = {'red' : 0, 'green' : 0, 'blue' : 0}
    for round in g.split(';'):
        for cubes in round.split(','):
            cube_cnt, color = cubes.split()
            cube_cnt = int(cube_cnt)
            color_cnt[color] = max(cube_cnt, color_cnt[color])

    temp = 1
    for cnt in color_cnt.values():
        temp *= cnt
        
    ans += temp

# with open('out.txt', 'w') as f:
#     f.write(str(ans))

print(ans)

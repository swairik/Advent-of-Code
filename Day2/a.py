with open('in.txt') as f:
    games = f.read().strip().split('\n')

RED = 12
GREEN = 13
BLUE = 14

ans = 0

for id, game in enumerate(games):
    g = game.split(':')[1]
    ok = True

    for round in g.split(';'):
        for cubes in round.split(','):
            cube_cnt, color = cubes.split()
            cube_cnt = int(cube_cnt)
            if color == 'red' and cube_cnt > RED:
                ok = False
            if color == 'blue' and cube_cnt > BLUE:
                ok = False
            if color == 'green' and cube_cnt > GREEN:
                ok = False
    
    if ok:
        ans += id + 1
            
# with open('out.txt', 'w') as f:
#     f.write(str(ans))

print(ans)

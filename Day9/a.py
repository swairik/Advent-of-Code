def getData(file):
    # reading and just removing the \n from the end
    with open(f"{file}.in") as f:
        data = [line.rstrip() for line in f]

    # preliminary print
    # print(data)

    # cleaned = [(direction, int(dist)) for move in data for (direction, dist) in move.split()]
    cleaned = []

    for move in data:
        dir, dist = move.split()
        cleaned.append([dir, int(dist)])

    # print(cleaned)
    return cleaned


def firstHalf(data):
    def tooFar(hx, hy, tx, ty):
        isAbsent = True
        for i in range(-1, 2):
            for j in range(-1, 2):
                if hx + i == tx and hy + j == ty:
                    isAbsent = False
                    break

        return isAbsent

    hx, hy, tx, ty = 0, 0, 0, 0
    lasthx, lasthy = 0, 0
    vis = set()
    for dir, dist in data:
        # print(f"trying for {dir}, {dist}")
        if dir == "U":
            # go up
            for _ in range(dist):
                hy += 1
                if tooFar(hx, hy, tx, ty):
                    tx, ty = lasthx, lasthy
                    vis.add((tx, ty))
                lasthx, lasthy = hx, hy
        elif dir == "D":
            # go down
            for _ in range(dist):
                hy -= 1
                if tooFar(hx, hy, tx, ty):
                    tx, ty = lasthx, lasthy
                    vis.add((tx, ty))
                lasthx, lasthy = hx, hy
        elif dir == "L":
            # go left
            for _ in range(dist):
                hx -= 1
                if tooFar(hx, hy, tx, ty):
                    tx, ty = lasthx, lasthy
                    vis.add((tx, ty))
                lasthx, lasthy = hx, hy
        else:
            # go right
            for _ in range(dist):
                hx += 1
                if tooFar(hx, hy, tx, ty):
                    tx, ty = lasthx, lasthy
                    vis.add((tx, ty))
                lasthx, lasthy = hx, hy
        # print(f"pos = {hx}, {hy} - {tx}, {ty}")

    # for v in vis:
    #     print(v)

    print(len(vis) + 1)


data = getData("in")
firstHalf(data)

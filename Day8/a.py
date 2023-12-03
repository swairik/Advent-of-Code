def getData(file):
    # reading and just removing the \n from the end
    with open(f"{file}.in") as f:
        data = [line.rstrip() for line in f]

    # preliminary print
    # print(data)

    cleaned = [[int(tree) for tree in treeRow] for treeRow in data]

    # print(cleaned)
    return cleaned


def firstHalf(data):  # 1688
    n, m = len(data), len(data[0])
    see = [[False for _ in range(m)] for _ in range(n)]

    # L To R
    for i in range(n):
        mx = 0
        for j in range(m):
            if j == 0:
                see[i][j] = True
            elif data[i][j] > mx:
                see[i][j] = True
            mx = max(mx, data[i][j])

    # R to L
    for i in range(n):
        mx = 0
        for j in range(m - 1, -1, -1):
            if j == m - 1:
                see[i][j] = True
            elif data[i][j] > mx:
                see[i][j] = True
            mx = max(mx, data[i][j])

    # T to B
    for j in range(m):
        mx = 0
        for i in range(n):
            if i == 0:
                see[i][j] = True
            elif data[i][j] > mx:
                see[i][j] = True
            mx = max(mx, data[i][j])

    # B to T
    for j in range(m):
        mx = 0
        for i in range(n - 1, -1, -1):
            if i == n - 1:
                see[i][j] = True
            elif data[i][j] > mx:
                see[i][j] = True
            mx = max(mx, data[i][j])

    ans = 0
    for i in range(n):
        for j in range(m):
            ans += 1 if see[i][j] else 0

    # for i in range(n):
    #     print(see[i], end="\n")

    print(ans)


def secondHalf(data):  #   410400
    n, m = len(data), len(data[0])
    ans = 0
    for i in range(n):
        for j in range(m):
            temp, cnt = 1, 0
            # Towards top
            x = i - 1
            while x >= 0:
                cnt += 1
                if data[x][j] >= data[i][j]:
                    break
                x -= 1
            temp *= cnt

            # Towards bottom
            cnt = 0
            x = i + 1
            while x < n:
                cnt += 1
                if data[x][j] >= data[i][j]:
                    break
                x += 1
            temp *= cnt

            # Towards left
            cnt = 0
            y = j - 1
            while y >= 0:
                cnt += 1
                if data[i][y] >= data[i][j]:
                    break
                y -= 1
            temp *= cnt

            # Towards right
            cnt = 0
            y = j + 1
            while y < m:
                cnt += 1
                if data[i][y] >= data[i][j]:
                    break
                y += 1
            temp *= cnt

            ans = max(ans, temp)

    print(ans)


data = getData("in")
firstHalf(data)
secondHalf(data)

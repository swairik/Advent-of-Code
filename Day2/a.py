from enum import IntEnum

FILE = "in.in"


def getData():
    # reading and just removing the \n from the end
    with open(FILE) as f:
        data = [line.rstrip() for line in f]

    # preliminary print
    # print(data)

    return data


class RESULT(IntEnum):
    WIN = 6
    DRAW = 3
    LOSE = 0


def scoreOfGame(combination):
    winCombo = ["A Y", "B Z", "C X"]
    drawCombo = ["A X", "B Y", "C Z"]
    if combination in winCombo:
        return RESULT.WIN
    if combination in drawCombo:
        return RESULT.DRAW
    return RESULT.LOSE


def score(token):
    scoreSheet = {"X": 1, "Y": 2, "Z": 3, "A": 1, "B": 2, "C": 3}
    return scoreSheet.get(token, 0)


def firstHalf(games):  # 8933
    ans = 0
    for game in games:
        ans += score(game[2])
        ans += scoreOfGame(game)
    print(ans)


def compute(token, result):
    combos = {
        "A": {"X": "Z", "Y": "A", "Z": "Y"},
        "B": {"X": "X", "Y": "B", "Z": "Z"},
        "C": {"X": "Y", "Y": "C", "Z": "X"},
    }
    s = 0
    if result == "Z":
        s += RESULT.WIN
    if result == "Y":
        s += RESULT.DRAW
    return s + score(combos[token][result])


def secondHalf(games):  # 11998
    ans = 0
    for game in games:
        ans += compute(game[0], game[2])
    print(ans)


games = getData()
firstHalf(games)
secondHalf(games)

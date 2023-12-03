def getData(file):
    # reading and just removing the \n from the end
    with open(f"{file}.in") as f:
        data = [line.rstrip() for line in f]

    # preliminary print
    # print(data)

    cleaned = [[int(num) for num in move.split()[1::2]] for move in data]

    # print(cleaned)
    return cleaned


def getBoard(file):
    rows, cols = 0, 0
    with open(f"{file}.in") as f:
        data = [line.rstrip() for line in f]
        cols = [int(i) for i in data[-1].split()][-1]
        data = data[:-1]
        rows = len(data)
    # print(data)
    board = [[" " for _ in range(cols)] for _ in range(cols * rows)]
    currRow = 0
    for boxes in data[::-1]:
        i = 0
        currCol = 0
        while i < len(boxes):
            i += 1
            board[currRow][currCol] = boxes[i]
            i += 3
            currCol += 1
        currRow += 1
    # print(board)
    return board


def firstHalf(data, board):  #   SPFMVDTZT
    rows, cols = len(board), len(board[0])
    for moves in data:
        move, FromCol, ToCol = moves[0], moves[1] - 1, moves[2] - 1
        currFromRow, currToRowInitial = 0, 0

        while currFromRow < cols * rows and board[currFromRow][FromCol] != " ":
            currFromRow += 1
        while currToRowInitial < cols * rows and board[currToRowInitial][ToCol] != " ":
            currToRowInitial += 1

        currFromRow -= 1

        while move:
            board[currFromRow][FromCol], board[currToRowInitial][ToCol] = (
                board[currToRowInitial][ToCol],
                board[currFromRow][FromCol],
            )
            currFromRow -= 1
            currToRowInitial += 1
            move -= 1

    topMostElem = []

    for col in range(cols):
        row = 0
        while row < rows * cols and board[row][col] != " ":
            row += 1
        row -= 1
        topMostElem.append(board[row][col])

    print("".join(topMostElem))


def secondHalf(data, board):  #   ZFSJBPRFP
    rows, cols = len(board), len(board[0])
    for moves in data:
        move, FromCol, ToCol = moves[0], moves[1] - 1, moves[2] - 1
        currFromRow, currToRowInitial = 0, 0

        while currFromRow < cols * rows and board[currFromRow][FromCol] != " ":
            currFromRow += 1
        while currToRowInitial < cols * rows and board[currToRowInitial][ToCol] != " ":
            currToRowInitial += 1

        currFromRow -= 1
        currToRowFinal = currToRowInitial

        while move:
            board[currFromRow][FromCol], board[currToRowFinal][ToCol] = (
                board[currToRowFinal][ToCol],
                board[currFromRow][FromCol],
            )
            currFromRow -= 1
            currToRowFinal += 1
            move -= 1

        currToRowFinal -= 1

        while currToRowInitial < currToRowFinal:
            board[currToRowInitial][ToCol], board[currToRowFinal][ToCol] = (
                board[currToRowFinal][ToCol],
                board[currToRowInitial][ToCol],
            )
            currToRowFinal -= 1
            currToRowInitial += 1

    topMostElem = []

    for col in range(cols):
        row = 0
        while row < rows * cols and board[row][col] != " ":
            row += 1
        row -= 1
        topMostElem.append(board[row][col])

    print("".join(topMostElem))


data = getData("in")
board = getBoard("board")
# firstHalf(data, board)
secondHalf(data, board)

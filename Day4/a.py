FILE = "in"


def getData():
    # reading and just removing the \n from the end
    with open(f"{FILE}.in") as f:
        data = [line.rstrip().split(",") for line in f]

    # preliminary print
    # print(data)

    cleaned = []
    for d in data:
        cleaned.append([[int(i) for i in item.split("-")] for item in d])

    # print(cleaned)
    return cleaned


def firstHalf(assignments):  #   584
    ans = 0
    for assignment in assignments:
        first, second = assignment

        if (first[0] <= second[0] and second[1] <= first[1]) or (
            second[0] <= first[0] and first[1] <= second[1]
        ):
            ans += 1
    print(ans)


def secondHalf(assignments):  #   933
    ans = 0
    for assignment in assignments:
        first, second = assignment
        if first[1] < second[0] or second[1] < first[0]:
            pass
        else:
            ans += 1
    print(ans)


assignments = getData()
# firstHalf(assignments)
secondHalf(assignments)

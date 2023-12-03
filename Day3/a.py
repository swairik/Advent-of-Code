FILE = "in"


def getData():
    # reading and just removing the \n from the end
    with open(f"{FILE}.in") as f:
        data = [line.rstrip() for line in f]

    # preliminary print
    # print(data)

    return data


def generatePrioritySet():
    a = [""]
    a.extend([chr(ord("a") + char) for char in range(26)])
    a.extend([chr(ord("A") + char) for char in range(26)])
    return a


def firstHalf(ruckSack):  #   7980
    priority = generatePrioritySet()
    ans = 0
    for items in ruckSack:
        firstCompartment = items[: len(items) // 2]
        secondCompartment = items[len(items) // 2 :]

        assert len(firstCompartment) == len(secondCompartment)

        for item in firstCompartment:
            if item in secondCompartment:
                ans += priority.index(item)
                break
    print(ans)


def secondHalf(ruckSack):  #   2881
    priority = generatePrioritySet()
    groups = [ruckSack[3 * i : 3 * (i + 1)] for i in range(len(ruckSack) // 3)]
    ans = 0
    for group in groups:
        for item in group[0]:
            if item in group[1] and item in group[2]:
                ans += priority.index(item)
                break
    print(ans)


ruckSack = getData()
# firstHalf(ruckSack)
secondHalf(ruckSack)

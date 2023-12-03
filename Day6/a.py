def getData(file):
    # reading and just removing the \n from the end
    with open(f"{file}.in") as f:
        data = f.read()

    # preliminary print
    print(data)

    # cleaned = [[int(num) for num in move.split()[1::2]] for move in data]

    # print(cleaned)
    return data


data = getData("in")

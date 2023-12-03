def getData():
    # reading and just removing the \n from the end
    with open("in.in") as f:
        data = [line.rstrip() for line in f]

    # converting data to int for calculation - empty line is present which present breaks in the calorie of each elf
    data = [int(line) if line else line for line in data]

    # preliminary print
    print(data)
    return data


def firstHalf(calories):  # ans = 71780
    maxCalorie, sum = 0, 0
    for calorie in calories:
        if calorie == "":
            maxCalorie = max(maxCalorie, sum)
            sum = 0
        else:
            sum += calorie

    print(maxCalorie)


def secondHalf(calories):  #   ans = 212489
    calorieSum = []
    sum = 0
    for calorie in calories:
        if calorie == "":
            calorieSum.append(sum)
            sum = 0
        else:
            sum += calorie

    calorieSum = sorted(calorieSum, reverse=True)
    print(calorieSum[0] + calorieSum[1] + calorieSum[2])


calories = getData()
# firstHalf(calories)
secondHalf(calories)

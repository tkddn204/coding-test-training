X = int(input())
sticks = [64]

if X == 64:
    print(1)
else:
    while True:
        minStick = min(sticks)
        halfMinStick = minStick // 2
        sticks.remove(minStick)
        sticks += [halfMinStick]
        if X > sum(sticks):
            sticks += [halfMinStick]
        elif X == sum(sticks):
            break

    print(len(sticks))

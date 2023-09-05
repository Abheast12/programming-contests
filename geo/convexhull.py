from math import atan, pow, pi

v1 = []
v = []
v2 = []

n = int(input())
mina = 10**9 + 1
minb = 10**9 + 1

for _ in range(n):
    a, b = map(int, input().split())
    if b < minb:
        minb = b
        mina = a
    elif b == minb and a < mina:
        mina = a
    v1.append((a, b))

for a, b in v1:
    if a != mina or b != minb:
        if mina == a:
            v.append(((pi/2, pow(b - minb, 2)), (a, b)))
        else:
            d = atan((b - minb)/(a - mina))
            dist = pow(b - minb, 2) + pow(a - mina, 2)
            v.append(((d, dist), (a, b)))

v.sort()
v2.append((mina, minb))
v2.append((v[0][1][0], v[0][1][1]))

pos = len(v) - 1
lastp = -1
firstp = -1

while pos >= 1:
    if v[pos][0][0] == v[pos-1][0][0]:
        if lastp == -1:
            lastp = pos
    else:
        if lastp != -1:
            firstp = pos
            break
    pos -= 1

if lastp != -1 and firstp != -1:
    v[firstp:lastp+1] = reversed(v[firstp:lastp+1])

for i in range(1, len(v)):
    while len(v2) >= 2:
        a1 = (v2[-1][0] - v2[-2][0]) * (v[i][1][1] - v2[-2][1])
        a2 = (v2[-1][1] - v2[-2][1]) * (v[i][1][0] - v2[-2][0])
        if a1 - a2 < 0:
            v2.pop()
        else:
            break
    v2.append((v[i][1][0], v[i][1][1]))

print(len(v2))
for a, b in v2:
    print(a, b)

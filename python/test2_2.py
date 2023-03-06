x = int(input("输入一个正整数："))

primefactors = []

for i in range(2, x):
    if x % i == 0:
        x //= i
        primefactors.append(i)
        i -= 1

if x != 1:
    print(x, end=' ')
for i in primefactors:
    print(i, end=' ')


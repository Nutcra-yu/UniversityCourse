# 分解质因数
x = int(input("输入一个正整数："))

prime = []

i = 2
while x != 1:
    if x % i == 0:
        prime.append(i)
        x /= i
    else:
        i += 1



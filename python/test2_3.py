# 判断回文数
x = int(input("输入一位五位数:"))
temp = x

y = 0

while temp != 0:
    i = temp % 10
    temp //= 10

    y *= 10
    y += i

#print(y)

if x == y:
    print("{}是回文数".format(x))
else:
    print("{}不是回文数".format(x))


a = int(input("输入："))

print("你的等级为：", end=' ')
if a < 0 or a > 100:
    print("成绩无效")
elif a <= 59:
    print("D")
elif a <= 69:
    print("C")
elif a <= 89:
    print("B")
elif a <= 100:
    print("A")
else:
    print("error")

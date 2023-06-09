x = int(input())
y = int(input())

primex = []
primey = []

# 对x，y分解质因数
i = 2
while x != 1:
    if x % i == 0:
        primex.append(i)
        x /= i
    else:
        i += 1

i = 2
while y != 1:
    if y % i == 0:
        primey.append(i)
        y /= i
    else:
        i += 1

#print("x="+"{}".format(primex))
#print("y="+"{}".format(primey))

# 最大公约数
common = []

i,j = 0,0
while i<len(primex) and j<len(primey):
    if primex[i] == primey[j]:
        common.append(primex.pop(i))
        del primey[j]
    elif primex[i] < primey[j]:
        i += 1
    elif primex[i] > primey[j]:
        j += 1

Value = 1

for i in common:
    Value *= i
    
print("最大公约数={}".format(Value))

#最小公倍数
for i in primex:
    Value*=i
    
for i in primey:
    Value*=i
    
print("最小公倍数={}".format(Value))

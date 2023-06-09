# 汉诺塔
l1 = [5, 4, 3, 2, 1]
l2 = []
l3 = []


def move(x, A, B, C):  # source dest temp
    # move(x,l1,l2) 将source[-x]位置上的盘子移动到dest
    if x == 1:
        C.append(A.pop())
        B.append(A.pop())
        B.append(C.pop())
    else:
        # 将顶层的盘子挪到temp上
        move(x-1, A, C, B)
        # 将目标盘子挪到dest
        B.append(A.pop())
        # 将temp上的盘子挪到dest
        move(x-1, C, B, A)
        
    printlists()

def printlists():
    print()
    print(l1)
    print(l2)
    print(l3)
    print()


move(4, l1, l2, l3)

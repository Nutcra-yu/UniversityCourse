#判断字符串中的字符类型个数
raw_srt = input("请输入字符串:")

str = []

for x in raw_srt:
    str += x

tag = {'English': 0, 'Num': 0, 'space': 0, 'other': 0}

for x in str:
    if 'a' <= x <= 'z' or 'A' <= x <= 'Z':
        tag['English'] += 1
    elif '0' <= x <= '9':
        tag['Num'] += 1
    elif x == ' ':
        tag['space'] += 1
    else:
        tag['other']+= 1


print(tag)

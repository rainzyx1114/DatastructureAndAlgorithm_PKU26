def cmp(s : str):
    lis = s.split('-')
    modelName = lis[0]
    num = (float)(lis[1][:-1])
    level = 1 if lis[1][-1] == 'B' else 0
    return (modelName, level, num)


n = (int)(input())
models = []
for i in range(n):
    s = input()
    models.append(s)
models.sort(key=cmp)
lastName = ''
for model in models:
    modelName, paraNum = model.split('-')
    if modelName != lastName:
        if lastName != '':
            print('')
        print(modelName + ': ', end='')
        lastName = modelName
    else:
        print(', ', end='')
    print(paraNum, end='')
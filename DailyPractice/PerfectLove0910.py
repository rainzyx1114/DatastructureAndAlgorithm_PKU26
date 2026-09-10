n = int(input())
gifts = list(map(int, input().split()))
sumRecord = {0 : 0}
maxLen = 0
prefixSum = 0
for i in range(1, n + 1):
    prefixSum += gifts[i - 1] - 520
    if (prefixSum in sumRecord):
        maxLen = max(maxLen, i - sumRecord[prefixSum])
    else:
        sumRecord[prefixSum] = i
print(maxLen * 520)
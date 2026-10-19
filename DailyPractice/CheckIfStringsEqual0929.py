class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        length = len(s1)
        if (len(s2) != length):
            return False
        evenSet = {}
        oddSet = {}
        idx = 0
        while (idx < length):
            c = s1[idx]
            if c not in evenSet:
                evenSet[c] = 1
            else:
                evenSet[c] += 1
            idx += 2
        idx = 1
        while (idx < length):
            c = s1[idx]
            if c not in oddSet:
                oddSet[c] = 1
            else: 
                oddSet[c] += 1
            idx += 2
        for i in range(length):
            c = s2[i]
            if i % 2 == 0:
                if c not in evenSet:
                    return False
                else:
                    if evenSet[c] <= 0:
                        return False
                    evenSet[c] -= 1
            else:
                if c not in oddSet:
                    return False
                else:
                    if oddSet[c] <= 0:
                        return False
                    oddSet[c] -= 1
        return True
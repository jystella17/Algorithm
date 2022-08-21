import math
def solution(begin, end):
    result = []
    for i in range(begin, end+1):
        if i < 2:
            result.append(0)
            
        else:
            for j in range(2, int(math.sqrt(i))+1):
                if i % j == 0 and i // j <= 10000000:
                    result.append(i // j)
                    break
                else:
                    result.append(1)
    return result

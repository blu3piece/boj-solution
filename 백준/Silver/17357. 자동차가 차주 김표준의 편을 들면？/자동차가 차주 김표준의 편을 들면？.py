import math

n = int(input())
b = input()
arr = [0]
presum = [0]

for (i, v) in enumerate(b.split(" ")):
    v = int(v)
    i = int(i)
    arr.append(v)
    presum.append(v)
    presum[i+1] += presum[i]
    
for k in range(1, n + 1):
    max_std = 0
    max_place = -1
    for i in range(1, n-k+2):
        mean = presum[i + k-1] - presum[i-1]
        mean /= k
        std = 0
        for j in range(0, k):
            std += (arr[i + j] - mean)**2
        std = math.sqrt(std)
        if max_place == -1 or round(max_std, 12) < round(std, 12):
            max_std = std
            max_place = i
    print(max_place)
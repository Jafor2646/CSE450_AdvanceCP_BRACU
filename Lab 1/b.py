n = int(input())
arr = list(map(int, input().split()))

presum = []
sum = 0
for i in range(n):
    sum += arr[i]
    presum.append(sum)
spresum = []
arr.sort()
sum = 0
for i in range(n):
    sum += arr[i]
    spresum.append(sum)

t = int(input())

for i in range(t):
    t, l, r = list(map(int, input().split()))
    if t == 1:
        if(l == 1):
            print(presum[r-1])
        else:
            print(presum[r-1] - presum[l-2])
    else:
        if(l == 1):
            print(spresum[r-1])
        else:
            print(spresum[r-1] - spresum[l-2])

s = input()
presum = []
count = 0
for i in range(len(s)-1):
    if s[i] == s[i+1]:
        count += 1
    presum.append(count)
t = int(input())
for i in range(t):
    l, r = list(map(int, input().split()))
    if(l == 1):
        print(presum[r-2])
    else:
        print(presum[r-2] - presum[l-2])
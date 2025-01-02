def check(lst, m, k):
  cows = 1
  lastCowPostion = lst[0]
  for i in range(1, len(lst)):
    if(lst[i]-lastCowPostion>=m):
      cows += 1
      lastCowPostion = lst[i]
      if cows >= k:
        return True
  return False
for run in range(int(input())):
  n, c = list(map(int, input().split()))
  arr = []
  for i in range(n):
    arr.append(int(input()))
  low = 0
  high = 10000000000
  ans = 0
  arr.sort()
  while(low <= high):
    mid = (low+high)//2
    if(check(arr, mid, c)):
      ans = mid
      low = mid+1
    else:
      high = mid-1
  print(ans)
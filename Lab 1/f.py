def binarySearch(lst, num, n):
  left = 0
  right = n-1
  while(left <= right):
    mid = (left+right)//2
    if(left == right):
      break
    if lst[mid] <= num:
      left = mid+1
    else:
      right = mid
  if(lst[mid] <= num):
    return mid+1
  return mid

n, m = list(map(int, input().split()))
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
arr1.sort()
for i in arr2:
  ans = binarySearch(arr1, i, n)
  print(ans, end=" ")
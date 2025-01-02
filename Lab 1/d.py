for run in range(int(input())):
  n = int(input())
  arr = list(map(int, input().split()))
  if n == 2:
    t = int(input())
    for i in range(t):
      s, e = list(map(int, input().split()))
      print(1)
  else:
    preCoin = [0]
    idx=1
    for i in range(0, n-1):
      if i == 0:
        preCoin.append(1)
      else:
        if abs(arr[i] - arr[i-1]) > abs(arr[i]-arr[i+1]):
          preCoin.append(preCoin[idx]+1)
        else:
          preCoin.append(preCoin[idx]+abs(arr[i]-arr[i+1]))
        idx += 1
    revPreCoin = [0]*n
    revPreCoin[n-2] = 1
    idx = n-3
    for i in range(n-2, 0, -1):
      if abs(arr[i+1]-arr[i]) > abs(arr[i]-arr[i-1]):
        revPreCoin[idx] = revPreCoin[idx+1]+1
      else:
        revPreCoin[idx] = revPreCoin[idx+1]+abs(arr[i]-arr[i-1])
      idx -= 1
    t = int(input())
    for i in range(t):
      s, e = list(map(int,input().split()))
      if s < e:
        print(preCoin[e-1]-preCoin[s-1])
      else:
        print(abs(revPreCoin[s-1]-revPreCoin[e-1]))
    
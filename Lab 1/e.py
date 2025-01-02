for run in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    pre = [0] *(n+2)
    suf = [0]*(n+2)
    for i in range(n):
        pre[i+1] = max(pre[i],arr[i]+i)
    suf[n+1] = -(10**9)
    for i in range(n-1, -1,-1):
        suf[i+1] = max(suf[i+2], arr[i]-i)
    ans = 0
    for i in range(1,n-1):
        ans = max(ans, pre[i]+suf[i+2]+arr[i])
    print(ans)
      
    
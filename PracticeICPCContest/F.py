import sys
sys.setrecursionlimit(150000)

def dfs(start, end, arr):
    if end-start == 0:
        return arr[end]
    i = -1
    max_val = -1
    # print(start, end)
    for j in range(start, end+1):
        if arr[j] > max_val:
            i = j
            max_val = arr[j]
    val_start = -1
    val_end = -1
    if i == start:
        val_end = dfs(i+1, end, arr)
    elif i == end:
        val_start = dfs(start, i-1, arr)
    else:
        val_start = dfs(start, i-1, arr)
        val_end = dfs(i+1, end, arr)
    # ans = -1
    if val_start == arr[i]:
        ans = val_start*2
        if val_end == ans:
            ans*=2
        return ans
    elif val_end == arr[i]:
        ans = val_end*2
        if val_start == ans:
            ans*=2
        return ans
    elif val_end == val_start:
        ans = val_end*2
        if ans == arr[i]:
            return ans*2
        return max(ans, arr[i])
    return max(val_start, val_end, arr[i])

n = int(input())
arr = []
t = [int(x) for x in input().split()]
print(dfs(0, n-1, t))
# print(t)
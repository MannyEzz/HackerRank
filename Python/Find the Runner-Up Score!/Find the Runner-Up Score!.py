if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    arr = list(arr)
    arr = set(arr)
    max_val = max(arr)
    arr.remove(max_val)
    print(max(arr))
    
    #------another solution---------------
    #arr = sorted(set(arr))
    #print(arr[-2])
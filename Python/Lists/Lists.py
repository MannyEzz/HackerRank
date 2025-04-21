if __name__ == '__main__':
    N = int(input())
    list = []
    for i in range(N):
        list2= input()
        list2 = list2.split()
        
        if list2[0] == "insert":
            list.insert(int(list2[1]),int(list2[2]))
        if list2[0] == "print":
            print(list)
        if list2[0] == "remove":
            list.remove(int(list2[1]))
        if list2[0] == "append":
            list.append(int(list2[1]))
        if list2[0] == "sort":
            list.sort()
        if list2[0] == "pop":
            list.pop()
        if list2[0] == "reverse":
            list.reverse()
            
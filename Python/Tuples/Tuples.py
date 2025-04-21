if __name__ == '__main__':
    n = int(input())
    integer_list = map(int, input().split())
    t = tuple(x for x in integer_list)
    print(hash(t))
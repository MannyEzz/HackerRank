if __name__ == '__main__':
    s = input()
    print (any(alnum.isalnum() for alnum in s))
    print (any(alpha.isalpha() for alpha in s))
    print (any(num.isdigit() for num in s))
    print (any(low.islower() for low in s))
    print (any(up.isupper() for up in s))
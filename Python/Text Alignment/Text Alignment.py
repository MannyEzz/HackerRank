# Enter your code here. Read input from STDIN. Print output to STDOUT
user_input = int(input())

for i in range(user_input):
    print(('H'*i).rjust(user_input-1)+'H'+('H'*i).ljust(user_input-1))

for i in range(user_input+1):  
    print(('H'*user_input).center(user_input*2)+('H'*user_input).center(user_input*6))

for i in range((user_input+1)//2):
    print(('H'*user_input*5).center(user_input*6))    

for i in range(user_input+1): 
    print(('H'*user_input).center(user_input*2)+('H'*user_input).center(user_input*6))    

for i in range(user_input):  
    print((('H'*(user_input-i-1)).rjust(user_input)+'H'+('H'*(user_input-i-1)).ljust(user_input)).rjust(user_input*6))

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    
    temp = 0
    for i in range(3):
        temp = temp + student_marks[query_name][i]
    
    #temp = student_marks[query_name][0]+student_marks[query_name][1]+student_marks[query_name][2]
    #temp = sum(student_marks[query_name])
    print(format(temp/3,".2f"))

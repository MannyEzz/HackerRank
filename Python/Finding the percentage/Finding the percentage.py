if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    
    sum = 0
    for i in range(3):
        sum = sum + student_marks[query_name][i]
    
    #sum = student_marks[query_name][0]+student_marks[query_name][1]+student_marks[query_name][2]
    print(format(sum/3,".2f"))
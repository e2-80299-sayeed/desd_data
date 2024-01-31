#  5)The marks obtained by a student in 3 different subjects are input by the user. 
# Your program should calculate the average of subjects and display the grade. The student gets a grade as per the following rules:
# Average Grade
# 90-100 A
# 80-89 B
# 70-79 C
# 60-69 D
# 0-59 F

eng = int(input("Enter English Marks: "))
math = int(input("Enter Math Marks: "))
sci = int(input("Enter Science Marks: "))
total_marks = eng + math + sci
average_grade = total_marks / 3

if average_grade >= 90 and average_grade <= 100:
        print('A')
elif average_grade >= 80 and average_grade < 90:
        print('B')
elif average_grade >= 70 and average_grade < 80:
        print('C')
elif average_grade >= 60 and average_grade < 70:
        print('D')
else:
        print('F')

print('Total Marks is', total_marks, 'and Average grade is', average_grade)


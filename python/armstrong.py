num = int(input("Enter a number to check if its armstrong or not: "))

def givePower(x,y):
    return x**y


list_num = [int(x) for x in str(num)]
cube_list = [givePower(x,len(str(num))) for x in list_num]

if sum(cube_list) == num:
    print("Given number is an Armstrong number")
else:
    print("Given number is not an Armstrong number")

print("Enter the x coordinate")
x = float(input()) #prompting the x coordinate
print("Enter the y coordinate")
y = float(input()) #prompting the y coordinate

if((x * x + y * y >= 9) and ((0 <= x and x <= 3 and -3 <= y and x <= 3) or (-3 <= x and x <= 0 and -3 <= y and y <= 0))): #cheking for conditions
     
    print("The point belongs to the shaded area") #the point belongs to the shaded area if the above condition is true

else:

    print("The point doesn't belong to the shaded area") #the point doesn't belong to the shaded area if the above condition is false
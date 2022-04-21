import math 
print('Enter the distance to the country house')
a = float(input())
print('Enter the amount of gasoline consumed by the car per 100 km')
b = float(input())
print('Enter the price of one liter of gasoline')
c = float(input())
S = float(2*a*b*c/100)
print('The cost of a trip by car to the country house (back and forth) is ' + str(S))
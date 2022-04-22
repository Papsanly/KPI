import math 
print('Enter the angle to convert in degrees')
B_deg = float(input())
B_rad = float(B_deg * math.pi / 180)
print('This angle in radians is ' + str(B_rad))

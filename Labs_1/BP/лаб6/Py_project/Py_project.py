def init():
    return int(input("Enter the value of n: "))

def browse():
    print(f"Numbers {num1} and {num2} are friendly")

def Sum_divisors(k):
    
    S_div = 0
    
    for div in range(1, int(k / 2 + 1)):
        if (k % div == 0): S_div += div
    
    return S_div

n = init()

for num1 in range(1, n): 
		for num2 in range(num1, n):
			    if ((Sum_divisors(num1) == num2) and (Sum_divisors(num2) == num1)): browse()
            
input()

n = int(input("Enter value of n: "))
S_div_max = 0
max_k = 1
print("\n")

for k in range(1, n + 1):
    
    S_div = 0
    
    for div in range(1, k + 1): 
        
        if (k % div == 0): S_div += div

    print("k = " + str(k) + ": S_div = " + str(S_div))

    if (S_div > S_div_max):

        max_k = k
        S_div_max = S_div

print("\nThe value between 1 and n with maximum sum of divisors is: " + str(max_k))
print("Its sum of divisors is: " + str(S_div_max))
print("\n")
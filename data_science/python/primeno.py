def no_of_primes(n):
    if(n > 1):    
        for i in range(3, n, 2):
            flag = False
            for j in range(3, i, 2):
                if(i % j) == 0:
                    flag = True
                    break
            if flag:
                pass
            else:
                print(f"{i} is a prime number")

no_of_primes(100)
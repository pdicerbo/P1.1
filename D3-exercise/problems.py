
def starting():
    """Allow to choose the number of the problem to solve"""
    num = 1

    options = {1:'multiple', 2:'fibo', 3:'largest'} 
    while num in range(1,3):
        print("\n\tEnter number problem:\n")
        print("\t1. Multiple of 3 and 5\n")
        print("\t2. Even Fibonacci Numbers\n")
        print("\t3. Largest prime factor")
        num = int(input('\n  -->\t'))
        if num in list(options.keys()):
            eval(options[num])()
        else:
            print("\n\tFailed to match problem number\n")

        print("\n"+"="*80 + "\n")
        
    print('\tGoodbye!\n')

def multiple():
    """Calculate the sum of all multiple numbers of 3 and 5 between 0 and 1000"""

    multiples = []
    for j in range(0,1001):
        if j % 3 == 0:
            multiples.append(j)
        elif j % 5 == 0:
            multiples.append(j)
        else:
            pass

    multi_sum = 0
    for j in multiples:
        multi_sum += j

    print('\n\tThe sum result is: ' + str(multi_sum))    
    

def fibo():
    """Calculate the sum of the even terms of the Fibonacci series that don't exceed 4.e6"""

    fibo_series = [1, 2]
    j = 2; n_term = 3; n_minus_one_term = 2

    while n_term < 4e6:
        fibo_series.append(n_term)
        n_temp = n_term
        n_term += n_minus_one_term
        n_minus_one_term = n_temp

    fibo_series.append(n_term)
    print(fibo_series)
    fibo_sum = 0
    for term in fibo_series:
        if term % 2 == 0:
            fibo_sum += term
        else:
            pass
    
    print('\n\tThe sum result is: ' + str(fibo_sum))    
    
def largest():
    """Calculate the largest prime factor of a given number"""
    number = 600851475143
    prime_factor = [1,]
    pf = 2

    while pf < number:
        if number % pf == 0:
            ctrl = 0
            """I need to do this control in order to don't 
            take multiples of prime factors already teaken"""
            if len(prime_factor) > 1:
                for prime_num in prime_factor:
                    if pf % prime_num == 0:
                        ctrl += 1
            if ctrl == 0:
                prime_factor.append(pf)
        else:
            pass
        pf += 1

    print("\n\tThe largest prime factor of "+str(number)+ " is "+ str(prime_factor[-1]))
        
    
starting()

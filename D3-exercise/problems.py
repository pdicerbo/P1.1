def starting():
    """Allow to choose the number of the problem to solve"""
    num = 1

    options = {1:'multiple', 2:'fibo', 3:'largest', 4:'collatz'} 
    while num in range(1,5):
        print("\n\tEnter number problem:\n")
        print("\t1. Multiple of 3 and 5\n")
        print("\t2. Even Fibonacci Numbers\n")
        print("\t3. Largest prime factor\n")
        print("\t4. Collatz sequence\n")
        print("\tAny other to exit\n")
        num = int(input('  -->\t'))
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
    original_number = 600851475143
    prime_factor = []
    pf = 2

    while pf <= number:
        if number % pf == 0:
            ctrl = 0
            """I need to do this control in order to don't 
            take multiples of prime factors already teaken"""
            for prime_num in prime_factor:
                if pf % prime_num == 0:
                    print(prime_num, pf)
                    ctrl += 1
                    break
            if ctrl == 0:
                prime_factor.append(pf)
                print("\tFind this prime factor: %d" % pf)
                number /= pf
        else:
            pass
        pf += 1

    print("\n\tThe largest prime factor of "+str(original_number)+ " is "+ str(prime_factor[-1]) + ";")
    print("\n\tControl:\n")
    prod_ctrl = 1
    for ctrl in prime_factor:
        prod_ctrl *= ctrl
        print("\t%d\t%d\n"%(prod_ctrl, ctrl))
        
def collatz():
    """Find the number that generate the longest collatz sequence"""
    max_seed = 2; longest = 0;
    seed = 2; tmp_count = 0

    while seed < 1e6:
        tmp_count = gen_coll(seed, tmp_count)
        
        if tmp_count > longest:
            max_seed = seed
            longest = tmp_count
        seed += 1
        tmp_count = 0
        
    print("\n\tThe number that generate the longest collatz sequence is %d\n"%max_seed)
    print("\tThe sequence have %d step\n"%longest)
    
def gen_coll(el, count):
    """Return the lenght of the collatz sequence starting from el"""
    if el == 1:
        count += 1
        return count
    elif el % 2 == 0:
        count += 1
        return gen_coll(el/2, count)
    else:
        count += 1
        return gen_coll(3*el + 1, count)

starting()

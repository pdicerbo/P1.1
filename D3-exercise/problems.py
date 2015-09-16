
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
    
starting()

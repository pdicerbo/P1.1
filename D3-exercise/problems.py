
def starting():
    """This function allow to choose the number of the problem to solve"""
    num = 1

    options = {1:'multiple', 2:'fibo', 3:'largest'} 
    while num in range(1,3):
        print("\n\tEnter number problem:\n")
        print("\t1. Multiple of 3 and 5\n")
        print("\t2.Even Fibonacci Numbers\n")
        print("\t3.Largest prime factor")
        num = input('-->')
        if num in options.keys():
            eval(options[num])

    print('\tGoodbye\n')

def multiple():
    """This function calculate the sum of all multiple numbers of 3 and 5 between 0 and 1000"""

    
starting()

import math
def main():
    x=int(raw_input())
    ans=1
    while x>0:
        ans=ans*math.factorial(x)%109546051211
        x=x-1
    print ans
    raw_input() 

main()

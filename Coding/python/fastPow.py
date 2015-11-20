def fastPow(a,b):
    result=1
    while b:
        if(b&1):
            result=(result*a)%1000000007
        a=a*a%1000000007
        b>>=1
    return result%1000000007

def main():
    t=raw_input()
    t=int(t)
    while(t):
        a=raw_input().split()      
        print(fastPow(int(a[0]),int(a[1])))
        t-=1
         
main()

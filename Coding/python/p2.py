def  z(n):
    r = 0
    for i in range(5, n+1, 5):
        while i%5 == 0:
            r += 1
            i = i / 5
    return r

def f(n):
    f2=f5=z(n)
    r = 1
    for i in range(1,n+1):
        while f2 > 0 and (i&1)== 0:
            f2 -= 1
            i >>= 1
        while f5 > 0 and i%5== 0:
            f5 -= 1
            i /= 5
        r = (i*r)%10
    return r

def main():
    x=sys.stdin.readline()
    while x>0:
        x=x-1
        k=int(raw_input())
        print f(k)
    raw_input() 
main()

#!/usr/bin/env python

#import sys 
#sys.path.append("./sympy-1.4/")
#sys.path.append("./mpmath-1.1.0/")

#from functools import reduce
#
#from sympy import factorint, lcm
#
#def A001175(n):
#
#    if n == 1:
#
#        return 1
#
#    f = factorint(n)
#
#    if len(f) > 1:
#
#        return reduce(lcm, (A001175(a**f[a]) for a in f))
#
#    else:
#
#        k, x = 1, [1, 1]
#
#        while x != [0, 1]:
#
#            k += 1
#
#            x = [x[1], (x[0]+x[1]) % n]
#
#        return k

k = input() 
m = input()

b = k #% A001175(m)

def pow(n):
    x=[1,1,1,0]
    s=[1,1,1,0]
    while (n>0):
        if(n&1):
            s[0],s[1],s[2],s[3]=(s[0]*x[0]+s[1]*x[2])%m,(s[0]*x[1]+s[1]*x[3])%m,(s[2]*x[0]+s[3]*x[2])%m,(s[2]*x[1]+s[3]*x[3])%m
        x[0],x[1],x[2],x[3]=(x[0]*x[0]+x[1]*x[2])%m,(x[0]*x[1]+x[1]*x[3])%m,(x[2]*x[0]+x[3]*x[2])%m,(x[2]*x[1]+x[3]*x[3])%m
        n=n>>1
    return s[3]
    
t = pow(int(b))

print t

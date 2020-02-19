# -*- coding: utf-8 -*-
import math
c=0

def KaratSuba(a,b):
    l=max(len(a), len(b))
    while(not isPowerOf2(l)):
        l+=1
    return(multiply(int(a), int(b), l))

def multiply(a, b, n):
    if(n==1):
        global c
        c+=1
        return (a*b)
    else:
        n2=int(n/2)
        m=pow(10,n2)
        x=a%m
        w=a//m
        z=b%m
        y=b//m
        p=multiply(w,y,n2)
        q=multiply(x,z,n2)
        r=multiply((w+x), (y+z), n2)
        return (pow(10,n)*p + m*(r-p-q) + q)
    
def isPowerOf2(n):
    ln=math.log10(n)/math.log10(2)
    return(math.ceil(ln)==math.floor(ln))
   
a=input("a: ")
b=input("b: ")
print('Karat Suba: ', KaratSuba(a,b))
print('No. of multiplications: ', c)
print('normally: ', int(a)*int(b))
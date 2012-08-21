import os

def divBy3(num):
    Sum = 0
    while(num > 3):
       Sum = Sum + (num >> 2)
       num = (num >> 2) + (num & 3)
    if (num == 3):
       Sum = Sum + 1
       num = 0
    return Sum,num

n = int(raw_input("enter a number"))
print "Result=%d Remainder=%d" % divBy3(n)

import fib,sys
print(fib.fib1(1000))
print(fib.fib2(1000))
print(fib.__name__)
print(type(fib))

#intro to the use of from __ import and 
#from __ import *
''' the use of " from __ import * (that can import all function to main program)"'''
from fib import fib1
print(fib1(500))
from fib import fib2
print(fib2(500))
print(dir(fib))
print(dir(sys))
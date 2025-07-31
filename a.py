x = 0
for i in range(10000):
    x += i
print(x)

class A:
    pass

class B:
    pass

a = A()
a.__class__ = B
b = A()
b.__class__ = B
c = A()
c.__class__ = B
d = A()
d.__class__ = B
e = A()
e.__class__ = B

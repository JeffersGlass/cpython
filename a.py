y = 1

def foo(x):
    return x + y

def bar(z):
    return foo(z) + foo(z + 1)

if __name__ == "__main__":
    w = 0
    for i in range(1000):
        w+=(bar(foo(i)))
        for j in range(50):
            z+= w - 50
    print(w)
    print(z)
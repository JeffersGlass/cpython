import os
import time
x = 0
while True:
    x += 1
    print(f"{os.getpid()} : {x}")
    time.sleep(1)

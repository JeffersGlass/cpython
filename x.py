import os
import sys
import time

x = 0
while True:
    x += 1
    print(f"{x: <4} : {os.getpid()}")
    #sys.stdout.flush()
    time.sleep(1)
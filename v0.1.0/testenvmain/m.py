import os
from time import time

start = time()
list1 = os.walk("/home/draco/")
end = time()

print(end - start)

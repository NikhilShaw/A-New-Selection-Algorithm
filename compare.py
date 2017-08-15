# compare quickselect, comparison algorithm and insertion sort

import numpy as np
import time
from random import randrange
import matplotlib.pyplot as plt
def my(arr, k):
	size_arr=len(arr)
	small_limit = k-1
	large_limit = size_arr-k
	window_Ulim = float('inf')
	window_Llim = float('inf')*-1
	for i in range(size_arr):
		small_count =0
		large_count =0
		# if its last element
		if(i==size_arr-1):
			return arr[i] 
			break
		# element doesn't lie in the window
		elif(arr[i]>window_Ulim):
			large_limit-=1
			continue
		elif(arr[i]<window_Llim):
			small_limit-=1
			continue
		#check if its the kth element by comparison with each element occuring after arr[i]
		else:
			for j in range(i+1, size_arr):
				if(arr[j]<arr[i]):
					small_count+=1
				else:
					large_count+=1

				if(small_count>small_limit):
					large_limit-=1
					window_Ulim= arr[i]
					break
				elif(large_count>large_limit):
					small_limit-=1
					window_Llim = arr[i]
					break
				else:
					pass

			#if the element is the kth element
			if((small_limit==small_count) and (large_limit==large_count)):
				return arr[i]
				break

#### Quick select algorithm

def partition(x, pivot_index = 0):
    i = 0
    if pivot_index !=0: x[0],x[pivot_index] = x[pivot_index],x[0]
    for j in range(len(x)-1):
        if x[j+1] < x[0]:
            x[j+1],x[i+1] = x[i+1],x[j+1]
            i += 1
    x[0],x[i] = x[i],x[0]
    return x,i

def RSelect(x,k):
    if len(x) == 1:
        return x[0]
    else:
        xpart = partition(x,randrange(len(x)))
        x = xpart[0] # partitioned array
        j = xpart[1] # pivot index
        if j == k:
            return x[j]
        elif j > k:
            return RSelect(x[:j],k)
        else:
            k = k - j - 1
            return RSelect(x[(j+1):], k)
## insertion sort
def insertionSort(alist, k):
   for index in range(1,len(alist)):
     currentvalue = alist[index]
     position = index
     while position>0 and alist[position-1]>currentvalue:
         alist[position]=alist[position-1]
         position = position-1
     alist[position]=currentvalue
   return alist[k]


size_arr=3000
x1=np.array([])
x=np.array([])
x2=np.array([])
y=np.arange(1,size_arr+1, 10)
for i in range(1, size_arr+1, 10):
	arr = np.random.random_integers(10000, size=(i))
	k=0
	start=time.time()
	j=my(arr, k)
	end=time.time()
	x1=np.insert(x1, len(x1), end-start)
	start=time.time()
	insertionSort(arr, k)
	end=time.time()
	x2=np.insert(x2, len(x2), end-start)
	start=time.time()
	RSelect(arr,k)
	end=time.time()
	x=np.insert(x, len(x), end-start)
	print i
plt.plot(y, x1, '-b', y, x, '-r', y, x2, '-g')
plt.show()

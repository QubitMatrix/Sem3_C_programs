n=int(input())
arr=[]
count=0
count1=0
def mergesort(arr):
    global count
    count+=1
    if(len(arr)<2):
        return arr
    else:
        mid=len(arr)//2
        return merge(mergesort(arr[:mid]),mergesort(arr[mid:]))
def merge(arr1,arr2):
    global count
   
    count+=1
    res=[]
    l1=l2=0
    while(l1<len(arr1) and  l2<len(arr2)):
        if(arr1[l1]<arr2[l2]):
            res.append(arr1[l1])
            l1+=1
        else:
            res.append(arr2[l2])
            l2+=1
    return res+arr1[l1:]+arr2[l2:]

for x in range(n):
    arr.append(int(input()))
arr1=arr.copy()
print("Merge sort:\nArray:",arr,"\nSorted:",mergesort(arr),"\nTime complexity:",count,"(~O(nlogn))\n")

def bubblesort(arr):
    global count
    global count1
    for x in range(0,n-1):
            for y in range(x+1,n):
                count+=1
                if(arr[y]<arr[x]):
                    count1+=1
                    arr[x],arr[y]=arr[y],arr[x]
    return arr
count=0
#arr1=arr
print(arr1,arr)
print("Bubble sort:\nArray:",arr)
print("Sorted:",bubblesort(arr),"\nTime complexity:",count,"(comparisons)",count1,"(swaps)\n")
def selectionsort(arr):
    global count
    global count1
    minv=0
    count1=0
    for x in range(0,n-1):
        minv=x
        for y in range(x+1,n):
            count+=1
            if(arr[y]<arr[minv]):
                minv=y
        if(x!=minv):
            count1+=1
            arr[x],arr[minv]=arr[minv],arr[x]
    return arr
count=0

print("Selection sort:\nArray:",arr1)
print("Sorted:",selectionsort(arr1),"\nTime complexity:",count,"(comparisons)",count1,"(swaps)")


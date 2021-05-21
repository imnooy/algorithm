def binary(n):
    arr.append(n%2)
    
    if (int(n/2))==0:
        return
    else:
        binary(int(n/2))



arr=[]
n=int(input())
binary(n)

arr.reverse()

for x in arr:
    print(x, end="")

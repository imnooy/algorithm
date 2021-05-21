def hanoi(n, a, b):
    if n==1:
        print(a, b, sep=" ")

    else:
        hanoi(n-1, a, 6-a-b)
        hanoi(1, a, b)
        hanoi(n-1, 6-a-b, b)

n=int(input())

if n>20:
    print(pow(2, n)-1)
else:
    print(pow(2, n)-1)
    hanoi(n, 1, 3)

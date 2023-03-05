n = int(input())
a = input().split(' ')
b = input().split(' ')
a = [int(i) for i in a]
b = [int(i) for i in b]

a.sort()
b.sort(reverse=True)

MAX = 0 
MIN = 10000000000 

for i in range(0 , n) :
    sum = a[i] + b[i] 
    MAX = max(MAX , sum) 
    MIN = min(MIN , sum) 

print(MAX - MIN) 
    

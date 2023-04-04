import io, os, time

def fast_io():
    
    input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
  
    # Taking input as string 
    n = int(input().decode())
    a = input().decode().split(' ')
    b = input().decode().split(' ')
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
  
# Driver Code
if __name__ == "__main__":
  
    fast_io()
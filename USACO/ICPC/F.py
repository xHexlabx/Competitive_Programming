n = int(input())

mem = dict()

for i in range(n) :
    
    found = False 
    
    q = int(input())
    
    for j in range(q) :
        
        s = input()
        
        if ('bie' in s) and (s not in mem.keys() ) :
            
            found = True
            mem[s] = True
            
            print(s)
    
    if found == False :
        
        print("Time to play Genshin Impact, Teacher Rice!")
            
            
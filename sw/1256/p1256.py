tc = int(input())

for i in range(tc) : 
    k = int(input())
    word = input()
    l = []
    for j in range(len(word)) : 
        l.append(word[j:])
    l.sort()
    print("#"+str(i+1) +" " + str(l[k-1]))
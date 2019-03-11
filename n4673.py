def d(a):
    t = a
    r = t
    while t > 0:
        r += t % 10
        t //= 10
    return r


arr_full = []
arr_d = []
n = 1
f = 1
while f <=10000 :
    f = d(n)
    print(str(n) + " "+ str(f))
    n += 1
    arr_d.append(f)

for i in range(1,10001):
    arr_full.append(i)

for i in range(0,arr_d.__len__()) :
    if arr_full.__contains__(arr_d[i]) :
      arr_full.remove(arr_d[i])
for i in range(0,arr_full.__len__()) :
    print(arr_full[i])


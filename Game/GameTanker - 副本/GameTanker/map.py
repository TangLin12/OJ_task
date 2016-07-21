map=[[0 for i in range(20)] for i in range(15)]
map[2]=[1 for i in range(20)]

f=open("map1.txt","wb")
for nodeLine in map:
    for node in nodeLine:
        f.write("%d,"%node)
    f.write("\n")
f.close()

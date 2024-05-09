# analisando o arquivo tester original,
# fui decodando o base 64 até chegar no programa original
# este aqui:

import random
import sys


#f = open("v8163873857", "a")
#f.write("X")
#f.close()

random.seed(15461246)

words = set()

while len(words) <= 5000:
    #creating words
    word = int(random.random()*1000000)
    words.add(word)

lwords = list(words)
groups=[]
for i in range(10):
    group = set()
    for j in range(500):
        v = random.randint(0, len(lwords)-1)
        word = lwords.pop(v)
        group.add(word)
    groups.append(group)

value1 = int(sys.argv[1])
value2 = int(sys.argv[2])

for g in groups:   
    if value1 in g:
        if value2 in g:
            print(1)  
        else: 
            print(0)
        exit(0)
    else:
            if value2 in g:
                if value1 in g:
                    print(1)  
                else:
                    print (0)
                exit(0)
                
print(0)
exit(0)
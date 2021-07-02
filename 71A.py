value = input()
value = int(value)
mylist = []
for x in range(value):
    word = input()
    mylist.append(word)
 
for val in mylist:
    if len(val) > 10:
        apperivation = val[0]+       str(len(val)-2)       +val[-1]
        print(apperivation)
    else:
        print(val)
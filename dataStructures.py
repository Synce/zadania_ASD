


# zadanie 1.28
# tablica wypelniona zerami,  i stos
n= 10 # ilosc elemntow
a=[0] * n
b=[] # stos


def Insert(i):
    if a[i]==0:
        a[i]=1
        b.append(i)

def Select():
    x = b.pop()
    a[x]=0
    return x

def Search(i):
    if a[i]==0:
        return  False
    return  True




# zadanie 1.29

# tak jak w poprzednim zadaniu
# tablica wypelniona zerami,  i stos
n= 10 # ilosc elemntow
a=[0] * n
b=[] # stos

def Push(i):
    if a[i]==0:
        a[i]=1
        b.append(i)

def Pop(i):
    x = b.pop()
    while a[x]==0 or len(b)==0:   #szukamy elemntu ktory jest w zbiorze, jezeli a[x] jest rowne 0 oznacza ze dany elemnt byl wczeniej usuniety za pomoca delete i musimy znalezc kolejny
         x = b.pop()

    if a[x]!=0:
        a[x]=0
        return x

def Delete(i):
      a[i] = 0


def Search2(i):
    if a[i]==0:
        return  False
    return  True



# zadanie 1.30
 # 2 tablice i  zmienna
data= []
minIndex = [] # tablica  majaca dokladnie tyle samo elementow co tablica z datą, tylko w niej umieszczamy obecny index najnioznszego elemenetu po kazdym pushu nowego
w=0 # index konca tablicy

def push(x):
    global w
    if w>0:
        minimum = data[w]
    else:
        minimum=0
    if x>=minimum:
            minIndex[w+1]=minIndex[w]
            data[w+1]=x

    else:
        minIndex[w+1]=w+1
        data[w+1]=x
    w = w + 1

def uptomin():
    global  w
    x = minIndex[w]
    w=x-1


def pop():
    global w
    x = data[w]
    w=w-1
    return x

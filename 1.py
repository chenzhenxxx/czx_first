n=int(input())
x={}
while n>0 :
    g=input()
    s=g.split(' ')
    for i in range (1,int(s[0])+1):
        x[s[i]]=1
    print(len(x))
    tmp=sorted(x.keys())
    print(*tmp)
    n=n-1
    
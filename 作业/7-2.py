x=input()
try:
    y=eval(x)
    z={}
    for i in y.keys():
        z[y[i]]=i
    print(z)
except:
    print("输入错误")

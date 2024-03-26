P=lambda s:print((' '*500+s)[-l:])
for _ in[0]*int(input()):
    s=input()
    for j in'+-*':
        if j in s:
            break
    p,q=s.split(j)
    e=eval(s)
    l=max(len(p),len(q)+1,len(str(e)))
    P(p)
    P(j+q)
    if j=='*':
        pad=l
        if len(q)!=1:
            P('-'*max(len(q)+1,len(str(int(p)*int(q[-1])))))
            for i in q[::-1]:
                P(str(int(i)*int(p)))
                l-=1
        l=pad
        P('-'*len(str(e)))
        P(str(e))
            
    else:
        P('-'*max(len(q)+1,len(str(e))))
        P(str(e))
    print()
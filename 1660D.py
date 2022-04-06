import io
import os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
def rdvec():
  return [int(i) for i in input().split()]
def rd():
  return int(input())
T=int(input())
def solve():
  n=int(input())
  a=[0]+rdvec()
  _,_e_,wh,s,l,r,tg=0,1,1,0,1,0,0
  for i in range(1,n+1):
    if a[i]==0:
      tg=1
    if abs(a[i])==2:
      _+=1
    if a[i]<0:
      _e_=-_e_
    if _*_e_>s and tg==0:
      s,c,l,r=_*_e_,i,wh,i
    elif tg==1:
      wh,_,_e_,tg=i+1,0,1,0
  _,wh,_e_,tg=0,n,1,0
  for i in range(n,0,-1):
    if a[i]==0:
      tg=1
    if abs(a[i])==2:
      _+=1
    if a[i]<0:
      _e_=-_e_
    if _*_e_>s and tg==0:
      s,c,l,r=_*_e_,i,i,wh
    elif tg==1:
      wh,_,_e_,tg=i-1,0,1,0
  print(l-1,n-r)
for o in range(T):
  solve()
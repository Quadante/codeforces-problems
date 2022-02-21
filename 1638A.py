for s in[*open(0)][2::2]:
 a=[0,*map(int,s.split()),0];i=1
 while a[i]==i:i+=1
 if a[i]:j=a.index(i)+1;a[i:j]=a[i:j][::-1]
 print(*a[1:-1])
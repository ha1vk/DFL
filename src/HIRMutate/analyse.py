#coding:utf8

f = open('1.txt','r')
content = f.read()
f.close()

lines = content.split('\n')

a = {}
b = {}

for line in lines:
   if '(' not in line:
      continue
   if line.startswith('~'):
      if line not in b:
         b[line] = 0
      b[line] += 1
   else:
      if line not in a:
         a[line] = 0
      a[line] += 1

for x in a:
   y = '~' + x
   if y not in b or b[y] != a[x]:
      print x

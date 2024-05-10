from itertools import chain

class A:
    def __init__(self, name):
        self.children = []
        self.name = name;

    def add_child(self, index,child):
        self.children.insert(index, child)

    def __iter__(self):
        yield self
        for elem in chain(*map(iter, self.children)):
            yield elem
    def elements(self):
        return list(chain(*self.children))
    def add_child(self):
      print("A");


class B(A):
   def __init__(self):
      pass
   def add_child(self):
      print("B");

class C(B):
   def fun(self):
      super().add_child()

a = A("a")
b = A("b");
c = A("c");
d = A("d");
e = A("e");
f = A("f");

def f1():
   print("f1")
   return True

def f2():
   print("f2")
   return True
#a.add_child(0,b);
#a.add_child(1,f);
#b.add_child(0,c);
#c.add_child(0,d);
#c.add_child(0,e);
#f.add_child(0,A("x"))

ok = f1()
ok = ok or f2()

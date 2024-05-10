#coding:utf8
import re

f = open('../include/value/svg_val.h','r')
content = f.read()
f.close()

classes = re.findall(r'class (.*?):',content,re.S|re.M)

template = '''void *HIRMutate::SVG::{}::getConstructor()
{{
    return HANDLE_VOID({});
}}'''
for clazz in classes:
   clazz = clazz.strip()
   inst = template.format(clazz,clazz)
   print inst

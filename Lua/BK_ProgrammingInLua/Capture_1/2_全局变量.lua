--[[ error
a
print(a)
--]]

b=10
print(b)

c=20
print(c)

--当吧nil赋值给全局变量后，Lua将自动回收该全局变量
c=nil
print(c)
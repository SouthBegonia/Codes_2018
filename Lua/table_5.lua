--[[垃圾回收--]]
mytable = {}
mytable[1] = "Lua"
mytable[1] = nil
mytable = nil

--[[表的别名--]]
mytable = {}
print("type of mytable :",type(mytable))
mytable[1] = "Lua"
mytable["name"] = "South"
newtable = mytable	--指向同样的内存区域(类似指针的别名)
print("type of newtable :",type(newtable))
print(mytable[1],newtable[1])
newtable[2] = "Java"		--关联修改
print(mytable[2],newtable[2])
print()

--仅消除关联表的一个不影响另一个
mytable = nil
print(newtable.name)
newtable = nil		--消除完全
print(type(newtable),type(mytable))
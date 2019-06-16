--[[元表
自定义对表的一些操作--]]

--定义一种方式用print(a)打印表内的元素

--[[创建普通表和元表--]]
mytable = {"Lua","C++","Java","Python"}	--普通表
mymetatable = {}	--元表

--[[把普通表设置为元表，返还被设置元表后的表--]]
--此外如果元表中存在__metatable键值，setmetatable会失败
mytable = setmetatable(mytable,mymetatable)	--mymetatable 是 mytable 的元表
print(mytable[3])

--[[得到元表--]]
print(getmetatable(mytable))
print(mymetatable)
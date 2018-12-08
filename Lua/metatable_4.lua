--  __index用来处理访问到的索引不存在的时
mytable = {"Lua","Java","Python","C++"}
mymetatable = {
	__index = function(tab,key)		--参数为表和键
		--print(tab) 即为mytable
		print("调用了 __index 方法" .. key)
		if(key >= 10)	then
			return "javascript"
		end
end
}

mytable = setmetatable(mytable,mymetatable)

--print(mytable)

--访问表内存在的键
print(mytable[1])

--当访问表内一个没有值的键时，返回nil，也可以设置返回值给这个键
print(mytable[10])
print()


my2table = {"South","Begonia","Github","Unity"}	--普通表

newtable = {}	--新建的表
newtable[7] = "Heaven"
newtable[8] = "Truth"
newtable[9] = "Wind"

my2metatable = {		--元表
	__index = newtable		-- __index 可为函数或者表
}

my2metatable = setmetatable(my2table,my2metatable)

print(my2table)
print(newtable)
print(my2metatable)

print(my2table[1])
print(my2table[9])

--搜索机制：先在my2table表里面寻找键10，如果没数值，则从 __index里面找，而此时__index 为表newtable，即从它里面找
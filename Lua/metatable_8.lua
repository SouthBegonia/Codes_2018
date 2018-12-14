--[[ __index元方法事例--]]
mytable = setmetatable({key1 = "value1"},{
	__index = function ( mytable,key )
		if key == "key2"	then
			return "metatablevalue"
		else
			return nil
		end
	end
	})
print(mytable.key1,mytable.key2)
print()


--[[ __newindex元方法事例--]]
mymetatable2 = {}
mytable2 = setmetatable({key1 = "value1"},{
	__newindex = mymetatable2
	})
print(mytable2.key1)

mytable2.newkey = "新值1"
print(mytable2.newkey, mymetatable2.newkey)	--在给新键赋值时(mytable2.newkey=...)会调用__newindex，但不进行赋值
mytable2.key1 = "新值2"
print(mytable2.key1, mymetatable2.key1)	--给已有键赋值则不调用__newindex

mytable3 = setmetatable({key1 = "value1"},{
	__newindex = function ( mytable, key, value )
		rawset(mytable, key, "\"" .. value .. "\"")	--rawset函数更新表
	end
	} )
mytable3.key1 = "new value"
mytable3.key2 = 12
print(mytable3.key1, mytable3.key2)
print()


--[[给表添加操作符  两表相加--]]
function table_maxn( tab )	--计算表的元素个数
	local mn = 0
	for k,v in pairs(tab)	do
		if mn< k then
			mn = k
		end
	end
	return mn
end

mytable4 = setmetatable({3,5,7},{
	__add = function ( mytable, newtable )
		for i = 1, table_maxn(newtable)	do
			table.insert(mytable, table_maxn(mytable)+1, newtable[i])
		end
		return mytable
	end
	})
secondtable = {9,11,13}
mytable4 = mytable4 + secondtable
for k,v in pairs(mytable4)	do
	print(k,v)
end
print()


--[[__call元方法事例--]]
--一步创建元表时除了元方法外还需有另外的元素
mytable5 = setmetatable({10,20},{
	__call = function ( mytable, newtable )
		sum = 0
		for i=1, table_maxn(mytable)	do
			sum = sum + mytable[i]
		end
		for i=1, table_maxn(newtable) do
			sum = sum + newtable[i]
		end
		return sum
	end
	})
newtable2 = {30,40,50}
print(mytable5(newtable2))
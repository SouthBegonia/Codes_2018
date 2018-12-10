--[[ __newindex
当修改表里一个新的索引(即给表添加新key时,并非修改原有的索引)时才调用 __newindex
--]]

mytable = {"Lua","Java","C++","Python"}
mymetatable = {
	__newindex = function ( tab,key,value )		--要修改的 key 与 value
		print("要修改的 key 为：" .. key .. "把这个 key 的值修改为：" .. value)
		rawset(tab,key,value)	--更新表，若缺失则mytable[5]未赋值，未 为 nil
	end
}
mytable = setmetatable(mytable,mymetatable)
mytable[1] = "Csharp"
mytable[5] = "PHP"		--进行 __newindex 处理，需手动更新表(进行mytable[5]的赋值)

print(mytable[5])
print()


-- __newindex 跟一个表 newtable 时
mytable2 = {"Lua","Javascript","Python","C"}
newtable = {}
mymetatable2 = {
	__newindex = newtable
	--此处 __newindex 不是跟函数故不需要 rawset(tab,key,value)
}
mymetatable2 = setmetatable(mytable2,mymetatable2)

mytable2[1] = "Csharp"
mytable2[5] = "Go"

print(mytable2[1])
print(mytable2[5])		--修改后的key 与value 设置在了 newtable 里而不是 mytable2 里
print(newtable[5])
--[[表的排序
table.sort(table)
--]]
mytable = {"Jack","Ada","Lee","alex"}	--元素字符的表的排序
print("排序前：")
for i,v in ipairs(mytable)	do
	print(i,v)
end
table.sort(mytable)		--升排序，大写在前(符合ASCII)
print("排序后：")
for i,v in ipairs(mytable)	do
	print(i,v)
end
print()


--[[求表内最值
maxn(table)	--已弃用
mymaxn(table) --自建求最值函数
--]]
numbertable = {10,98,45,32,68,54,68,2,6}
--print(table.maxn(numbertable))		--返回最大值的key值。Lua 5.2后删除了该用法
function mymaxn( tab )
	local mn  = 0
	local tag = 0
	for i,v in ipairs(tab)	do
		if(mn < v)		then
			mn = v
			tag = i
		end
	end
	return mn,tag
end
print("length of table  =",#numbertable)
print("max and tag :",mymaxn(numbertable))
table.sort(numbertable)		--元素为数字的表的排序
print("After sorting, max and tag :",mymaxn(numbertable))
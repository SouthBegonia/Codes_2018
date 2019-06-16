--[[--]]
table1 = {key1= "South",key2 = "Begonia"}
print(table1.key1,table1.key2,table1.key3)
table1.key1 = "A"		-- 表内元素的修改
print(table1.key1,table1.key2,table1.key3)
table1.key3 = "!"			--向表内添加新元素
print(table1.key1,table1.key2,table1.key3)
print()


table2 = {"One","Two","Three","Four","Five"}
table2[2] = nil			--删除表的元素
table2[100] = "hundred"		--添加新元素
for key,val in pairs(table2) do
	print(key .. ":" .. val)
end
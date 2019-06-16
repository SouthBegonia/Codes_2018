--[[数值运算符
+ - * / ^ -(负号)  --]]


--[[关系运算符
== ~= > < >= <=  --]]
a = 10
b = 20
print(a ~= b)	-- a 不等于 b 为真
print("----------------------------")

--[[逻辑运算符
and or not  --]]
a = true
b = false
print("not a = ",not a ,"not b = ",not b)		--不可用 .. 连接
print("----------------------------")


--[[关于 #读取表的长度 --]]
table = {1,2,3,4,5}	--初始化新表(规范化)
print("table =",table[1],table[2],table[3],table[4],table[5])
print("Length of table = ",#table)	--正确取得长度
table = nil
print("----------------------------")

table = {key3 = "Value3", key4 = "Value4"}		--初始化新表(不规范)
table.key1 = 1
table.key2 = "something"
print("table = ",table.key1,table.key2,table.key3,table.key4)
print("length of table = ",#table)
print("----------------------------")

table[1],table[2],table[3],table[4] = 10,20,30,"hi"		--非初始化新表，而是对上表的赋值，故上面代码不可 table = nil
for i,v in ipairs(table) do		--为何此处 pairs 仅打印前3个元素
	print(i,v)
end
print("length of table = ",#table)
table = nil
print("----------------------------")

table = {}
table[2] = 2
table[5] = 5
print("table = ",table[1],table[2],table[3],table[4],table[5])		--非一定顺序的表
print("length of table =",#table)

-- 结论：只有在表的索引为一定顺序的实数时才可进行长度统计
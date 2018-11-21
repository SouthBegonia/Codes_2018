--[[表内索引为字符串时忽略双引号--]]
table1 = {key1 = "hello",key2 = "world"}
print(table1.key1,table1.key2)			--第一种读取
print(table1["key1"],table1["key2"])	--第二种读取
print(table1[1],table1[2])		--错误格式
print()


-- 表的索引可为数字类型，其赋值和读取写法类似C数组
table2 = {}
table2[1], table2[2] = 10, 20
print(table2[1],table2[2])		--第三种读取
table3 = {"table3","hello","world"}
print(table3[1],table3[2],table3[3])
print(table3["1"],table3["2"],table3["3"])		-- 错误格式
print()


--[[表的遍历--]]
for key,val in pairs(table3) do
	print(key .. ":" .. val)
end
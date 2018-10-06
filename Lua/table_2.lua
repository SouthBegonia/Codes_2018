-- table 是 Lua 的一种数据结构用来帮助我们创建不同的数据类型，如：数组、字典等


-- 初始化表
mytable = {}
-- 指定值
mytable[1] = "Lua"
-- 移除引用
mytable = nil
-- Lua 垃圾回收会释放内存


-- 简单的table
mytable  = {}
-- print("mytable 是：",mytable)
print("mytable 的类型是：",type(mytable))
mytable[1] = "Lua"
mytable["Hello"] = "修改前"
print("mytable 索引为 1 的元素是：",mytable[1])
print("mytable 索引为 Hello 的元素是：",mytable["Hello"])
print()


-- alternatetable 和 mytable 指向同一个table
alternatetable = mytable
print("alternatetable 索引为 1 的元素是：",alternatetable[1])
print("mytable 索引为 Hello 的元素是：",alternatetable["Hello"])
alternatetable["Hello"] = "修改后"
print("mytable 索引为 Hello 的元素是：",mytable["Hello"])
print()


-- 释放变量
alternatetable = nil
print("alternatetable 是：",alternatetable)
-- 不影响 mytable 的访问
print("mytable 索引为 Hello 的元素是：",mytable["Hello"])
-- 释放 mytable
mytable  = nil
print("mytable 是：",mytable)
print()



-- 几种Table操作方法

-- Table 连接
-- table.concat (table [, sep [, start [, end]]])
fruits = {"apple","orange","banana"}
print("连接后的字符串",table.concat(fruits))		--连接字符串内所有字符
print("连接后的字符串",table.concat(fruits,", "))	--指定连接字符
print("连接后的字符串",table.concat(fruits,", ",2,3))	--指定索引来连接
print()

-- Table 插入和移除
-- table.insert (table, [pos,] value)   table.remove (table [, pos])
fruits = {"apple","orange","banana"}
print("最后一个元素是：",fruits[3])
table.insert(fruits,"mango")		--在末尾插入
print("最后一个元素是：",fruits[4])

print("索引为 2 的元素是：",fruits[2])
table.insert(fruits,2,"grapes")	--在索引为2的地方插入
print("新的索引为 2 的元素是：",fruits[2])

print("最后一个元素是：",fruits[5])
table.remove(fruits)		--移除最后一个元素
print("移除后最后一个元素是：",fruits[5])
print()

-- Table 排序
fruits = {"apple","orange","banana","mango"}
print("排序前")
for k,v in ipairs(fruits) do
	print(k,v)
end

table.sort(fruits)
print("排序后")
for k,v in ipairs(fruits) do
	print(k,v)
end
print()

-- Table 最大值
function table_max(t)
	local mn  = nil
	for k, v in ipairs(t) do
		if(mn == nil)	then
			mn = v
	end
	if mn < v  then
		mn = v
	end
	end
	return mn
end
tbl = {[1] = 2, [2] = 6, [3] = 34, [26] = 5}
print("tbl 最大值：",table_max(tbl))
print("tbl 长度：",#tbl)

--[[函数返回多个值--]]
function temp(  )
	return 1,2,3,4,5
end
res1, res2,res3,res4,res5 = temp()
print(res1,res2,res3,res4,res5)
print()


--[[可变参数--]]
--普通格式
function add1( ... )
	local s = 0
	for i,v in ipairs{...}	do
		s = s + v
	end
	return s
end
print(add1(1,2,3,4))
-- 函数传递表格式
mytable = {1,2,3,4,5}
function add2(tab)
	local s = 0
	for i,v in ipairs(tab)	do
		s = s + v
	end
	return s
end
print("type=" .. type(table),"ans="..add2(mytable))
print("type=" .. type({1,2,3,4,5,6}),"ans="..add2({1,2,3,4,5,6}))
print()

-- #arg 获取变量数和计算
function average( ... )
	local result = 0
	local arg = {...}		--arg为表，局部变量
	for i,v in ipairs(arg)	do
		result = result + v
	end
	print("总共传入" .. #arg .. "个数")
	return result/#arg
end
print("平均值为" .. average(1,2,3,4,5,6,7,8))
print()

-- select("#",...)获取可变参数的数量
function average2( ... )
	local result = 0
	local  arg = {...}
	for i,v in ipairs(arg)	do
		result = result + v
	end
	print("总共传入" .. select("#", ...) .. "个数")
	return result/select("#", ...)
end
print("平均值为" .. average2(1,2,3,4,5,6,7))
print()

--
do
	function foo( ... )
		for i=1, select('#',...)		do	--获取参数总数
			local arg = select(i, ...)		--读取参数
			print("arg" , arg)
		end
	end
	foo(1,2,3,4)
end
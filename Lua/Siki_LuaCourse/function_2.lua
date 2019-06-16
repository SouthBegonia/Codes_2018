--[[递归求阶乘函数--]]
function  recursion( n )
	if (n==1) then
		return n
	else
		return n*recursion(n-1)
	end
end
print("recursion(3)=",recursion(3))
-- 函数传递
recursion2 = recursion
print("recursion2(4)=",recursion2(4))
print("recursion(4)=",recursion(4))
print()

--[[函数作为参数传递--]]
myprint = function ( param )
	print("myprint("..param..")="..param)
end
function add( num1, num2, PointFunction)	--函数作为参数
	local result = num1 + num2
	PointFunction(result)	--调用传递的函数参数
end
myprint(12)
add(1,5,myprint)
print()

--[[函数返回多值--]]
function Maxinum( n )
	local mi = 1		--最大元素索引
	local max = n[mi]	--初始首位元素为最大值
	for i,val in ipairs(n) do
		if val > max then
			mi = i
			max = val
		end
	end
	return max,mi 		--返回最大值及其索引
end
print(Maxinum({2,8,5,10,3,9,4,1,6}))
print()


--[[可变参数--]]
function add2( ... )
	local s =0
	for i,val in ipairs{...} do
		s = s +val
	end
	return s
end
print(add2(1,2,3,4,5))
print()
--可变参数赋值给变量
function average( ... )
	local result = 0
	local arg = {...}		--arg为一个表
	for i,val in ipairs(arg) do
		result = result + val
	end
	print("总共传入".. #arg .. "个数")
	return result/#arg
end
print("平均值为".. average(1,2,3,4,5,6,7,8,9))
print()


-- [[# 除了求字符串长度外还可以求表内元素的个数--]]
string = "South"
print(string .. "的长度为 " .. #string)
table = {11,12,13,14,15,16}
for i,val in ipairs(table) do
	print(i ,val)
end
print("table内元素个数为" .. #table)

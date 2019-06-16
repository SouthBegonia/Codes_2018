-- 函数放回两个值的最大值
function max( num1,num2)
	if(num1>num2) then
		result = num1
	else
		result = num2
	end
	return result;
end

print("两值比较最大值为",max(10,4))
print("两值比较最大值为",max(5,6))
print()

-- 将函数作为参数传递给函数
function myprint ( param )
	print("这是打印函数 - ##",param," ##")
end

function add( num3,num4,functionPrint )
	result = num3+num4
	functionPrint(result)	-- 调用传递的函数参数，等价于myprint(result)，第二次打印
end

myprint(10)	-- 第一次打印

add(2,5,myprint)  -- 将 myprint 函数作为参数传递
print()

-- 多返回值
function  maxinum( a )
	local mi = 1	  --最大值索引
	local m = a[mi]		--最大值
	for i ,val in ipairs(a) do
		if val > m  then
			mi = i
			m =val
		end
	end
	return m , mi
end

print(maxinum({8,10,23,12,5}))
print()

-- 可变参数
function add2( ... )
	local s = 0
	for i, v in ipairs{...} do  --{...}表示一个由所有变长参数构成的数组
		s = s+v
	end
	return s
end

print(add2(3,4,5,6,7))	--25
print()

-- 计算几个数的平均值
function average( ... )
	result = 0
	local arg = {...}		--arg为一个表，局部变量
	for i,v in ipairs(arg) do
		result = result + v
	end
	print("总共传入 ".. #arg .. " 个数")
	return result/#arg
end
print("平均值为",average(10,5,3,4,5,6))

-- 也可以使用select("#",...) 来获取可变参数的数量, 返回可变参数的长度
function average2( ... )
	result = 0
	local arg={...}
	for i,v in ipairs(arg) do
		result = result + v
	end
	print("总共传入 " .. select("#",...) .. "个数")
	return result/select("#",...)
end
print("平均值为",average2(10,5,3,4,5,6))
print()

-- select(n, …) 用于访问 n 到 select('#',…) 的参数
do
	function foo( ... )
		for i=1,  select('#',...) do
			local arg = select(i,...)
			print("arg",arg)
		end
	end
	foo(1,2,3,4)
end
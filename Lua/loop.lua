-- Lua 的循环种类：while，for

-- while循环
a=1
while(a<3)
do
	print("a的值为:",a)
	a = a+1
end	-- 整体while的end

-- for循环:数值for循环/泛型for循环
-- 数值for循环
function f(x)
	print("fucntion")
	return x*2
end
for i=1,f(5) do
	print(i)
end

for i=6,1,-1 do
	print(i)
end

-- 泛型for循环
a={"one","two","three"}
for i, v in ipairs(a) do
	print(i,v)
end

days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}
for i,v in ipairs(days) do
	print(v)
end

-- repeat...until  循环
a = 10
repeat
	print("a的值为:",a)
	a=a+1
until(a>15)	-- 判断为真 停止循环

-- 嵌套循环
j=2
for i=2,10 do
	for j=2,(i/j),2 do
		if(not(i%j)) then
				break
		end
		if(j>(i/j)) then
			print("i的值为:",i)
		end
	end
end
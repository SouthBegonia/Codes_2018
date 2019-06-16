function fact( n )
	if n==0 then
		return 1
	else
		return n*fact(n-1)
	end
end
--[[
a = -2		--当阶乘数为负数时报错  栈溢出stack overflow
print(fact(a))
--]]

--调用求绝对值函数解决问题
a = -5
if a>0 then
	print(fact(a))
	else
		print(fact(math.abs(a)))
end


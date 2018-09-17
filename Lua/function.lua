-- 函数被看作“第一类值” 函数可以存放在变量里
function factorial_1( n )
	if n== 0 then
		return 1
	else
		return n * factorial_1(n-1)
	end	-- if 末尾的end
end	-- 函数末尾的end

print(factorial_1(5))
factorial_2 = factorial_1
print(factorial_2(4))
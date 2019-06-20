--[[--
标准Lua使用64个bit位来储存整型值，最大值 math.maxinteger=2^63-1(约10^19)，最小值math.mininteger
精简Lua使用32个bit位来储存整型值，最大值约20亿
]]

print(math.maxinteger)
print(math.mininteger)

-- 回环(warp around) 问题
print(math.maxinteger+1 == math.mininteger)
print(math.mininteger-1 == math.maxinteger)
print(-math.mininteger == math.mininteger)
print(math.mininteger//-1 == math.mininteger)


--当操作数超过其范围时，整数型运算发生回环，浮点型运算发生取近似值
print(math.maxinteger + 2)
print(math.maxinteger + 2.0)
print(math.maxinteger + 2.0 == math.maxinteger + 1.0)

--浮点型能够表示整数范围在 [-2^53,2^53] 故我们可以再次区间忽略整型和浮点型的区别
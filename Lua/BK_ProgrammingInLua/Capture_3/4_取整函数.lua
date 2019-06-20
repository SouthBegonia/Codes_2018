--[[ Lua取整函数：
floor:向负无穷取整
ceil:向正无穷取整
modf:向0取整(还多返回小数部分)
--]]
print(math.floor(1.2))
print(math.floor(-1.2))
print(math.floor(2^70))

print(math.ceil(1.2))
print(math.ceil(-1.2))

print(math.modf(1.2))
print(math.modf(-1.2))
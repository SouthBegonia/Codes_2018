--[[
变量在使用前需要声明，即创建变量(可以看作初始化赋值即有声明作用)
Lua的变量有三种：全局变量，局部变量，表中的域
--]]

a = 5	-- 默认全局变量
local b = 5	-- 显示说明才为局部变量
print(a,b)
--> 5 5

function exa()
	c = 5	-- 全局变量
	local d = 6	-- 局部变量
end
exa()
print(c,d)
--> 5 nil

do
	local a = 6	-- 	局部变量
	b = 6	-- 对局部变量重新赋值
	print(a,b)
	--> 6 6
end

print(a,b)		--全局变量的a不变
--> 5 6

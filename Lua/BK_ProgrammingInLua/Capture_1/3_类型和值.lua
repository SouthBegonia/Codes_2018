--[[Lua的八种基本类型--]]
print(type(nil))		--nil
print(type(true))		--boolean
print(type(1.2*2))		--number
print(type("SouthBegonia")) --string
print(type(io.stdin))	-- userdata
print(type(print))		--function
print(type(type))		--thread
print(type({}))			--table
print(type(type(Z)))	--string


print()
print(a)				--nil
print(type(a))			--nil 未初始化的a

a=12
print(type(a))			--number

a="South"
print(type(a))

a=nil
print(type(a))			--当赋值nil给全局变量时，就相当于删除
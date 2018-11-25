--[[默认变量为全局变量--]]
 --全局变量
var_global = 10
print(var_global,type(var_global))

--[[局部变量生命周期为所在语句块--]]
 -- 局部变量的生命周期未语句块内(此处的local a 变量其周期为整个程序)
local a =10
 print(a)

 function test(  )
 	b = 5	--全局变量
 	local  c = 6	--局部变量 c 的周期仅为 test()
 	print(a,b,c)
 end
 test()
 print(a,b,c)
 print()

 --
 print(a,b)
 do
 	local a = 100	--局部变量
 	b = 50		--全局变量
 print(a,b)
end
print(a,b)
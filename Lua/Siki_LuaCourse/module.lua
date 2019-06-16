--[[Lua的模块由 变量，函数等已知元素组成table
所以创建模块的方法就是创建table，把需要导出的常量，函数放入其中，最后放回table--]]


-- 文件名 module.lua
--定义一个名为 module 的模块
module = {}

-- 定义一个常量
module.constant = "这是一个常量"

--定义一个变量
module.var = "Lua"

-- 定义一个函数
function module.func1( )
	io.write("这是一个全局函数\n")
end

local function func2(  )
	print("这是一个局部函数\n")
end

function module.func3(  )
	func2()
end

return module


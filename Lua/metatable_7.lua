--[[ __call元方法
当把表当作函数来使用时调用 __call
--]]
mytable = {"Lua","Java","Python","C++"}

mymetatable ={
	__call = function ( tab,arg1,arg2,arg3 )
		print(arg1,arg2,arg3)
		return "World"
	end
}
mytable = setmetatable(mytable,mymetatable)

v = mytable("Hello")
print(v)
v = mytable(12,34,567)
print(v)
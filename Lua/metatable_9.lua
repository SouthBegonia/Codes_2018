--[[ __tostring 元方法
用于修改表的输出行为--]]
mytable = setmetatable({10,15,20},{
	__tostring = function ( mytable )
		local sum = 0
		for k,v in pairs(mytable)	do
			sum = sum + v
		end
		return "表内所有元素的和为 " .. sum
	end
	})
print(mytable)
print()


mytable2 = setmetatable({"Hello World"}, {
	__tostring = function ( mytable2 )
		print("这是__tostring 内")
		return "修改后的输出为" .. mytable2[1]
	end
	})
print(mytable2)
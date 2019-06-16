--[[迭代器/迭代器方法 pairs 和 ipairs --]]
--[[ pairs ：迭代table ，遍历表中所有的 key 和 value--]]
array = {"Lua", "C#", "Java", nil, "C++"}
for i,v in pairs(array)	do
	print(i,v)
end
print()

--[[ ipairs 遍历索引从 1 开始递增遍历直到 nil --]]
for i,v in ipairs(array)	do
	print(i,v)
end
print()

--[[自定义Lua迭代函数--]]
function square(state, control)
	if(control >= state)	then
		return nil
	else
		control = control+1
		return control, control*control
	end
end

--[[ 迭代函数格式
for  变量列表  in  迭代函数, 状态函数,  控制函数  do
		body
	end
--]]
for i, j in square,9,0	do
	print(i,j)
end
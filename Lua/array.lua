-- Lua数组索引值默认为1开始的整数，如果没有索引值则返回nil
-- 数组设定了指定的索引值从而避免出现nil值，利于节省内存空间

-- Lua一维数组
array = {"Lua", "Tuorital"}

for i = 0, 2 do
	print(array[i])
end
print()


-- 数组索引值也可为负值
array = { }
for i = -2, 2 do
	array[i] = i*2
end
for i = -2, 2 do
	print(array[i])
end
print()


-- 多维数组
array = {}
for i=1, 3 do
	array[i] = {}
		for j=1, 3 do
			array [i][j] = i*j
		end
end
local s=""
for i=1, 3 do
	for j=1, 3 do
		s = s .. array[i][j]	-- 同行打印
	end
end
print(s)
print()
--[[数组的实现--]]
array = {"Hello", "World"}
for i=1,2	do
	print(array[i])
end

for i= -2,2	do
	array[i] = i*3
end
for i=-2,2	do
	print(array[i])
end
print()


--[[多维数组--]]
array2 = {{"jack","Rose"}, {1001,1002}, {"Math","Physical"}, {90,80}}		-- 4*2

for i=1,2	do
	print(array2[1][i], array2[2][i])
	print(array2[3][i], array2[4][i])
end
print()

array3 = {{},{},{}}	--含有三个元素的表
for i=1,3	do
	array3[i] = {}	--将三个元素构造成空表
	for j=1,2	do
		array3[i][j] = i*j
	end
end
for i=1,3	do
	for j=1,2	do
		print(array3[i][j])
	end
end
-- 迭代器能够遍历标准模板库容器中的部分或全部元素，每个迭代器对象代表容器中的确定的地址
-- 在Lua中的迭代器是一种支持指针类型的结构，可以遍历集合的每一个元素

-- 泛型for迭代器
array  = {"Lua", "Tutorial",}
for key, value in ipairs(array)
do
	print(key,value)
end
print()


-- 无状态迭代器
function square(iteratorMaxCount, currentNumber)
	if currentNumber < iteratorMaxCount
		then
			currentNumber = currentNumber + 1
		return currentNumber, currentNumber * currentNumber
	end
end
for i, n in square,3,0
do
	print(i,n)
end
print()

-- 当Lua调用ipairs(a)开始循环时，他获取三个值：迭代函数iter、状态常量a、控制变量初始值0；然后Lua调用iter(a,0)返回1,a[1]（除非a[1]=nil）
-- 第二次迭代调用iter(a,1)返回2,a[2]……直到第一个nil元素
function iter(a,i)
	i  = i + 2	-- 原 i = i +1
	local v = a[i]
	if v then
		return i, v
	end
end
function ipairs( a )
	return iter, a, 0
end
array  = {"One", "Two", "Three", "Four"}
for key, value in ipairs(array)
do
	print(key,value)
end
print()


-- 多状态的迭代器
array = {"Lua", "Tutorial"}
function elementIterator( collection )
	local index = 0
	local count = #collection
	-- 闭包函数
	return function (  )
		index = index + 1
		if index <= count
		then
			-- 返回迭代器的当前元素
			return collection[index]
		end
	end
end
for element in elementIterator(array)
do
	print(element)
end
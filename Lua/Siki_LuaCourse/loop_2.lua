--[[while循环--]]
a = 1
while(a<=20)	do
	if(a%2 == 1)	then
		print(a)
	end
	a = a+1
end
print()


--[[for循环
1.数值for循环
for var=start, end, step do
	body
end
	var 从 satrt 变化到 end ，每次变化一步长 step
2.泛型for循环--]]
-- 数值for循环
for i=1, 10, 2	do
	print(i)
end
print()
for i=10, 1, -2	do
	print(i)
end
print()


--泛型for循环
table = {key1 = "Value1", key2 = "Value2"}
for k,v in pairs(table)	do
	print(k,v)
end
table2 = {"One", "Two",3,"Four"}
for k,v in pairs(table2)	do
	print(k,v)
end
print()


--[[repeat until 循环--]]
a = 1
repeat
	print(a)
	a = a+1
until(a>=5)

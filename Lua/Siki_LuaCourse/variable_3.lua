--[[Lua中多变量的同时赋值--]]
a,b = 1,2
print(a,b)

s1, s2 = "Hello","World"
print(s1,s2)

c,d = 3,4
a,b = c,d
print(a,b)
print()


-- 当变量与值数量不符，值数量少时为被赋值的数为nil
a,b,c = 11,12,13,14
print(a,b,c)
a,b,c = 21,22
print(a,b,c)
print()


--变量返回多值
function test(  )
	return 40,50
end
a,b = test()
print(a,b)
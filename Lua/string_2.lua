--[[字符串的大小写转换--]]
str = "First string"
str2 = string.upper(str)
str3 = string.lower(str)
print(str,str2,str3)
print()


--[[字符串的替换--]]
str4 = string.gsub(str,"i","123")
str5 = string.gsub(str,"i","ABC",1)	--要替换的字符串，被替换字符，替换字符，替换次数
print(str4,str5)
print()


--[[查找字符串，返回匹配的第一个字符的位置--]]
index = string.find(str,"string")
print(index)
print()


--[[字符串的反转--]]
str6 = string.reverse(str)
print(str6)
print()


--[[字符串的格式化--]]
num1 = 5
num2 = 10
print("加法运算:" .. num1 .. "+" ..num2 .. "=" .. (num1+num2))		--繁琐的组拼语句
str7= string.format("加法运算: %d + %d = %d",num1,num2,num1+num2)		-- 字符串格式化(类似C)
print(str7)
name = "Chen"
id = 9527
str8 = string.format("%s's id is \'a%d\'",name,id)
print(str8)
print()


--[[字符与整数的转换--]]
str9 = string.char(65)		--转换ASCII为字符
print(str9)
str10 = string.byte("ABCD",4)		--转换第4个字符D为ASCII码，没有则默认转换第一个
print(str10)
print()


--[[字符串的拷贝--]]
str11 = string.rep("abcd",2)		--需拷贝的字符串及拷贝数量
print(str11)
print()


--[[正则表达式--]]
for word in string.gmatch("Hello  Lua","%a+")	do
	print(word)
end
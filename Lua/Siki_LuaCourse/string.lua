html = [[
Hello
world
]]		--此处有空行

print(html)

-- 在对一个数字字符串上进行算术操作时，Lua 会尝试将这个数字字符串转成一个数字
print("2" + 6)		--8
print("2" + "6")	--8
print("2 + 6")		--2+6
print("-2e2" * "6")	-- -1200

print("a" .. 'b')
 print(157 ..428)

 -- 使用 # 来计算字符串的长度，放在字符串前面
 len = "www.baidu.com"
print(#len)
print(#"www.baidu.com")

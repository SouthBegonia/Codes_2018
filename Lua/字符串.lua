-- lua 字符串的3种表示方法
string1 = "Lua"
print("\"字符串1是\"",string1)
string2 = 'www.google.com'
print("字符串2是",string2)
string3  = [[<Lua教程>]]
print("字符串3是",string3)
print()


-- 字符串大小写转换
string1 = "South"
print(string.upper(string1))
print(string.lower(string1))
print()


-- 字符串的查找与反转
string1 = "Lua Tutorial"
print(string.find(string1,"Tutorial"))	-- 查找
reversedString = string.reverse(string1)	-- 反转
print("新字符串为",reversedString)
print()


-- 字符串的替换
-- 要替换的字符串，被替换的字符，替换的字符，替换次数(默认即全部)
print(string.gsub("zwzwzw","w","Y",1))
print()


-- 字符串格式化
string1 = "Hello"
string2 = "World"
number1 = 10
number2 = 20
print(string.format("基本格式化 %s %s",string1,string2))
data = 2;  month =9;  year = 2018
print(string.format("日期格式化 %02d/%02d/%03d",data,month,year))
print(string.format("%.4f",1/3))
print(string.format("%q","One\nTwo"))
print(string.format("%s","South"))
print()


-- 字符串与整数的相互转换
print(string.byte("Lua"))	--第一个字符
print(string.byte("Lua",3))
print(string.byte("Lua",-1))	--末尾第一个字符
print(string.char(97))	--ASCII转换成字符
print()


-- 计算字符串长度
print("字符串长度为",string.len("South"))
print()


-- 链接多个字符串
print("字符串1" .."字符串2".."字符串3")
print()


-- 放回字符串string的n个拷贝
print("拷贝2份字符串",string.rep("233",2))
print()


-- 匹配模式
s = "Deadline is 30/05/1999, firm"
date = "%d%d/%d%d/%d%d%d%d"	--搜索该格式的日期
print(string.sub(s, string.find(s, date)))

s = "Now, is 2018.9.24"
data1 = "%d%d%d%d.%d.%d%d"
print(string.sub(s,string.find(s,data1)))
data2 = "%u%w%w,"
print(string.sub(s,string.find(s,data2)))
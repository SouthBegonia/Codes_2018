print(string.rep("abc",3))			--abcabcabc
print(string.reverse("A long line"))--enil gnol A
print(string.lower("A long line"))	--a long line
print(string.upper("A long line"))	--A LONG LINE
print()

--[[string,sub(s,m,n)  从s中返回第m到n个字符，不修改原s]]
str = "[South Begonia]"
print(str)
print(string.sub(str,2,-2))			--South Begonia
print(string.sub(str,1,1))			--[
print(string.sub(str,-1,-1))		--]
print()

str = string.sub(str,2,-2)
print(str .. '\n')

--[[string.char(num) 将整数num转换为对应字符]]
print(string.char(97))				--a
i = 99;print(string.char(i,i+1,i+2) .. '\n')--cde

--[[string.byte(s,i) 返回s中第i个字符串的内部数值表示]]
print(string.byte("abc"))			--97
print(string.byte("abc",2))			--98
print(string.byte("abc",-1))		--99
print(string.byte("abc",1,-1))		--97 98 99
print()

--[[string.format() 格式化输出]]
print(string.format("x=%d y=%d ",10,20))--x=10 y=20 
print(string.format("x=%x",200))		--x=c8
print(string.format("x=0x%X",200))		--x=0xC8
print(string.format("x=%f",200))		--x=200.000000
print(string.format("%02d/%02d/%04d",1,1,1900))--01/01/1900
tag,title = "h1","a title"
print(string.format("<%s>%s</%s>",tag,title,tag))--<h1>a title</h1>
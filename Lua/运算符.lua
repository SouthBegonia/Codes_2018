-- Lua运算符：算术运算符，逻辑运算符，关系运算符，其他运算符

-- 算术运算符
a=20
b=10
c=a+b
print("c=a+b=",c)
c=a*b
print("c=a*b=",c)
c=a/b
print("c=a/b=",c)
c=a%b
print("c=a%b=",c)
c=a^2
print("c=a^2=",c)
c=-a
print("c= -a =",c)

-- 关系运算符
a=20
b=10
if(a==b)
then
	print("a==b")
else
	print("a~=b")
end

if(a~=b)
then
	print("a~=b")
else
	print("a==b")
end

-- 逻辑运算符：逻辑与操作符 and，逻辑或操作符 or，逻辑非操作符 not
a=true
b=true
if(a and b)
then
	print("a and b 为true")
end

if(a or b)
then
	print("a or b 为true")
end

-- 修改a，b
a=false
b=true

if(a and b)
then
	print("a and  b 为true")
else
	print("a and b 为false")
end

if(not(a and b))
then
	print("not(a and b) 为true")
else
	print("not(a and b) 为false")
end


-- 其他运算符： 连接两个字符串.. , 一元运算符返回字符串或表的长度 #
a="hello"
b="world"

print("连接字符串a和b",a..b)
print("b字符串长度",#b)
print("字符串Text长度",#"Text")
print("百度网页长度",#"www.baidu.com")
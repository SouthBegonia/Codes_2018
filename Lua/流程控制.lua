-- lua提供的控制语句有：if语句， if...else语句， if 嵌套语句

-- if 语句
-- 在表达式为ture时指定if内的·代码，为 false 时，指定end后的代码
-- Lua认为false和nil为假，true 和非nil为真。Lua中 0 为 true
a=10
if(a<20)
	then
	print("a小于20")
end
print("a的值为",a)

-- if...else语句
a=15
if(a<20)
then
	print("a小于20")	-- 表达式为true
else
	print("a大于20")	-- 表达式为false
end
print("a的值为",a)

-- if...elseif...else
a=100
if(a==10)
then
	print("a的值为10")	-- a==10为真
elseif(a==20)
then
	print("a的值为20")	-- a==20为真
elseif(a==30)
then
	print("a的值为30")	-- a==30为真
else
	print("没有匹配a的值")		-- 上述所有为假
end
print("a的值为",a)
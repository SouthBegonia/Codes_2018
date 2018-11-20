--[[ Lua基本数据结构 ]]--
-- type()函数 ：检测括号内的数据类型，返回数据类型的字符串
print(type("Hello world"))      --> string
print(type(10.4*3))                 --> number
print(type(print))                    --> function
print(type(type))                    --> function
print(type(true))                     --> boolean
print(type(nil))                        --> nil
print(type(type(X)))                --> string
print()
print(type(b))		--> 未赋值全局变量默认类型为 nil
b = 10
print(type(b))		--> 赋值后其类型修改

-- [[ 数据类型：nil ]]--
-- 表示该数据类型没有任何有效值(如为初始化的变量)，其次nil也有着删除的作用
table = {key1 = "Hello",key2 = "world"}
print(table.key1,table.key2)
print("type(table) = ",type(table))
--[[ 仅把其元素进行 nil 不能使得table变为 nil
table.key1 = nil
table.key2 = nil ]]--
table = nil
print("type(table) = ",type(table))
print()


-- [[布尔类型 boolean]]--
-- Lua中把 false 和 nil 定义为 假
if false or nil then
	print("false 和 nil 中至少一个为 true")
else
	print("false 和 nil 都为 false")
end
print()


--[[数字类型 number]]--
-- Lua 默认只有double精度的number类型
print(type(0))
print(type(0.1))
print(type(1e+1))
print(type(0.1e-1))
print()


--[[字符串类型 string]]--
-- Lua中字符串有三种表达方式： ''   ""   [[]]
string1 = "Hello"
string2 = "world"
string3 = [[
SouthBegonia
]]
print(string1,string2)
print(string3)
-- 对数字字符串进行算术操作时，Lua会将其转换为数字类型，例如 "10"+1, "10"-1, "10"*2
string4 = "10"
print("string4 = ",string4,"type=",type(string4))
string4 =string4 + 1
print("string4 = ",string4,"type=",type(string4))
-- 计算字符串长度： 前缀#
len = "SouthBegonia"
print(len,"=",#len)
-- 字符串的连接： "" .. ""   ，区别于简单的print("","","")，该连接中间没有间隔
print("Hello".."world")
print("Hello","world")

--[[表 table]]--
-- 详见目录下相关代码

--[[线程 thread]]--
-- 详见目录下相关代码

--[[自定义类型 userdata]]--
-- 详见目录下相关代码
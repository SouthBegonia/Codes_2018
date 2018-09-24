# Lua学习
[Lua](https://baike.baidu.com/item/lua/7570719?fr=aladdin)：是一个小巧的**脚本语言**，其设计目的是为了**嵌入应用程序中**，从而为应用程序提供灵活的扩展和定制功能。Lua由标准C编写而成，几乎在所有操作系统和平台上都可以编译，运行。

特性：
- 轻量级：轻量级Lua语言的官方版本只包括一个精简的核心和最基本的库
- 可扩展性

环境 ：Lua5.1.0 / Sublime Text3

## 基本语法
Lua代码存储在名为 xxxx.lua 的脚本文件内。

**简单打印：**
```
print("Hello World！")
```

**注释：**
单行注释：`--`
多行注释：
```
--[[多行注释
 多行注释--]]
```

**标识符：**
以字母 A 到 Z 或 a 到 z 或下划线 _ 开头后加上0个或多个字母，下划线，数字（0到9）。Lua 是一个区分大小写的编程语言。

下面列出了一些在Lua中的保留字。这些保留的字不可以被用作常量或变量，或任何其它标识符。

|  |  |  |  |
|--|--|--|--|
|and     |break |do    |else  |
|elseif	 |end	|false |for   |
|function|if    |in    |local |
|nil	 |not	|or	   |repeat|
|return  |then  |true  |until |
|while   |

## 数据类型
> Lua是动态类型语言，变量不要类型定义,只需要为变量赋值

| 数据类型    |  描述   |
|------------|---------|
|nil	 |只有值nil属于该类，表示一个无效值（在条件表达式中相当于false） |
|boolean |包含false和true|
|number	 |表示双精度类型的实浮点数|
|string	 |字符串由一对双引号或单引号来表示|
|function	|由 C 或 Lua 编写的函数|
|userdata	|表示任意存储在变量中的C数据结构|
|thread 	|表示执行的独立线路，用于执行协同程序|
|table	 |Lua 中的表（table）其实是一个"关联数组"（associative arrays），数组的索引可以是数字或者是字符串。在 Lua 里，table 的创建是通过"构造表达式"来完成，最简单构造表达式是{}，用来创建一个空表|

- 代码示例 [数据类型.lua](https://github.com/SouthBegonia/Codes_2018/blob/master/Lua/数据类型.lua)

## 循环
**While 循环**
```
while(condition)	-- 为真时执行循环体语句
do
   statements
end
```

**For 循环**
- 数值for循环
```
-- var从exp1变化到exp2，每次变化以exp3为步长递增var，并执行一次"执行体"。exp3是可选的，如果不指定，默认为1
for var=exp1,exp2,exp3 do  
    <执行体>  
end
```

- 泛型for循环
```
-- i是数组索引值，v是对应索引的数组元素值。ipairs是Lua提供的一个迭代器函数，用来迭代数组
-- 打印数组a的所有值  
a = {"one", "two", "three"}
for i, v in ipairs(a) do
    print(i, v)
end 
```

**嵌套循环**
- 代码示例 [loop.lua](https://github.com/SouthBegonia/Codes_2018/blob/master/Lua/loop.lua)

## 流程控制
> Lua 认为 false 和 nil 为假，true 和 非nil 为真, **Lua中 0 为 true**

**if语句**
```
if(布尔表达式)
then
   --[ 在布尔表达式为 true 时执行的语句 --]
end
```

**if...else语句**
```
if(布尔表达式)
then
   --[ 布尔表达式为 true 时执行该语句块 --]
else
   --[ 布尔表达式为 false 时执行该语句块 --]
end
```

**if...elseif...else**
```
if( 布尔表达式 1)
then
   --[ 在布尔表达式 1 为 true 时执行该语句块 --]

elseif( 布尔表达式 2)
then
   --[ 在布尔表达式 2 为 true 时执行该语句块 --]

elseif( 布尔表达式 3)
then
   --[ 在布尔表达式 3 为 true 时执行该语句块 --]
else 
   --[ 如果以上布尔表达式都不为 true 则执行该语句块 --]
end
```
- 代码示例 [流程控制.lua](https://github.com/SouthBegonia/Codes_2018/blob/master/Lua/流程控制.lua)

## 函数
函数定义格式：
```
optional_function_scope  function function_name( argument1, argument2, argument3..., argumentn)
    function_body
    return result_params_comma_separated
end
```

|          |         |
|----------|---------|
| optional_function_scope | 可选的制定函数是全局函数还是局部函数，未设置该参数默认为全局函数 |
| function_name |指定函数名称 |
|argument1, argument2, argument3..., argumentn| 函数的参数，多个参数用逗号隔开，也可以不带参数|
|function_body |函数体|
|result_params_comma_separated| 函数返回值，Lua语言函数可以返回多个值，每个值以逗号隔开|


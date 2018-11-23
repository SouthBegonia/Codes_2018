# Lua学习
[Lua](https://baike.baidu.com/item/lua/7570719?fr=aladdin)：是一个小巧的**脚本语言**，其设计目的是为了**嵌入应用程序中**，从而为应用程序提供灵活的扩展和定制功能。Lua由标准C编写而成，几乎在所有操作系统和平台上都可以编译，运行。

- 特点：
 - 轻量级：轻量级Lua语言的官方版本只包括一个精简的核心和最基本的库
 - 可扩展性

- 开发环境 ：Lua5.1 ，Sublime Text3 / SciTE
- 学习资料：
 - [Lua教程 - 菜鸟教程](http://www.runoob.com/lua/lua-tutorial.html)
 - [Lua编程 - SiKi学院](http://www.sikiedu.com/my/course/75) 

## 基本语法

**打印：**
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

## 变量
> Lua中创建的变量默认为全局变量，默认值为 nil

- 创建全局变量：`variable = 5`
- 创建局部变量：`local variable2 = 10`



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

- `optional_function_scope` : 可选的制定函数是全局函数还是局部函数，未设置该参数默认为全局函数
- `function_name`：指定函数名称
- `argument1, argument2, argument3..., argumentn`：函数的参数，多个参数用逗号隔开，也可以不带参数，且参数的类型不限，也可以传递函数
- `function_body`：函数体
- `result_params_comma_separated`：函数返回值，Lua语言函数可以返回多个值，每个值以逗号隔开

**匿名函数**：只调用一次的无名函数，常作为参数被其他函数调用
```
-- 一个main函数，被传入val参数及一个匿名函数
function main(val,
	function (..)
		-- body
	end
)
```


## 运算符

|     Lua运算符(功能参考C语言)    |     表示 |
|----------|---------|
|算术运算符 |`+` `-` `*` `/` `%` `^` `- 负号`|
|关系运算符 |`==` `~= 不等于` `>` `<` `>=` `<=`|
|逻辑运算符|`and` `or` `not`|

- 其他运算符：
	- `..` ：在print()内连接两个字符，例如`print("Number is" .. number)`，此表示方法与`print("Number is",number)`表示区别在于没有间隔，而`,`表示间隔较大(一制表符？)
	- `#`：返回**字符串**或**表**的长度，例如`print(#table)`

- 代码示例 [运算符.lua](https://github.com/SouthBegonia/Codes_2018/blob/master/Lua/运算符.lua)

运算符的优先级：
1. `^`
2. `not`  `-(负号)`
3. `*`  `/`
4. `+`	`-`
5. `..`
6. `<` `>` `<=` `>=` `~=` `==`
7. `and`
8. `or`


## 字符串
Lua中字符串有三种表达方式：
- 单引号间的字符串 `' '`
- 双引号间的字符串 `" "`
- 双中括号间的字符串 `[[ ]]`

关于字符串的操作方法例如：

|  用法  |   用途 |
|--------|--------|
|`string.upper(str)`|   字符串全部转换为大写|
|`string.lower(str)`|字符串全部转换成小写|
|`string.gsub(mainString,findString,replaceString,num)`|`mainString`为要替换的字符串，`findString` 为被替换的字符，`replaceString`为要替换的字符，`num`替换次数（默认全部替换)|
|`string.find (str, substr, [init, [end]])`|在字符串`str`中搜索指定的内容`substr`,第三个参数为搜索到的第几个符合内容。返回其具体位置(首尾),不存在则返回`nil`。|
|`string.reverse(str)`|反转字符串|
|`string.format(...)`|返回类似C语言printf的格式化字符串|
|`string.len(str)`|计算字符串的长度|
|`string.rep(str,n)`|返回字符串`str`的n份拷贝|
|`str1..str2`|连接两个字符串|

- 代码示例 [字符串.lua](https://github.com/SouthBegonia/Codes_2018/blob/master/Lua/字符串.lua)


## 数组
Lua的数组有**一维数组**和**二维数组**，数组的索引值可以用整数(默认从**1**开始，**负数**亦可)。

```
-- 一维数组
array = {"First","Second"}
```

```
-- 二维数组
array = {}
for i=1,3 do
	array[i] = {}
		for j=1,3 do
			array[i][j] = i*j
		end
end
```
- 代码示例 [array.lua](https://github.com/SouthBegonia/Codes_2018/blob/master/Lua/array.lua)


## 表 table
> tableName 是 Lua 的一种数据结构用来帮助我们创建不同的数据类型，很类似于数组

1. 表的创建
```
字符串为索引：tableName1 = {key1 = "hello",key2 = "world" ...}
数字为索引：  tableName2 ={}
			   tableName2[1], tableName2[2], ... = 10, 20, ...
			   tableName3 = {"South","Begonia","Hi","Friend"}
```
	- `tableName` ：构建的表的名字 
	- `key1,key2...` ：表内元素的索引，或称键，可为任意数据类型。当索引为字符串时(key1,key2等)，省略其双引号。若不另设索引，默认为从1开始的索引

2. 表的读取
	- 索引为字符串时： `print(tableName.key1,tableName.key2)` 或 `print(tableName["key1"],tableName["key2"])`
	- 索引为数字时：`print(tableName[1],tableName[2])`

## 迭代器
> [迭代器](https://baike.baidu.com/item/%E8%BF%AD%E4%BB%A3%E5%99%A8/3803342?fr=aladdin "迭代器")（iterator）是一种对象，它能够用来遍历标准模板库容器中的部分或全部元素，每个迭代器对象代表容器中的确定的地址。

Lua中的迭代器：
1.泛型for迭代器
2.无状态的迭代器
3.多状态的迭代器
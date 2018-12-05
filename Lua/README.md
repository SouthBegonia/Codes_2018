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
> Lua中创建的变量默认为全局变量，初始值默认值为 nil

- 全局变量
	- 创建：函数内外均可，例如`variable = 5`
	- 生命周期：程序结束
- 局部变量
	- 创建：在函数内`local variable2 = 10`，表示局部变量在目标函数开始时创建，在结束时被销毁
	- 生命周期：目标函数期间



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
-- var从 start 变化到 end，每次变化以 step 为步长递减，并执行一次"执行体"。step 是可选的，如果不指定，默认为1
for var=start, end, step do  
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
```
-- 函数基本结构
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

**函数返回多值**：要求接受返回值的数目匹配
```
function temp()
	return 1,2,3,4,5
end

res1, res2,res3,res4,res5 = temp()	--接收数目与返回数目匹配
print(res1,res2,res3,res4,res5)
```

**可变参数**：
```
function add( ... )
	local s = 0
	for i,v in ipairs{...}  do
		s = s + v
	end
	return s
end
print(add(1,2,3,4))
```

**获取可变参数的参数个数**
```
-- 获取可变参数的数量：select("#",...)
function average( ... )
	local result = 0
	local  arg = {...}	--arg为表
	for i,v in ipairs(arg)  do
		result = result + v
	end
	print("总共传入" .. select("#", ...) .. "个数")
	return result/select("#", ...)
end
print("平均值为" .. average2(1,2,3,4,5,6,7))
```


## 运算符

|     Lua运算符(功能参考C语言)    |     表示 |
|----------|---------|
|算术运算符 |`+` `-` `*` `/` `%` `^` `- 负号` (注意无自加自减)|
|关系运算符 |`==` `~= 不等于` `>` `<` `>=` `<=`|
|逻辑运算符|`and` `or` `not`|

- 其他运算符：
	- `..` ：在print()内连接两个字符，例如`print("Number is" .. number)`，此表示方法与`print("Number is",number)`表示区别在于没有间隔，而`,`表示间隔较大(一制表符？)
	- `#`：返回**字符串**或**表**的长度，例如`print(#table)`，但表的索引需为自然数(operator.lua)，此外，不可用 `..` 连接 `#table`此类，因为`..#`会别判定为错误的运算符

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

**表的创建**：

```
字符串为索引：tableName1 = {key1 = "hello",key2 = "world" ...}
数字为索引：  tableName2 ={}
			   tableName2[1], tableName2[2], ... = 10, 20, ...
			   tableName3 = {"South","Begonia","Hi","Friend"}
```

- `tableName` ：构建的表的名字 
- `key1,key2...` ：表内元素的索引，或称键，可为任意数据类型。当索引为字符串时(key1,key2等)，省略其双引号。若不另设索引，默认为从1开始的索引

**表的读取**：
- 索引为字符串时： `print(tableName.key1,tableName.key2)` 或 `print(tableName["key1"],tableName["key2"])`
- 索引为数字时：`print(tableName[1],tableName[2])`

**表的操作**：

|用法|功能|
|---|---|
|`table.concat(table,"/",start,end)`|将表内从`start`到`end`号元素进行连接，用符号`/`间隔|
|`table.insert(table,num,"str")`|插入字符串或者数字到表内第`num`号元素位置(原来的元素后移)|
|`table.remove(table,num)`|删除表内第`num`号元素，后续元素前移|
|`table.sort(table)`|对表内元素进行排序(规则类似C++)|
|`table.maxn(table)` Lua5.2后已经弃用，需另写函数|返回表内最大值元素的索引|


## 迭代器
> [迭代器](https://baike.baidu.com/item/%E8%BF%AD%E4%BB%A3%E5%99%A8/3803342?fr=aladdin "迭代器")（iterator）是一种对象，它能够用来遍历标准模板库容器中的部分或全部元素，每个迭代器对象代表容器中的确定的地址。

**Lua中的迭代器**：
1. 泛型for迭代器
2. 无状态的迭代器
3. 多状态的迭代器

**Lua内置的迭代器 pairs 与 ipairs**:
- `pairs`：迭代table ，遍历表中所有的 key 和 value。遇到 nil 则跳过
- `ipairs`：遍历索引从 1 开始递增直到 nil 停止

```
array = {"Lua", "C#", "Java", nil, "C++"}
for i,v in pairs(array)	do
	print(i,v)
end
--[[pairs 输出
1	Lua
2	C#
3	Java
5	C++
--]]

for i,v in ipairs(array)	do
	print(i,v)
end
--[[ipairs 输出
1	Lua
2	C#
3	Java
--]]
```


**自定义迭代器**：
```
--迭代函数格式
for 变量列表  in  迭代函数,状态函数,控制函数  do
	body
end

--自定义迭代函数 square
function square(state, control)
	if(control >= state)	then
		return nil
	else
		control = control+1
		return control, control*control
	end
end
--使用迭代器
for i, j in square,9,0	do
	print(i,j)
end
```

迭代器各部分：
- 变量列表：接收迭代函数返回值的一些变量(个数同返回值个数)。此例中的 `i`,`j` 与 `state`,`control`
- 迭代函数：Lua内置有`pairs`和`ipairs`，此例中自定义的`square`
- 状态函数：被传递给迭代函数的参数之一，一般仅赋值一次。表示总共迭代多少次。此例中的 `state`
- 控制函数：被传递给迭代函数的参数之一，迭代过程中被多次赋值。表示当前已迭代的次数

迭代过程：
1. 调用迭代函数`square`，把状态函数`state`和控制函数`control`传递给它
2. 如果迭代函数的返回值为`nil`,则退出 `for循环`，否则把返回值赋给变量列表，并执行循环体实现迭代过程


## 模块 Module
> 把一些公用的代码放在一个文件里，以 API 接口的形式在其他地方调用的机制称为模块(module)

**定义模块**：
```
--文件名 module.lua

--定义一个名为module的模块
module = {}

--定义模块内的变量、常量、函数
module.var = 10
module.constant = "Lua"
module.func1 = function()
	print("这是module内的函数")
end

--结束定义
return module
```

**调用模块**：
```
--文件名 usemodule.lua

--[[
调用方法:
require "模块名"
require ("模块名")
--]]

require "module"
print(module.var)
module.func1()
```

**模块的加载机制**：


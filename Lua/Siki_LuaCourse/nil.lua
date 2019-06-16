-- type() ：返回括号内值的数据类型

-- nil 类型表示一种没有任何有效值，它只有一个值 nil，例如打印一个没有赋值的变量a，便会输出一个 nil 值
print(type(a))

-- 给变量赋值后，即为number类型
a=5
print(type(a))
print(a)

-- 对于全局变量和 table，nil 还有一个"删除"作用，给全局变量或者 table 表里的变量赋一个 nil 值，等同于把它们删掉
a=nil
print(a)

-- nil 作比较时应该加上双引号
-- type(X) == "nil"

-- type(X)==nil 结果为 false 的原因是 type(type(X))==string

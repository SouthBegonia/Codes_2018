--and :第一个操作数为false就返回它，否则返回第二个
--遵循短路求值(Short-circuit evaluation)：只有在必要时才操作第二个
--false 和 nil 为假
print(4 and 5)		-->5
print(nil and 13)	-->nil
print(false and 13) -->false


--or :第一个操作数不为false就返回它，否则返回第二个
--同样遵循短路求值
--0 和 空字符 为真
print(0 or 5)		-->0
print(false or "S") -->S
print(nil or false) -->false


--not :返回布尔类型值
print(not nil)		-->true
print(not false)	-->true
print(not 0)		-->false
print(not not 1)	-->true
print(not not nil)	-->false
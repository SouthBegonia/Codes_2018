--[[表内元素的连接
table.concat(table,"str",num1,num2)
--]]
mytable = {"Lua","C","C#","Java","C++"}
print(table.concat(mytable))
print(table.concat(mytable,"/"))	--间隔符为 '/''
print(table.concat(mytable,"|",2,4))		--保留2~4号元素
print()


--[[表的插入和移除
table.insert(table,num,"str")
table.remove(table,num)
--]]
mytable[#mytable] = "PHP"
print(mytable[#mytable])
table.insert(mytable,"javascript")
print(mytable[#mytable])
table.insert(mytable,2,"Yaho")		--插入元素到原2号位置
print(mytable[2],mytable[3])
table.remove(mytable,2)		--删除2号元素，后续元素前移
print(mytable[2],mytable[3])
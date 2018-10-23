

-- 对指定的表设置元素
mytable = {}				-- 普通表
mymetatable = {}	-- 元表

setmetatable(mytable , mymetatable)	-- 把mymetatable 设为mytable 的元表

--以上代码等价于 mytable = settatable({}, {})

--放回对象元表
getmetatable(mytable)		--返回mymetatable

-- __index元方法
mytable = setmetatable({key1 = "value1"}, 	--mytable设定了元表，方法为__index
{
  __index = function(mytable, key)		--判断元表有没有__index方法，如果__index方法是一个函数，则调用该函数
    if key == "key2" then
      return "metatablevalue"
    elseif key == "key3" then
      return "Second2"
    else
    	return nil
    end
  end
},{key3 = "Second"})
print(mytable.key1,mytable.key3)
print()
--[[上段代码等价于：
mytable = setmetatable({key1 = "Value1"}, { ___index = { key2 = "metatablevalue"}})
print(mytable.key1, mytable.key2)
--]]


-- __newindex元方法
mytable = {}
mytable = setmetatable({key1="value1"}, {__newindex = mymetatable})
print(mytable.key1)

mytable.newkey = "新值2"
print(mytable.newkey, mymetatable.newkey)

mytable.key1 = "新值1"
print(mytable.key1, mymetatable.key1)
print()
-- rawset函数更新表
mytable = setmetatable({key1 = "value1"}, {
  __newindex = function(mytable, key, value)
        rawset(mytable, key, "\""..value.."\"")
  end
})

mytable.key1 = "new value"
mytable.key2 = 4

print(mytable.key1,mytable.key2)
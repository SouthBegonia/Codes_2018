a = "South Begonia"

-- 改变字符串中的部分字符串
--区别于C的字符串修改，Lua不可在原有字符串上做修改
b = string.gsub(a,"Begonia","Park")
print(#b,b)
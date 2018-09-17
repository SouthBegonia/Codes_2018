-- 赋值

-- 变量个数>值得个数  不足的补nil
a,b,c,d = 0,1,2
print(a,b,c,d)
-- 0 1 2 nil

-- 变量个数<值的个数  多余的被舍弃
print(a,b)
a,b = a+1,b+1,b+2
-- 1 2

-- 多个变量赋值必须依次对每个变量赋值 a,b,c = 0 , 0, 0
print(a,b,c)
a,b,c = 0
-- 0 nil nil

-- 交换a,b值
a,b = 1,2
print(a,b)
a,b = b,a
print(a,b)

-- 索引
site = {}
site["key"] = "www.baidu.com"
print(site["key"])
print(site.key)
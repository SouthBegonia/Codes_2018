--[[math.random 生成伪随机数(每次运行生成相同的伪随机数序列)
math.random()生成[0,1)范围为均匀分布的随机数
math.random(k) 生成 [1,k]范围内的随机数
math.random(m,n) 生成 [m,n]范围内的随机数
--]]
--未设置种子的随机数序列，运行一次后就不再改变
print(math.random())
print(math.random(10))
print(math.random(1,5))

-- 设置随机数种子
math.randomseed(os.time())
print(math.random())
print(math.random(10))
print(math.random(1,5))

--操作数为整型和浮点型时，Lua先将整型转换为浮点型
print(12.0+15)
print(type(12.0+15))

-- floor除法：将得到的商向负无穷取整
print(3//2)
print(3.0//2)
print(-9//2)
print(1.5//0.5)
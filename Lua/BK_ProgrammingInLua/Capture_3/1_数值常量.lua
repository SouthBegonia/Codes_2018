--[[
Lua 5.3始，数值的格式分：integer的64位整数类型，float的双精度浮点类型
--]]

--整数值和浮点数类型都为 number ，可以相互转换
print(type(5))
print(type(5.5))
print(4==4.0)
print(-4==-4.00)
print(0.1e3==100)

--string.format("%a",419)	-->0x1.ap+8
--string.format("%a",0.1)	-->0x1.999999999999ap-4	
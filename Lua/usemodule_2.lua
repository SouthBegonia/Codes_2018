--[[引用module.lua文件内的 module 里面的module模块：
require "模块名"
require ("模块名")

存疑：如何选择调用哪个文件的module
--]]
require "module"
print(module.var1)
module.func1()
--module.func2()		局部函数不可直接被引用
module.func3()		--但通过全局函数func3()可以间接调用func2()

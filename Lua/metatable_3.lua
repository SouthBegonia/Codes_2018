print(getmetatable("Lua"))
print(getmetatable(10))

--如果元表中存在__metatable键值，setmetatable会失败
--使用__metatable 可以保护元表，禁止用户访问元表中的成员或者修改元表
tA = {}
mt = {}
getmetatable(tA,mt)
mt.__metatable = "lock"
setmetatable(tA,mt)
print(getmetatable(tA))
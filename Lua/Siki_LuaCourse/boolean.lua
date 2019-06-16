-- boolean 类型只有 true 和 false，Lua 把 false 和 nil 看作是"假"，其他的都为"真":
print(type(true))
print(type(false))
print(type(nil))

if false or nil then
    print("至少有一个是 true")
else
    print("false 和 nil 都为 false!")
end
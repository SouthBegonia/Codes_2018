--打印所在函数的名字
function SimpleFunction()
    print(debug.getinfo(1).name)
end

SimpleFunction()	-->SimpleFunction
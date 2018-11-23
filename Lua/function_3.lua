--[[函数作为参数传递和匿名函数的用法--]]
tab = {key1 = "val1",key2 = "val2"}
function test( tab,fun )
	for k,v in pairs(tab) do		--注意此处不是iparis
		fun(k,v)
	end
end

function f1( k,v )
	print(k .. ":" .. v)
end
test(tab,f1)
print()

function f2( k,v )
	print(k .. " ".. v)
end
test(tab,f2)
print()


--[[匿名函数作为参数，在调用test函数时只调用匿名函数一次，匿名函数不可有名字--]]
test(tab,
	function ( k,v )
		print(k .. "-" .. v)
	end)


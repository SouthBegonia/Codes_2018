--[[协同函数内的返回值--]]
co = coroutine.create(
	function ( a,b )
		print("Before yield")
		coroutine.yield(a*b+1,a+b+1)		--挂起，返回参数
		print("After yield")
		return a*b+2,a+b+2	--函数末尾，返回参数
	end)
res1,res2,res3 = coroutine.resume(co,20,30)
print(res1,res2,res3)

res1,res2,res3 = coroutine.resume(co)
print(res1,res2,res3)
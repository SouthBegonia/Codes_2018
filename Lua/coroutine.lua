--[[协程可以理解为 协程函数(coroutine)
普通函数：执行完函数体直到 return 才返回
协程函数：在函数体某处人为暂停，跳转到主函数体继续后继代码(称为对该函数的挂起)。也可以在主函数体某处再返回协程内继续代码
使用协程的目的：建立一个可以随时中断和随时恢复的函数
-
function test( ... )
	--code1
	--pause
	--code2
	--code3
	return
end

test()

--after code

--go on
--]]

--定义协同函数，coroutine.create()，返回地址需要接收
co = coroutine.create(
	function (a,b)		--此处需为匿名函数
		print(a+b)
		coroutine.yield()		--函数挂起
		print(a-b)
	end
	)

--重启协同函数，coroutine.resume，协同函数
coroutine.resume(co,20,30)
print("Done!")
coroutine.resume(co)	--重启
print()


-- coroutine.wrap()定义协同函数
co2 = coroutine.wrap(
	function ( a,b )
		print(a*b)
		coroutine.yield()		--函数挂起
		print(a-b)
	end)

--该方法下重启协同函数，
co2(30,20)
print("Done!")
co2()	--再次运行实现重启，无需参数
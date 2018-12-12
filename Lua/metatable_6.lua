--[[ __add 元方法，实现将表 newtable 的元素加在 mytable 后面 --]]
mytable = {"Lua","Java","Python","C++"}
mymetatable = {
	__add = function ( tab,newtab )
		local mi = 0
		for k,v in pairs(tab)	do
			if(k>mi)	then
				mi = k
			end
		end

		for k,v in pairs(newtab)	do
			mi = mi + 1
			table.insert(tab,mi,v)
		end
	end
}
mytable = setmetatable(mytable,mymetatable)

newtable = {"PHP","C"}

v1 = mytable + newtable
for k,v in pairs(mytable) do
	print(k,v)
end
print()


function table_maxn( tab )
	local mn = 0
	for k,v in pairs(tab)	do
		if mn < k	then
			mn = k
		end
	end
	return mn
end

mytable2 = setmetatable({3,4,5}, {
	__add = function (mytable,newtable )
		for i=1,table_maxn(newtable)	do
			table.insert(mytable,table_maxn(mytable)+1, newtable[i])
		end
		return mytable
	end
	})

secondtable = {6,7,8}

mytable2 = mytable2 + secondtable
for k,v in ipairs(mytable2)	do
	print(k,v)
end
print()

--[[ __sub元方法--]]

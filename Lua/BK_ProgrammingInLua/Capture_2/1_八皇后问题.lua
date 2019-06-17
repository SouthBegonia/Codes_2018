--[[
八皇后问题：
--]]
N = 8

function IsPlaceOk( a,n,c )
	for i=1,n-1 do
		if(a[i]==c) or
			(a[i]-i == c-n) or
			(a[i]+i == c+n) then
			return false
		end
	end
	return true
end

--打印棋盘
function PrintSolution( a )
	for i=1,N do
		for j=1,N do
			io.write(a[i]==j and "X" or "-"," ")
		end
		io.write("\n")
	end
	io.write("\n")
end

--把从 n~N 的所有皇后放在棋盘 a 上
function AddQueen( a,n )
	if(n>N) then
		PrintSolution(a)
	else
		for c=1,N do
			if IsPlaceOk(a,n,c) then
				a[n] = c
				AddQueen(a,n+1)
			end
		end
	end
end

AddQueen({},1)
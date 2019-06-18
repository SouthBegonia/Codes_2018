--[[
八皇后问题：某一皇后所在的行与列内再无其他皇后，总共8个皇后，例如：
	X - - - - - - - 
	- - - - X - - - 
	- - - - - - - X 
	- - - - - X - - 
	- - X - - - - - 
	- - - - - - X - 
	- X - - - - - - 
	- - - X - - - - 
--]]

N = 8	--八个皇后

--检查(n,c)是否不会被攻击
function IsPlaceOk( a,n,c )
	for i=1,n-1 do
		if(a[i]==c) or				--同一列
			(a[i]-i == c-n) or		--同一对角线
			(a[i]+i == c+n) then	--同一对角线
			return false
		end
	end
	return true		--不会被攻击，位置有效
end

--打印棋盘
function PrintSolution( a )
	for i=1,N do		--行
		for j=1,N do	--列
			io.write(a[i]==j and "X" or "-"," ")
		end
		io.write("\n")
	end
	io.write("\n")
end

--把从 n~N 的所有皇后放在棋盘 a 上
function AddQueen( a,n )
	if(n>N) then		--是否所有的皇后都被放置好了
		PrintSolution(a)
	else
		for c=1,N do	--尝试放第n个皇后
			if IsPlaceOk(a,n,c) then
				a[n] = c  	--把第n和皇后放在列c
				AddQueen(a,n+1)
			end
		end
	end
end

AddQueen({},1)
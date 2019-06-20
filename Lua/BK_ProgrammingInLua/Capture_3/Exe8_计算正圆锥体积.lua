-- 计算正圆锥体的体积
-- 母线l ，高h，母线与高夹角angle
l = 5
h = 4
angle = 30

r = math.sin(math.rad(angle)) * l
s = math.pi * (r^2) * h

v = 1/3 * s * h
print(v)

-- 保留位数
v = v - v%0.01
print(v)
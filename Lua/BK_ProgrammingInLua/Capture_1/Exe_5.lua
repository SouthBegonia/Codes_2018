print(1==1)				-->true
print(1==2)				-->false
print(nil==nil)			-->true
print(type(nil))		-->nil
print(type(type))		-->准确来说是thread(线程)类型,当本例此处显示为function型
print(type(nil))		-->nil
print()


print(type(nil)==nil)	--false
--type()为线程类型，而nil为nil类型，两者类型不同，故为false
--type()内的内容不影响其本身的类型

print(type(true)==nil)	--false
print(type("Hello")=="hello")--false
# 指针与数组
--------------
参考资料：
- 《深入理解C指针》
- 《指针的编程艺术》
- [数组指针和指针数组的区别——jack_孟](https://www.cnblogs.com/mq0036/p/3382732.html)
-----------------
> 数组：能用索引访问的同质元素连续集合(内存连续)

## 数组和指针的相似处
我们可以把数组**下标**用在指针上，即：
`*(p + i)` 等价于 `p[i]`

指针的**加减运算**对于数组同样实用，即数组名加减整数：
`*(p + i)` 等价于 `*(array + i)`


## 数组和指针的差别
1.`array[i]` 与 `*(array+i)` 结果相同，生成的机器码却不同
- `array[i]`：从 `array` 位置开始，移动 `i` 个位置，再取出内容
- `*(array+i)`：从 `array` 位置开始，在地址上增加 `i` ，然后取出这个地址中的内容

2.`sizeof`操作符对他们的操作不同
有代码例如
```
int array[5] = {1,2,3,4,5};
int *p = array;
```
则
- `sizeof(array)`：返回20，即**数组分配的字节数** *4X5*
- `sizeof(p)`：返回4，即**指针长度**

## 数组指针(行指针)
- 定义：指的是**数组名的指针** 、 **数组首元素地址的指针** 、 **指向数组的指针**。例：`int (*p)[4]` ，`p` 即为指向数组的指针
- 声明解释：定义一个 指向整数型的一维数组(长度为n) 的**指针**

有代码如下：
```
int array[3][4];
int (*p)[4];
p = array;
```

**`p` 与 `p+1` 与 `++p`**：`p` 是一个int型数组(长度4)的指针，`p+1` 是另一个int型数组(长度为4)的指针，通过一个 `p` 可以读取 `array[]` 的内容，`++p`同理
![](https://i.imgur.com/nEObzYh.jpg)

**`p` 读取 `array[0]`**：当数据类型匹配时，可以理解为 `*p` 内的 `*p+0,*p+1,*p+2,*p+3` 对应读取`array[0][1],array[2]...`
![](https://i.imgur.com/8yxHeen.jpg)

**`p+1`读取 `array[1]`**：当数类型匹配时，同理读取 `array[1]`的内容
![](https://i.imgur.com/V6pYYdQ.jpg)

**当 `*p` 与 `array[]`数据类型不匹配**：即`array[3][4]` 与 `(*p)[5]`，因为`*p`为5个int的数组，在`p`读取`array[0]`时，`*p+4` 占据了 `array[1][0]`，在`p+1`读取`array[1]`时，则从`array[1][1]`开始读取，产生其他结果，但这并不算错误，而是警告`[Warning] assignment from incompatible pointer type [-Wincompatible-pointer-types]`。同理，当`*p`内元素少于数组，则提前读取
![](https://i.imgur.com/WzERE64.jpg)

**总结(前提为数据类型匹配)**：
- `p+i 与 *p+i`：一个指向第二数组首位元素，一个指向第一数组的第`i`个元素
- `*p[n] 与 (*p)[n]`：优先级`() > [] > *`，一个是`p[n][0]/array[n][0]`，一个为`p[0][n]/array[0][n]`

代码示例：[数组指针.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/PointerWithArray/%E6%95%B0%E7%BB%84%E6%8C%87%E9%92%88.c)


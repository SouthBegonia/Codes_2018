# stdio.h

[stdio](https://baike.baidu.com/item/stdio.h/9637809?fr=aladdin) 是指 “ *standard input & output* "（**标准输入输出**)，源代码中如用到标准输入输出函数时，就要包含此头文件。


-------------

## 流-stream
不管对设备或是文件（广义上都是文件）的输入输出操作，而产生的**数据**，都是I/O流。而C语言中的I/O流能分为两种：**文本流**，**二进制流**

在C语言中，程序开始运行时，系统自动打开3个标准文件：
- 标准输入：stdin
- 标准输出：stout
- 标准出错输出：stderr



- 参考：[C语言中流指什么](https://zhidao.baidu.com/question/513394569.html?qbl=relate_question_0&word=c%D3%EF%D1%D4%20%C1%F7)

## scanf()
- 声明：`int scanf(const char *format, ...)`
- 功能：连续从流中读入字符,对和格式说明符(如`%d`)相匹配的部分进行变换处理。如说明符为 `%d` 时输入`123↙` 从**流**中读取了 123 但**换行符**依旧残留在**流**中被后续`getchar()`读取。此外,当`scanf()`读取失败(如说明符`%d`但输入了英文字符),scanf()会导致读取失败的部分遗留在**流**中。
- 代码示例：[scanf.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/scanf.c)

## sscanf()
- 声明：`int sscanf(const char *str, const char *format, ...)`
- 功能：从字符串读取格式化输入
- 代码示例：[vmtest.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/vmtest.c)，[sscanf.c](https://github.com/SouthBegonia/Codes_2018/blob/master/Pointer/sscanf.c)



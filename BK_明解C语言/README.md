# BK_明解C语言
--------------

**rand()**

- 头文件：`<stdlib.h>`
- 格式：`int rand(void); `
- 功能：生成伪随机数，基于种子值(`seed`,默认为1)，按照特定规律生成的随机数。
- 代码示例：\C code\Code_2018\BK_明解C语言\猜数游戏_随机数生成。

**srand()**

- 头文件：`<stdlib.h>`
- 格式：`void srand(unsigned seed);` 
- 功能：给后续调用的`rand()`设置种子(`seed`)，用于生成新的伪随机数序列。
- 代码示例：\C code\Code_2018\BK_明解C语言\猜数游戏_随机数生成。
- 说明：常把时间当种子，`srand(time(NULL))`
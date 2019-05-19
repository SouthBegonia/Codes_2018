# 打砖块游戏

- 基本功能：实现WASD进行视角在XY轴方向的移动，其次按下鼠标左键产生子弹`bullet`对面前的砖块`cube`进行碰撞。


**制作过程：**

1. 创建平面`plane`做场景的地面
2. 创建砖块的预制体`Cube`，包含信息有
	- 碰撞体 `Box Collider`
	- 材质 `Cube Material`
	- 刚体 `Rigidbody`
3. 复制砖块堆积创建墙壁 `TotalCubes`
4. 对镜头`Main Camera`编写脚本 `Short.cs` 及 `Movement.cs`
	- `Movement`：键盘读取WASD值对视角进行XY轴的移动
	- `Short`：单鼠标左键按下即实体化子弹预制体 `bullet`，并且赋予初速度
5. 至此实现基本功能，以下为其他可添加功能
	- 弹跳性：创建`Physic Material`材质，其中`Bounciness`属性即为弹性(0代表无弹力，1表示完全反弹)，将其赋予`Collider` 的 `Material`即可实现


主页面
![主页面](https://img2018.cnblogs.com/blog/1688704/201905/1688704-20190519175259411-1290471200.png)


运行情况
![运行情况](https://img2018.cnblogs.com/blog/1688704/201905/1688704-20190519175307233-1657591039.png)

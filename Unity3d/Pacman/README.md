Pixels Per Unit：多少像素相当于Unity一个单位，迷宫Maze大小232x256，

Pivot：设置贴图的零点，Bettom Left左下角

物理化：墙，import package->custom package，导入已经设置好碰撞体的墙

pacman切图,动画片段：Sprite Mode->multiple，Pixels Per Unit=8，进行Sprite Editor，显示其窗口。选择Slice切片，Type为Grid By Cell Count，切割参数3行4列，Apply后可在Pacman下面看到切割好的12张照片。

制作动作：12张照片每3张为一个动作，分别是右，左，上，下，每次将3张拖入Hierarchy面板，保存在Animations文档下，各自命名。可在Project面板Animations文件夹下包含4个动画文件，说明每次保存的3张图片生成一个动画，还包含4个动画机(但只需要设置一个。其余可删除)

状态机：在主角Pacman内添加Animator组件，添加上述留下的动画机，打开Animator页面，看到4个组件，初始情况为：当游戏物体进入状态机，默认状态转变为PacmanRight；后拖拽其他3个状态到状态机页面

分析主角移动：仅仅能横x纵y向移动，当持续按住某方向键位，速度为每0.3s移动 1 Unit，

通过Any State切换连接4个状态，点击连线可看到说明：无论在任何状态只要达到连线内条件，即转变状态到所指对象状态

在Parameters内添加float型DirX，DirY值用来判断(持续按键产生的是浮点数)。例如PacmanRight的判断，添加DirY，当DirY>0.1(浮点数不精确性质，留一定范围)。并且取消状态机Settings内Can Transition To（考虑到帧数问题，和重复播放初始动作问题），其次2D动画将融合调0

其他：可以调节动画的speed以调节播放该动作的速度

主角的实体化：加碰撞器，circle collider，添加rigdbody2D，设置重力0

脚本格式规范化：全选，ctrlK，ctrlF

public的变量可在unity面板看到，可外界操控
private的变量则私有，不可外界修改

吃豆人的移动方法：
1.修改transform瞬移，修改坐标，多用在生成位置
2.rigidbody2D移动，物理移动，推荐使用

调用Vector2.MoveTowards(transform.position，dest,speed)，使得返回起始点到目标点的中间值，另设temp接收这个值；再对刚体进行移动操作GetComponent<Rigidbody2D>().MovePosition(temp)；
而初始时transform.position=test，故不会移动，因此需要按键检测以改变dest的值：Input.GetKey(KeyCode.UpArrow)或者Input.GetKey(KeyCode.W)实现读取键位，然后赋值dest：(Vector2)transform.position + Vector2.up;

但此时移动会造成吃豆人旋转问题，原因在于与墙壁碰撞时Z轴坐标改变造成旋转，解决：Rigdibody2D->Constraints->Freeze Rotation Z
还有问题：卡槽间移动容易卡住，问题在于按键过程时刻改变dest，造成temp = Vector2.MoveTowards（）的时刻改变，解决：判断当上一个dest抵达时才读取新的键位if ((Vector2)transform.position == dest)

又产生新的问题：抵达墙边时，键盘读取的dest到了墙以外，if判断永远无法transform.position==dest，无法在键盘读取，解决：

从而实现每次移动仅走1Unit
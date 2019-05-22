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

实现不同动作状态机的切换：
- 获取移动的方向：Vector2 dir = dest - (Vector2)transform.position;
- 把获取到的方向设置到状态机，状态机从而进行切换GetComponent<Animator>().SetFloat("DirX", dir.x);

2D游戏Z轴问题：若在不同层级碰撞功能失效；若在同一层级，则存在渲染顺序问题(谁覆盖谁)
Order in Layer：小先大后，可以确定渲染顺序，迷宫先0，豆子pacdot中1，2~5敌人，6Pacman

豆点：Pacdot即为豆子图标，拖入页面内，对其添加Box Collider 2D，设置为触发器。对所有Pacdot添加脚本Pacdot.cs，创建碰撞检测OntriggerEnter2D来检测触发Pacdot的物体是否为Pacman，若是，则销毁Pacdot

敌人：重复切图，合成动作，设置图层，安放位置；关于状态机，采用重写状态机(Animation文档，create->Animator Override Controller，改为敌人替代原状态机)，后设置状态机参照Controller为Pacman的，可看到Original为Pacman内的动作，Override内的就设置为每个敌人的不同动作；注意，删除原有的状态机使得物体的Animator内Controller找不到状态机组件，此时需要将重写后的状态机设置到它身上）;再设置Rigidbody和CircleCollider(注意此处要设置为触发器Trriger而不是碰撞器，范围0.8)

敌人的移动(单路径)：创建一连串的路径点，储存于way内，编写EnemyMove.cs，创建循环队列保存所有路径点Transform[] WayPoint，及数组标记index表示当前再前往哪个路径点的途中；创建FixedeUpdata()，首先判断：若怪物没抵达目标位置，则从当前位置持续移动直到抵达(同Pacman的移动，但没有输入检测)，若抵达，则index++，前往下一个点；此外动画状态的检测、切换也同Pacman的；同时也设置触发检测，当检测到触发的物体是Pacman，则销毁Pacman;在Unity页面将全部路径点拖拽到怪物脚本的Way Point处实现赋值数组

多路径：
- 先创建对象 wayPointsGo用来接收只作为预制体的路径Way；
- 创建表wayPoints，在start内调用foreach方法，将wayPointGo内的组件取出到t，将t.position坐标顺序添加到wayPoints表内(还需修改FixedUpdate函数内wayPoints[index]此时为表，存储的是坐标，无需再.position，后续的wayPoints.Length也改为了wayPoints.Count)；由此实现了一条路径；
- 根据前面路径Way预制体的制作方法，再次制作多条路径;
- 修改EnemyMove.cs，游戏对象wayPointsGo改为数组形式
```
    private void LoadApath(GameObject go)
    {
        //将wayPointsGo数组内某一路径的子物体(路径点)的Transform组件取出，依次将其position赋值到Ways表中
        //修改为多路径后随机从5条路径走
        foreach (Transform t in wayPointsGo[Random.Range(0, 4)].transform)
        {
            wayPoints.Add(t.position);
        }
    }
```
- 创建LoadApath函数：首先清除上调路径遗留再List中的信息，后foreach()加载路径到List内，而后再Start内每次调用随机LoadApath()函数，传入随机一条路径。

不同怪物出门都与Blinky红色怪物同一点问题：删除所有路径预制体的首末路径点(同一点)。修改EnemyMove.cs
- 创建一个坐标变量 startPos用在存放该点，初始Start函数内设置satrtPos为怪物起始坐标+向上3个单位；
- 再后续foreach()加载路径表的函数后，插入该点到List表头，及再List末尾添加该点；
```
        //添加首末路径点到List内
        wayPoints.Insert(0, startPos);
        wayPoints.Add(startPos);
```

即便随机路径下不同怪物选到同路径问题：添加GameManager.cs，添加如下代码实现每个怪物随机选取的路径不同
```

public class GameManager : MonoBehaviour
{
    private static GameManager _instance;

    public static GameManager Instance
    {
        get
        {
            return _instance;
        }
    }

    public GameObject Pacman;
    public GameObject Blinky;
    public GameObject Cycle;
    public GameObject Inky;
    public GameObject Pinky;

    public List<int> usingIndex = new List<int>();
    public List<int> rawIndex = new List<int> { 0, 1, 2, 3};

    private void Awake()
    {
        _instance = this;
        int tempCount = rawIndex.Count;

        for (int i = 0; i < tempCount; i++)
        {
            int tempIndex = Random.Range(0, rawIndex.Count);
            usingIndex.Add(rawIndex[tempIndex]);
            rawIndex.RemoveAt(tempIndex);
        }
    }
}

//再修改EnemyMove,Start内
LoadApath(wayPointsGo[GameManager.Instance.usingIndex[GetComponent<SpriteRenderer>().sortingOrder - 2]]);
```


超级豆子：
GameManager.cs内：
- 创建pacdotGos，foreach()存储所有豆子；
- 生成超级豆子：CreateSuperPacdot()
- 创建布尔变量isSuperPacman(初始为false)；
Pacdot.cs内：
- 修改碰撞触发判定：if(是超吃豆人状态){} else 被敌人消灭
EnemyMove.cs:
- 修改碰撞触发判定：if(碰到的是超级吃豆人){} else 消灭吃豆人



协程引入：
- 引入命名空间

- 生成超级豆子
- 豆子被吃掉后
- 从表内移除该豆子，销毁对象，延时10s后准备下一个超级的生成，与此同时改变吃豆人状态isSuperPacman=true(两过程不干涉，并行执行)
- 调用恢复状态函数，持续超级吃豆人状态4s后取消敌人的冻结及超级状态
- 若在超级吃豆人状态期间吃到敌人，则敌人位置回归到初始

UI：
创建UI->Canvas，作为UI工作区域；
- 添加image作为logo；
- 创建空物体命名StartPanel，包含2个UI->text，start和exit，修改字体，调整位置
- 创建空物体命名GamePanel，包含3个UI->text，remain，eaten，修改字体，score
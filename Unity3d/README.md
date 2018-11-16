## 调试：
在某函数内进行`Debug.Log(...)`可实现调试检测，例如：
```
public class Player : MonoBehaviour {

	// Use this for initialization
	void Start () {
        Debug.Log("Hello");
	}
	
	// Update is called once per frame
	void Update () {
		Debug.Log(" World");
	}
}
//在控制台查看调试信息
```

## 获取碰撞体信息：
- 前提：碰撞两者都有碰撞器 Collider ，至少一物体有刚体 Rigidbody（详细前提见 [Unity-Manual-Colliders](https://docs.unity3d.com/Manual/CollidersOverview.html) ）

```
// 碰撞触发检测
 private void OnCollisionEnter(Collision collision)
    {
        print(collision.collider);		//获取碰撞体+碰撞器类型
        print(collision.collider.name);		//碰撞体名称
        print(collision.collider.tag);		//碰撞体标签
    }

// 碰撞结束检测
private void OnCollisionExit(Collision collision)
        print("OnCollisionExit");

// 碰撞持续检测
private void OnCollisionStay(Collision collision)
        print("OnCollisionSaty");

```

## 触发器 Trigger:
存在于碰撞体collider页面栏，勾选is Trigger 则表示物体为触发器(可以穿过)，否则物体为碰撞体。

## 光照贴图：
灯光是实时计算的(默认设置：`Light|Mode|Realtime`)，对不变动的灯光进行贴图可以节省资源，在`Windows|Rendering|Lighting Setting` 打开了`Lighting Setting` 页面点击 `Generate Lighting` 实现灯光贴图。
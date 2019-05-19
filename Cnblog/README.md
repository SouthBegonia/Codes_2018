# 博客园blog定制

记录我在定制个人blog页面效果时遇到的技巧及方法等。
效果：[SouthBegonia](https://www.cnblogs.com/SouthBegonia/)

## 基本流程
1. 设定博客皮肤为BluSky
2. 定制首页代码：引入外部CSS

## 页顶博主名字及副标题
在首页html内输入以下代码可添加博主名到页面顶端，也可添加副标题：
```
<header class="main-header" id="site-head">
        <div id="top" class="vertical">
            <div id="site-head-content" class="inner row">
                <div class="col-md-9">
                    <div class="site-description">
                        <h2 class="blog-title">YourBlogName</h1>
                        <h3 class="blog-description">SubtitleContent</h2>
                    </div>
                </div>
            </div>
        </div>
</header>
```
- YourBlogName：主标题，可写博主名等
- SubtitleContent：副标题，可写座右铭、博客说明等

## 字体及背景图
创建CSS编写页面字体的信息及背景图；首先需要引入所创建的CSS，方法为[通过link标签引入](https://www.cnblogs.com/zhaoyingli/p/5379990.html)，在首页html输入：
```
<link type="text/css" rel="stylesheet" href="https://blog-static.cnblogs.com/files/YourBolg/YourTheme.css"/>
```
- YourBlog：个人创建博客园blog时的Blog地址名
- YourTheme：上传编写好的`.css`文档到博客-管理-文件内，以便上述代码调用

关于`.css`文件的定制信息包括各类标题、字体样式、背景图片等信息，能力有限暂不细讲，但若采用其他主题可有更便捷方法实现更换背景图、修改字体等功能。


## Fork me on Github 标签
在首页html内输入以下代码即可实现标签：
```
<a href="https://github.com/YourGithub">  
<img style="position: fixed; top: 0; right: 0; border: 0; z-index:9999;" 
	src="https://github.blog/wp-content/uploads/2008/12/forkme_right_red_aa0000.png?resize=149%2C149" class="attachment-full size-full" 
	alt="Fork Me On GitHub" data-recalc-dims="1">
</a>
```
- YourGithub：个人github的链接
- src="..."：[github官网](https://github.blog/2008-12-19-github-ribbons/)提供的标签样式，可自行查找


## 参考
- [付伤年华的博客](https://www.cnblogs.com/ruanraun/)
- [止步路人 - 让你的博客不再单调，博客园设置随机背景图片教程](https://www.cnblogs.com/zhibu/p/7158807.html)
- [Rosaynatu - 博客园个人首页背景设置](https://blog.csdn.net/qq_36346831/article/details/80947660)
- [FEbuddy - 引入外部CSS的两种方式及区别](https://www.cnblogs.com/zhaoyingli/p/5379990.html)
- [legege007 - 博客园美化](https://www.jianshu.com/p/eb66825d6808)
- [CSS文本字体颜色](http://www.divcss5.com/rumen/r116.shtml)
- [Chrome取色器](https://jingyan.baidu.com/article/f25ef2548e8544482c1b82b0.html)
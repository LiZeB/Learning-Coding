## 介绍

###  1. Learning_cpp
对C++各种特性的测试
- queue：empty()成员函数
- vector：各种初始化方式的区别；
- 关联容器：map
- C++中algorithm库中自带的算法：sort()
- 重写了一遍C++ primer第11.3.6小节中出现的单词置换程序，用到了文件输入输出流、字符流、字典
- 字符串操作：全面熟悉了C++中string、char*这两种字符串的各种操作；增加了与字符串操作相关的两个笔试题
- thread多线程类：
	- thread的常用操作；
	- 利用mutex对线程进行加锁；
	- 多线程笔试题：多个线程按顺序打印字母，比如ABCABCABC
	- 锁管理类：unique_lock，lock_guard; 设置条件协调线程运行的条件变量类：condition_variable;
	- 锁的概念：C++中锁有一个作用域，作用域内所有的资源都会被锁定，只能被一个线程使用。这些资源可以是变量、输入输出流;
- 面向对象的特性：
	- 基类的成员访问权限，派生类的继承权限；
	- 类的内存分配，成员内存对齐规则；
	- 类的构造函数，静态函数；
- 强制类型转换：static_cast、dynamic_cast、reinterpret_cast、const_cast【较难】
	
###  2. DataStructure
常见数据结构的实现
- 单向链表；
- 链表的排序；
- 栈；
- 二叉树；
- 二叉搜索树；
- 平衡二叉搜索树（即AVL树）
- 哈希表(散列表)；
- 图：
	- 用邻接矩阵的方式实现了图的基本操作；
	- 用邻接表的方式实现了图的基本操作；
	- 邻接表形式下图的深度优先搜索；
	- 邻接表形式下图的广度优先搜索；
- 堆：
	- 堆的基本操作：插入、删除最大值、初始化为最大堆等；
	- 利用最大堆实现的堆排序；

###  3. Algorithm
一些平常用到自己亲自实现过的算法
- 生成字典序；
- 排序算法：
    - (1)插入排序；
	- (2)希尔排序(运算符重载输出vector)；
	- (3)冒泡排序；
	- (4)归并排序；
	- (5)快速排序
- 查找算法：
	- (1)二分查找
- 最短路径搜索：
	- (1)Dijkstra算法
    
### 4. Java Code
java学习
- 数据类型的转换
- 链表实现
- 加入了链表的排序
- 排序算法：
    - (1)冒泡排序；
    - (2)冒泡降序排序；
    - (3)择排序；
    - (4)插入排序；
    - (5)快速排序；
    - (6)加入了二分查找的递归实现和非递归实现；
- 栈的实现：
    - (1)基于数组的顺序栈；
    - (2)基于链表的链式栈；
- 二叉树的实现：
    - (1)数组转换成二叉搜索树；
    - (2)增加/删除二叉树的节点；
    - (3)遍历二叉树；
    - (4)统计二叉树的高和节点个数；
- 堆(大顶堆)的实现：
    - (1)数组转换成堆；
    - (2)插入元素/向上调整；
    - (3)删除元素/向下调整；
    - (4)用堆实现排序；
- 死锁：
    - (1)synchronized实现；
    - (2)lock实现；
- 动态规划经典背包问题：
    - (1)0-1背包问题；
    - (2)完全背包问题；
    - (3)多重背包问题；
- clone方法学习：
    - (1)重写clone方法实现深拷贝
- 创建对象的几种方法：
    - (1)new;
    - (2)调用clone方法，具体见clone方法学习部分；
    - (3)调用newInstance方法，2种；
    - (4)序列化和反序列化，代码未实现；

### 5.Socket
Linux下Socket编程

### 6.MySQL
- 用C++连接本地MySQL数据库，并做一些简单地查询操作；
- 从select查询结果生成新表；

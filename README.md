## 项目介绍
1. Learning_cpp: 对C++各种特性的测试
2. DataStructure: 常见数据结构的实现
### 2019/7/21
1. 出现了一个getMax函数返回值设置为引用【本不该设置为引用】导致链表中的值被莫名其妙修改的问题。一开始以为排序算法内部出了问题
，花了两个小时一一排除，最后才发现问题出在getMax获取链表最大值的问题上。
# 不同算法之间的处理分析
## map vs 堆
- 堆：priority_queue,
    - 底层结构：一个标准完全二叉树；
    - 插入删除的时间是O（logn）->对应的就是二叉树插入/删除的平均时间
    - 优势：整体占用的空间比较小
    - 特点：只能对于最值数据进行处理
    - 定义方法
        - 大根堆：`priority_queue<int> pq1`;
        - 小根堆：`priority_queue<int, vector<int>, decltype(cmp)> min_pq(cmp);`
    - 使用函数（其实和queue一致）
        - .top()：访问极值
        - .pop()：删除极值
        - .insert()：插入相关的值
- 集合：map/set
    - 底层结构：红黑树（平衡二叉树）
        - 相较于原来的平衡二叉树（AVL树）来说，红黑树的要求没有那么强，没有那么多的平衡的操作
    - 插入删除的时间是O（logn）->对应的就是平衡二叉树插入/删除+再平衡的平均时间
    - 优势：能够进行遍历，里面的部分是有序的
    - 劣势：存储了大量的链接（左右孩子的指针），占据的空间很大
    - 定义方式
        - 一般是直接对于数值的输入`std::set<int> s3 = {5, 2, 8, 2};`
    - 使用函数：
        - `auto t=set.begin()`
            - set数据是int-> `int num=*t`
            - set数据是pair-> `int num=t->first`
        
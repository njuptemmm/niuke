# CPP分析与思考
## 基本介绍
1. 全局算法 (Global Algorithms)
大部分你熟悉的查找操作（如 find, lower_bound, upper_bound, sort）都定义在 <algorithm> 头文件中。它们是“泛型”的，意味着它们不属于任何特定的容器，而是通过迭代器在任何容器上工作。

2. 成员函数 (Member Functions)
只有当容器的内部结构（如红黑树或哈希表）可以利用特殊算法来极大提高效率时，容器才会自己定义同名的成员函数。
- 对于 std::unordered_map：
  - myUnorderedMap.find(key); —— 复杂度 $O(1)$

## 相关数据结构学习
- vector ：就是用来平替掉我们之前使用的数组结构。同时我们vector内部的内容，可以引入unordered_map（哈希表）等其他常用的结构
  - `vector<vector<int>> nums(n+1,vector<int>(m+1,0));`:在确定大小的时候我们使用的二维vector的方法；
    - `vector<vector<pair<double,double>>> arr;`:直接可以实现arr[i]访问其中的数据
  - `vec.push_back()`;使用pair等用{}
  - `vec.empty()`
  - `vec.size()`
  - `vec.reserve(k)`
  - `arr.insert(arr.begin() + i + 1, x);`在第i个数据和第i+1个数据中间插入一个x的数据。使用insert不用我们自己完成模拟

- stack：栈。
  - `stk.push()`
  - `stk.top()`
  - `stk.pop()`

- string
  - `str.append()`
  - `str.length()`
  - `str.substr(start,end)`*[)*
  - `str.substr(i)`*[i,+INF)*

- `unordered_map<key,value> m` ： 哈希表。
  - 我们在使用的的时候一般key和value的数据类型是不一样的
  - 相较于pair的优势是能够使用m[key]来定位到对应的值
  - `m.find(key)`
    - 找到就返回指向该元素的迭代器，找不到就返回 end()。
    - 可以用来判断是否存在
  - `count(key)`
    - 只是判断这个键出现了几次。对于 map 和 unordered_map，因为键唯一，所以通常只会返回 0 或 1。

- `unordered_set`:哈希集合
  - 基于哈希表实现，存储唯一元素（不重复），不保证元素顺序，平均 O(1) 的插入、删除和查找效率
  - 遍历的时候可以发现值是无序的
  - count：跟unordered_map一致//返回键的次数
  - insert: 直接插入一个key的值
  - erase
    - 按值删除 — 返回删除的元素个数（0 或 1）
    - 按迭代器删除 — 返回下一个有效迭代器
    - 按范围删除 — 删除 [first, last) 范围内的元素

- `map<map,value>`:其本身是有序的，但是是按照key升序进行排列的

- `pair<string,int>`:使用pair来进行处理，就是将两个不同的数据类型合并成一个单元。
  - `vector<pair<string,int>>`：能够使用sort来快速排序
    - `sort(vec.begin(),vec.end(), [](const auto& a, const auto& b){return a.second<b.second}`:这里是使用完成的形式进行sort的操作

- `priority_queue`:堆。也就是我们实现的优先队列。
  - 使用的头文件是`#include<queue>`
  - 在默认情况下，我们创建的heap是maxheap，也就是顶部是max值的堆
    - minHeap：`priority_queue<int, vector<int>, greater<int>> pq;`
    - maxHeap:`priority_queue<int>;`
    - 相关原因见于后面对于Lambda的分析
  - 常使用的func主要就是：`push()`,`pop()`,`top()`,`empty()`等这些queue中常用的func
    - 在使用`push()`,`pop()`等相关func的时候，复杂度是O(logn)。在执行这些命令的时候是使用了堆的原则进行了处理


**关于使用结构体时候的处理方法**
- 使用Lambda表达式
```cpp
std::sort(vec.begin(), vec.end(), [](const Node& a, const Node& b) {
    return a.data < b.data; // 升序排列
});
//主要的记忆点就是：中间我们使用的[]之后部分都是一个lambda的表达式，于是是作为sort的一个参数存在的
```
- 使用重载的方法
```cpp
struct Node {
    int id;
    int data;

    // 重载小于号运算符
    bool operator<(const Node& other) const {
        return this->data < other.data; 
    }
};

// ... 在主函数中 ...
std::sort(vec.begin(), vec.end()); // 此时不需要写第三个参数了
```


## cpp中使用快读：
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
endl->'\n'//endl本质上是要对于输出缓冲区进行刷新，使用快读的时候要搭配这个才能保证我们读取的速率
```

在当前的代码中要求读入一整行的数据，但是没有提前跟你说明相关的数据量的时候：
```cpp
  string line;
  getline(cin,line);
  vector<int>arr;
  int num;
  stringstream ss(line);//自动处理多余的空格和字符
  while(ss>>num){
    arr.push_back(num);
  }
```
**Attention**
- 看看这样的读入一整行的数据的问题的时候，前面如果有'\n'需要使用`cin.ignore()`把缓存库中的换行符给去除

## 使用银行家算法进行处理：
银行家舍入处理：主要就是笨笨cpp最人下人的一集
```cpp
double r(double n){
    int sign = (n < 0) ? -1 : 1;
    double tempValue = fabs(n * 1000000.0);//这里必须使用fabs是因为abs仅仅针对整形使用会在这里强制转化成整形
    double tempPart = floor(tempValue);
    double diff = tempValue - tempPart;//我们主要就是对于其中的差值进行分析
    long long base = (long long)tempPart;
    double tiny = 1e-12;
    if(diff>0.5+tiny){
        tempValue = tempPart+1;
    }
    else if(diff<0.5-tiny){
        tempValue = tempPart ;
    }
    else{
        if(base%2==0)
            tempValue = tempPart;
        else
            tempValue = tempPart + 1;
    }
    double ans = sign*tempValue / 1000000.0;
    return ans;
}
```
//以上就是我们使用的对于银行家舍入进行的处理

## vector数组的去重操作
对于vector内部的数据进行去重的操作
```cpp
void removeDuplicates(std::vector<int>& arr) {
    if (arr.empty()) return;

    // 1. 先排序，让重复的元素排在一起
    std::sort(arr.begin(), arr.end());

    // 2. 使用 unique 将重复元素移动到末尾，并返回指向第一个重复元素的迭代器
    auto last = std::unique(arr.begin(), arr.end());

    // 3. 擦除末尾多余的元素
    arr.erase(last, arr.end());
}
```

## Lambda 方法及其使用方法
1. 首先是我们使用Lambda的时候想要带上其他比较函数的处理方法：
``` cpp
// 1. 定义并存储 Lambda 表达式
auto cmp = [&value](int a, int b) {
    // 假设是按 value 数组里的值进行某种比较
    return value[a] < value[b]; 
};

sort(label[0].begin(), label[0].end(), cmp);
```

2. 我们之前使用的sort函数其实都是使用到了一次性的Lambda函数，于是我们是可以使用Lambda函数的形式来进行解决
```cpp
auto cmp = [](const auto &a, const auto &b) {
    return a > b; 
};

sort(label[i].begin(), label[i].end(), cmp);
```
这种方法仅限于我们所说的**模板函数**，也就是类似于sort，max，swap

3. 在我们使用类模板并且需要用户自定义比较规则和hash规则的容器，在使用Lambda表达式的时候是有额外的要求的：
```cpp
//对于heap进行处理
//实现minHeap的方法
auto cmp = [](int a, int b) { return a > b; };//这里比较反常的是使用a>b实现的是minHeap，用a<b是maxHeap
//其中的逻辑可以理解为是：cmp是用来表示堆中相关元素的优先级的；使用a<b->大的数字优先级高->形成的是maxHeap；这也是为啥默认形成的heap是maxheap的原因
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

//创建一个按照字符串长度排序的 set
auto cmp = [](const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b; // 长度相同时按字典序
};
// 需要用 decltype(cmp) 提取类型填入模板参数，并在构造函数传入 cmp 实例
set<string, decltype(cmp)> mySet(cmp);
mySet.insert("apple");
mySet.insert("hi");
mySet.insert("banana");

//创建一个 Key 为整数，但按照绝对值大小排序的 map
auto absCmp = [](int a, int b) {
    return abs(a) < abs(b);
};

map<int, string, decltype(absCmp)> myMap(absCmp);

myMap[-10] = "negative ten";
myMap[5] = "five";
myMap[-2] = "negative two";
```
在使用上面的类模板中，注意不仅仅是在前面类型中要添加Lambda表达式，在后面函数对象的部分也是要添加Lambda表达式来实现；

## stringstream处理未给出明确数量的输入
```cpp
string line;
getline(cin, line);
stringstream ss(line);
string str1;
while (ss >> str1)
{
  //输入到对应的数组中
}
```
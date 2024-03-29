# LeetCode Practice

1. 优秀的leetcode刷题集锦：
	+ https://books.halfrost.com/leetcode/ChapterOne/
	+ https://www.programmercarl.com/

## 1. DataStructure

### 1.1 Hash Table

### 1.2 List, Stack, Queue

+ List（链表）：
+ 剑指offer分类：
	+ 面试题6：从尾到头打印链表
	+ 面试题18：删除链表的节点
	+ 面试题22：链表中导数第k个节点
	+ 面试题23：链表中换的入口节点
	+ 面试题24：反转链表
	+ 面试题25：合并两个排序的链表
	+ 面试题35：复杂链表的复制
	+ 面试题36：二叉搜索树与双向链表
	+ 面试题52：两个链表的第一个公共节点

+ 如何构造递归？如何构造头结点？常见题目：
	+ 链表区间逆序：92
	+ 链表寻找中间节点。第 876 题。链表寻找倒数第 n 个节点。第 19 
	+ 合并 K 个有序链表。第 21 题，第 23 题。
	+ 链表归类。第 86 题，第 328 题。
	+ 链表排序，时间复杂度要求 O(n * log n)，空间复杂度 O(1)。只有一种做法，归并排序，至顶向下归并。第 148 题。
	+ 判断链表是否存在环，如果有环，输出环的交叉点的下标；判断 2 个链表是否有交叉点，如果有交叉点，输出交叉点。第 141 题，第 142 题，第 160 题。

+ Stack_Queue：

	[单调栈总结](./docs/单调栈专题总结.md)

+ 剑指offer分类：
   + 面试题09-用两个栈实现队列
   + 面试题30-包含min函数的栈
   + 面试题31-栈的压入、弹出序列
   + 面试题58-1-翻转单词顺序
   + 面试题59-1-滑动窗口的最大值

+ 栈和队列都不能被归类为容器。stack可以用vector, deuqe, list进行实现。栈先进后出。队列先进先出。
	
	常见的算法问题(stack用于进行元素匹配)

	+ 括号匹配问题
	+ 字符串去重(删除重复且相邻的元素)
	+ 逆波兰表达式
	+ 滑动窗口最大值（单调队列）
	+ 求K个高频元素（优先队列）

+ queue（队列）：

+ heap（堆）：完全二叉树。树中每个结点的值都不小于（或不大于）其左右孩子的值。 如果父亲结点是大于等于左右孩子就是大顶堆，小于等于左右孩子就是小顶堆。大家经常说的大顶堆（堆头是最大元素），小顶堆（堆头是最小元素）。

### 1.3 BinaryTree

详情见：[二叉树总结](./docs/二叉树总结.md)

### 1.4 String

+ 剑指offer分类：
	+ 面试题5：替换空格
	+ 面试题19：正则表达式匹配
	+ 面试题20：表示数值的字符串
	+ 面试题38：字符串的排列
	+ 面试题46：把数字翻译成字符串
	+ 面试题58：翻转字符串

### 1.5 Array

+ 数组考点（利用vector实现）： 连续内存空间的集合。数组元素是不能删除的，只能覆盖，**因此可考察数组移除元素（利用双指针法）**。int是4个字节。还有**滑动窗口、二分法**的技巧。
+ 连续子数组个数

+ 剑指offer分类：
	+ 面试题3（I,II）：数组中重复的数字
	+ 面试题4：二维数组中的查找
	+ 面试题21：调整数组顺序使技术位于偶数前面
	+ 面试题42：连续子数组的最大和
	+ 面试题50：第一个只出现一次的字符
	+ 面试题56：数组中数字出现的次数

## 2. Algorithmn

### 2.1 DP

详见：[动态规划专题](./docs/%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E4%B8%93%E9%A2%98.md)

### 2.2 Recursion

如何写一段完美的递归函数？

1. 确定该任务是否可分？（比如常见的反转链表、计算n次幂、机器人移动范围等等）
2. 确定该任务的终止条件。（写在recursion函数的第一排）
3. 如果没有到中止条件，则进行递归计算
    1. 首先写递归函数进行迭代
    2. 然后写递归的计算部分

### 2.3 DFS\BFS

解题关键：找到递归终止条件

相关例题：

1. lc200确定岛屿数量
2. 剑指offer55_二叉树的第k个节点
3. 机器人运动范围

### 2.4 Greedy

### 2.5 BisectionMethod (二分法)

### [二分法详解](./docs/查找-二分法.md)

### 2.6 Backtracking (回溯)

### [回溯类解法](./docs/%E5%9B%9E%E6%BA%AF-%E7%BB%84%E5%90%88%E6%8E%92%E5%88%97%E7%B1%BB%E9%97%AE%E9%A2%98.md)

### 2.7 Sort(全排列、快速排列) \ find(查找)

+ 全排列：给定一个数组，返回所有的排列的可能性。【本质是回溯算法】

+ 快排模板：
```c++
void quickSort(vector<int>& arr, int l, int r) {
	// 子数组长度为 1 时终止递归
	if (l >= r) return;
	// 哨兵划分操作（以 arr[l] 作为基准数）
	int i = l, j = r;
	while (i < j) {
		// 在右侧找到比基准小的，左侧找到比基准大的，然后交换
		// 括号里里面写判断条件，这里arr[l]作为基准，i<j这个条件必须要有
		while (i < j && arr[j] >= arr[l]) j--;
		while (i < j && arr[i] <= arr[l]) i++;
		swap(arr[i], arr[j]);
	}
	// 交换基准数
	swap(arr[i], arr[l]);
	// 递归左（右）子数组执行哨兵划分
	quickSort(arr, l, i - 1);
	quickSort(arr, i + 1, r);
    }
```

+ 剑指offer分类：

+ 面试题11：旋转数组的最小数字
+ 面试题39：数组中出现次数超过一半的数字
+ 面试题40：最小的k个数
+ 面试题41：数据流中中位数
+ 面试题51：数组中的逆序对
+ 面试题53：在排序数组中查找数字
+ 面试题57：和为s的数字
+ 面试题60：n个骰子的点数

### 2.8 Dynamic Window(滑动窗口)

要点为如何计算窗口的长度、起点，窗口移动条件。

相关题：

3. 无重复字符的最长子串
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    }
        return maxStr;
        
    }
};
```

30. 串联所有单词的子串

76. 最小覆盖子串

159. 至多包含两个不同字符的最长子串

209. 长度最小的子数组

239. 滑动窗口最大值

567. 字符串的排列

632. 最小区间

727. 最小窗口子序列

## 3. 机考C++常见的输入输出

### 3.1 input

#### 1. 空格' '作为分割符，输入字符串
```c++
string s;
getline(cin, s);
```

#### 2. 给定数目多字符串
```c++
// input: 3 abc ab a
int n;
cin >> n; // 读入3，说明字符串数组的大小是3
vector<string> strings(n); // 创建大小为3的vector<string>
for(int i = 0; i < n; i++) {
	cin >> strings[i];
}

// 验证是否读入成功
for(int i = 0; i < strings.size(); i++) {
	cout << strings[i] << " ";
}
cout << endl;
```

#### 3. 不定数目多字符串
```c++
vector<string> strings;
string str;
while(cin >> str) {
	strings.push_back(str);
	// 读到换行符，终止循环
	if(getchar() == '\n') {
		break;
	}
}

// 验证是否读入成功
for(int i = 0; i < strings.size(); i++) {
	cout << strings[i] << " ";
}
cout << endl;
```

#### 4. 空格分割，输入数组

```c++
vector<int> nums(5);
for(int i = 0; i < nums.size(); i++) {
	cin >> nums[i];
}
// 输出读入的数组
for(int i = 0; i < nums.size(); i++) {
	cout << nums[i] << " ";
}
```

#### 5. 逗号','间隔的整数
```c++
/*
2 3
1,2,3
1,2,3
*/
int m; // 接收行数
int n; // 接收列数

cin >> m >> n;

vector<vector<int>> matrix(m);

for(int i = 0; i < m; i++) {
    // 读入字符串
	string s;
	getline(cin, s);
	
	// 将读入的字符串按照逗号分隔为vector<int>
	vector<int> vec;
	int p = 0;
	for(int q = 0; q < s.size(); q++) {
		p = q;
		while(s[p] != ',' && p < s.size()) {
			p++;
		}
		string tmp = s.substr(q, p - q);
		vec.push_back(stoi(tmp));
		q = p;
	}
	
	//写入matrix
	matrix[i] = vec;
	vec.clear();
}

// 验证是否读入成功
for(int i = 0; i < matrix.size(); i++) {
	for(int j = 0; j < matrix[i].size(); j++) {
		cout << matrix[i][j] << " ";
	}
	cout << endl;
}
```

#### 6. 常规输入
```c++
/*
2 3
1 2 3
1 2 3
*/
int m; // 接收行数
int n; // 接收列数

cin >> m >> n;

vector<vector<int>> matrix(m, vector<int>(n));

for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
		cin >> matrix[i][j];
	}
}

// 验证是否读入成功
for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
		cout << matrix[i][j] << " ";
	}
	cout << endl;
}
```

## 4. 常见数据结构的时间复杂度


# LeetCode Practice

## 1. DataStructure

### 1.1 Hash Table

### 1.2 List, Stack, Queue

### 1.3 BinaryTree

## 2. Algorithmn

### 2.1 DP

### 2.2 Recursion

如何写一段完美的递归函数？

1. 确定该任务是否可分？（比如常见的反转链表、计算n次幂、机器人移动范围等等）
2. 确定该任务的终止条件。（写在recursion函数的第一排）
3. 如果没有到中止条件，则进行递归计算
    1. 首先写递归函数进行迭代
    2. 然后写递归的计算部分

### 2.3 DFS

### 2.4 Greedy

### 2.5 BisectionMethod (二分法)

### 2.6 Backtracking (回溯)


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
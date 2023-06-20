class A;

A* Array[2];

class A {
public:
   virtual int sum(int n) {
       return 0;
   }
};

class B : public A {
public:
   virtual int sum(int n) {
       return Array[!!n]->sum(n - 1) + n;
   }
};

class Solution {
public:
   int sumNums(int n) {
       A a;
       B b;
       Array[0] = &a;
       Array[1] = &b;
       return Array[1]->sum(n);
   }
};
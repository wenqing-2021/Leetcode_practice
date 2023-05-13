#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> a = {1,4,7,2,10,9};
    for (int i = 0; i < a.size() - 1; ++i){
        for (int j = 0; j < a.size() - 1 - i; ++j){
            if (a[j] > a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
    for (auto num : a){
        cout << num << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

double ComputeMiddle(double& middle){
    return pow(middle, 2) + middle - 1;
}

double Caculate(){
    // x**5 + x = 1, 二分法求解
    double error = 0.000001;
    double solution;
    double left = 0.0;
    double right = 1.0;
    while (left < right){
        double middle = left + (right - left) / 2.0;
        double y = ComputeMiddle(middle);
        if (abs(y) < error){
            cout << middle << endl;
            return middle;
        }
        if (y > 0){
            right = middle;
        }
        if (y < 0){
            left = middle;
        }
    }
    return 0;
}

int main(){
    Caculate();
    return 0;
}
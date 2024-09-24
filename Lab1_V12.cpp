#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double hx = 2, hy = 1, E = 0.0001, z;
    
    for(double x = 1; x <= 10; x += hx)
        for(double y = -4; y <= 3; y += hy) {
            if(x > y) {
                z = pow(x, 2) / pow(x - 5, 3);
            } else {
                z = pow(x - 2, 3) / (y * pow(x - 5, 4));
            }
            cout << "x = " << x <<"\t";
    cout << "y = " << y <<"\t";
    cout << "z = " << z <<endl;
        }
    
    return 0;
}

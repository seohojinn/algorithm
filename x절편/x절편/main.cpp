#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int a = 0, b = 0;
    float c;
    cin >> a >> b;
    
    b *= -1;
    
    c = b / a;
    
    printf("%.4f\n",round(c * 100000) / 100000);

    
    return 0;
}

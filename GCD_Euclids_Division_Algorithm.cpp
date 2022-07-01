#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    while (a != b){
        if(a > b){
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    int x, y;
    cin >> x;
    cin >> y;
    cout<< "The GCD of the given numbers is " << gcd(x, y) << endl;
    return 0;
}
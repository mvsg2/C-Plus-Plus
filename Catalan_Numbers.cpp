#include <iostream>
using namespace std;
unsigned long int Catalan(int n)
{
    if (n <= 1){
        return 1;
    }
    unsigned long int res = 0;
    for(int i = 0; i < n; i++){
        res += Catalan(i) * Catalan(n - i -1);
    }
    return res;
}

int main()
{
    unsigned long int m;
    cin >> m;
    string s;
    if (m == 1){
        s = "st";
    }
    else if (m == 2){
        s = "nd";
    }
    else if (m == 3){
        s = "rd";
    }
    else{
        s = "th";
    }
    cout << "The " << m <<s<< " Catalan number is " << Catalan(m) << endl;
    return 0;
}
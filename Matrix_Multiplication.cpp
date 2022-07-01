#include <iostream> 
using namespace std;
int main()
{
    int m = 3, n = 4, p = 5;
    int A[m][n];
    int B[n][p];
    int C[m][p];

    cout << "Enter the elements of the first matrix: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
    
    cout << "Enter the elements of the second matrix: " << endl;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            cin >> B[i][j];
        }
    }

    for (int i=0; i < m; i++){
        for(int j = 0; j < p; j++){
            for (int k = 0; k < n; k++){
                C[i][j] = 0;
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    cout << "The resultant matrix is: " << endl;
    for(int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// In multipying two matrices of sizes (m by n) and (n by p), the total number of multiplications/computations is m*n*p.
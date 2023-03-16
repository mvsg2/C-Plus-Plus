#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#define PI 3.141592653589793
using namespace std;

template <typename T>
void operator + (T &element1, T &element2){
    cout << element1 + element2 << endl;
}

template <typename T>
T Add(T num1, T num2){
    return num1 + num2;
}

template <typename T>
void operator - (T &element1, T &element2){
    cout << element1 - element2;
}

template <typename T>
T Subtract(T num1, T num2){
    return num1 - num2;
}

template <typename T>
T Mutlitply(T num1, T num2){
    return num1*num2;
}

float Divide(int num1, int num2){
    return num1 / num2;
}

int floor_division(int num1, int num2){
    // return int(num1/num2);
    return floor(num1/num2);
}

int ceiling_division(int num1, int num2){
    return ceil(num1/num2);
}

float logarithm(float num){
    return log(num);
}

float logarithm_10(float num){
    return log10(num);
}

int randomIntegerGenerator(int lower, int upper){
    // This program will create some sequence of random
    // numbers on every program run within range lb to ub
    srand(time(0));
    return (rand() % (upper - lower + 1)) + lower;
}

float randomFloat(){
    return (float) (rand()) / (float)(rand());  // if you want between 0 and 1, then use RAND_MAX keyword in the denominator 
}

float randomFloatGenerator(){
    srand(time(0));
    return (float)(rand()) / (float)(RAND_MAX);
}

template <typename T>
void printArray(T* arr, int n){
    // if (n != sizeof(arr)/sizeof(arr[0])){
    //     cout << "Not valid!" << endl;
    //     exit(0);
    // }
    for (int i=0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
vector<T> concatArrays(vector<T> &v1, vector<T> &v2){
	for (int i=0; i < v2.size(); i++)
		v1.push_back(v2[i]);
	return v1;
}

template <typename T>
void takingUserInputVector(vector<T> &v, int size){
	for(int i=0; i < size; i++){
		T el;
		cin >> el;
		v.push_back(el);
	}
}

int Factorial(int n){
    if (n < 0){
        cout << "Cannot compute factorial of negative numbers!" << endl;
        exit(0);
    }
    int fac = 1;
    while (n > 1){
        fac *= n;
        n -= 1;
    }
    return fac;
}

double vectorNorm_l2(vector<float> &vector){
    double norm = 0.;
    for(int i=0; i<vector.size(); i++) norm += vector[i]*vector[i];
    return sqrt(norm);
}

void normalizeVector(vector<float> &vector){
    if (vectorNorm_l2(vector) == 1.) cout << "The vector is already normalized!";
    else{
        float norm = vectorNorm_l2(vector);
        for (int i = 0; i < vector.size(); i++)
            vector[i] /= norm;
    }
}

double innerProduct(vector<float> &v1, vector<float> &v2){
    double sum = 0.;
    if(v1.size() != v2.size()) cout << "The vectors are not of equal sizes!" << endl;
    else{
        for (int i = 0; i < v1.size(); i++) sum += v1[i]*v2[i];
    }
    return sum;
}

vector<vector<float>> outerProduct(vector<float> &v1, vector<float> &v2){
    vector<vector<float>> v;
    for (int i = 0; i < v1.size(); i++){
        vector<float> row;
        for (int j = 0; j < v2.size(); j++)
            row.push_back(v1[i]*v2[j]);
        v.push_back(row);
    }
    return v;
}

struct Matrix{
    private:
    int n_rows, n_cols;
    int shape[2] = {n_rows, n_cols};
    vector<vector<int>> v;
    public:
    Matrix(int n_rows, int n_cols){
        this->n_rows = n_rows;
        this->n_cols = n_cols;
        for (int i = 0; i < v.size(); i++){
            for (int j = 0; j < v[i].size(); j++) v[i][j]=0;
        }
    }
    void printMatrix2D(){
        for (int i = 0; i < n_rows; i++){
            for (int j = 0; j < n_cols; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};

template <typename T>
void printMatrix(vector<vector<T>> &matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[i].size(); j++) cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

float maximum(vector<float> &array){
    float max_el = array[0];
    int max_index;
    for(int i=0; i < array.size(); i++){
        if (array[i] > max_el) {max_el = array[i]; max_index = i;}
    }
    return max_el;
}

float minimum(vector<float> &array){
    float min_el = array[0];
    int min_index;
    for(int i=0; i < array.size(); i++){
        if (array[i] < min_el) {min_el = array[i]; min_index = i;}
    }
    return min_el;
}

vector<float> anotherVersionSelectionSort(vector<float> &unsorted_array){   // O(N^2)
    vector<float> sorted_array;
    while(!unsorted_array.empty()){
        float min = minimum(unsorted_array);
        sorted_array.push_back(min);
        unsorted_array.erase(find(unsorted_array.begin(), unsorted_array.end(), min));
    }
    return sorted_array;
}

template <typename T>
vector<T> reverse_vector(vector<T> v){
    vector<T> v1;
    for (int i=v.size()-1; i >=0; i--) v1.push_back(v[i]);
    return v1;
}

template <typename T>
void printVector(vector<T> &vector){
    for (int i=0; i < vector.size(); i++) cout << vector[i] << " ";
    cout << endl;
}

template <typename T>
void printVectorReversed(vector<T> &vector){
    for (int i=vector.size()-1; i >= 0 ; i--) cout << vector[i] << " ";
    cout << endl;
}

string reverse_string(string str){
    for(int i=0; i < str.length()/2; i++) swap(str[i], str[str.length()-i-1]);
    return str;
}

vector<int> get_digits(int n){ 
    // gets the digits of an integer, but in reversed order. Don't forget to use the above defined printVectorReversed() function
    vector<int> digits;
    while (n >= 10){
        digits.push_back(n%10);
        n /= 10;
    }
    digits.push_back(n);
    return digits;
}

bool isPalindrome(int n){
    vector<int> reversed_digits = get_digits(n);
    vector<int> digits = reverse_vector(reversed_digits);
    return (digits==reversed_digits) ? true : false;
}

bool isPalindromeString(string s){
    string reversed_string = reverse_string(s);
    return (s==reversed_string) ? true : false;
}

template <typename T>
void swap_elements(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(vector<float>& array){   // O(N^2)
    for (int i = 0; i < array.size()-1; i++){
        for (int j = 0; j < array.size() - i-1; j++){
            if (array[j] > array[j+1]){
                // swap(array[j], array[j+1]);
                float temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }   
        }
    }
}

void insertionSort(vector<float> &array){  // O(N^2)
    for(int i=1; i<array.size(); i++){
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

void selectionSort(vector<float> &array){  // O(N^2)
    for(int i=0; i < array.size()-1; i++){
        int min_idx = i;
        for (int j = i+1; j < array.size(); j++){
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        if(min_idx!=i)
            swap(array[min_idx], array[i]);
    }
}

int partition(vector<float> &array, int low, int high){
    int pivot = array[high];
    int i = low - 1;
    for(int j=low; j < high; j++){
        if(array[j] < pivot){
            i++;
            swap_elements(&array[i], &array[j]);
        }
    }
    swap_elements(&array[i+1], &array[high]);
    return i+1;
}

void quickSort(vector<float> &array, int low, int high){
    float pivot = array[high];
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi-1);
        quickSort(array, pi+1, high);
    }
}

class ComplexNumbers{
    private:
    double real_part, imaginary_part;
    public:
    ComplexNumbers(double real, double imaginary){
        this->real_part = real;
        this->imaginary_part = imaginary;
    }
    void printComplexNo(ComplexNumbers c){
        cout << c.real_part << " + " << c.imaginary_part << "j" << endl;
    }
    ComplexNumbers Add_ComplexNos(ComplexNumbers c1, ComplexNumbers c2){
        double total_real = c1.real_part + c2.real_part;
        double total_imaginary = c1.imaginary_part + c2.imaginary_part;
        ComplexNumbers c_total = ComplexNumbers(total_real, total_imaginary);
        // cout << total_real << " + " << total_imaginary << "j" << endl;
        return c_total;
    }
    ComplexNumbers Subtract_ComplexNos(ComplexNumbers c1, ComplexNumbers c2){
        double total_real = c1.real_part - c2.real_part;
        double total_imaginary = c1.imaginary_part - c2.imaginary_part;
        // cout << total_real << " + " << total_imaginary << "j" << endl;
        ComplexNumbers c_difference = ComplexNumbers(total_real, total_imaginary);
        return c_difference;
    }
    ComplexNumbers Multiply_ComplexNos(ComplexNumbers c1, ComplexNumbers c2){
        double total_real = c1.real_part*c2.real_part - c1.imaginary_part*c2.imaginary_part;
        double total_imaginary = c1.real_part*c2.imaginary_part + c1.imaginary_part*c2.real_part;
        ComplexNumbers c_product = ComplexNumbers(total_real, total_imaginary);
        // cout << total_real << " + " << total_imaginary << "j" <<  endl;
        return c_product;
    }
    void giveConjugate(ComplexNumbers c){
        cout << c.real_part << " - " << c.imaginary_part << "j" << endl;
    }
};

class Circle{
    double radius;
    public:
    double Circumference(double circle_radius){
        radius = circle_radius;
        return 2*PI*radius;
    }

    double Area(double circle_radius){
        radius = circle_radius;
        return PI*radius*radius;
    }
};

class Rectangle{
    double length, breadth;
    public:
    double Perimeter(double l, double b){
        length = l;
        breadth = b;
        return 2 * (length + breadth);
    }

    double Area(double l, double b){
        length= l; breadth = b;
        return length*breadth;
    }
};

class Triangle{
    double side1, side2, side3;
    public:
    double Perimeter(double a, double b, double c){
        side1 = a;
        side2 = b;
        side3 = c;
        if ((side1+side2<side3 || side2+side3<side1 || side1+side3<side2)){
            cout << "The given triplet cannot form a triangle!" << endl;
            exit(0);
        }
        return side1+side2+side3;
    }
    double Area(double a, double b, double c){
        side1= a; side2 = b; side3 = c;
        if ((side1+side2<side3 || side2+side3<side1 || side1+side3<side2)){
            cout << "The given triplet cannot form a triangle!" << endl;
            exit(0);
        }
        double semi_perimeter = (side1+side2+side3) / 2;
        return sqrt(semi_perimeter*(semi_perimeter-side1)*(semi_perimeter-side2)*(semi_perimeter-side3));
    }
    void isRightAngled(double a, double b, double c){
        side1 = a; side2 = b; side3 = c;
        if ((side1+side2<side3 || side2+side3<side1 || side1+side3<side2)){
            cout << "The given triplet cannot form a triangle!" << endl;
            exit(0);
        }
        if (((side1*side1 + side2*side2) == side3*side3) || ((side1*side1 + side3*side3) == side2*side2) || ((side2*side2 + side3*side3) == side1*side1))
            cout << "Yes, it is a right-angled triangle!" << endl;
        else cout << "No, it's not a right-angled triangle.";
    }
};
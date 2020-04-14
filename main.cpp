#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef double dd;
typedef vector<ll> vll;
typedef vector<dd> vd;

double relu(double x){
  return max(0.0,x);
}

class Genome{
  private:
    vector<vector<vector<double>>> weights;
    vector<vector<double>> biases;
    vector<int> shape;
    int mark;
  public:
    NeuralNetwork(vector<vector<vector<double>>> w, vector<vector<double>> b, vector<int> s, int m) {weights = w; biases = b; shape = s; mark = m;}
};


int main() {
  cout << "Hello World!\n";
}
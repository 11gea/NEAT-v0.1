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
typedef vector<int> vi;

int globalInnov = 0; 

double relu(double x){
  return max(0.0,x);
}

// -1 = input
// 0 = hidden
// 1 = output

class Node{
  public:
    int type; //-1 = input, 0 = hidden, 1 = output
    int id; //id of node
    vi prevNodes; 
    int activ;
    dd sum; 
    dd bias; 
  public:
    Node(int type, int id, vi prevNodes, dd bias, int activ = 0){
      type = type; 
      id = id; 
      prevNodes = prevNodes; 
      activ = activ; 
      bias = bias;
      sum = bias;
    }
};

class Connection{
  public:
    int innov;
    int from;  
    int to; 
    dd weight; 
  public:
    Connection(int innov, int from, int to, dd weight){
      //FIX INNOV NUMBER
      innov = globalInnov; //globalInnov starts at 0.
      from = form;
      to = to;
      weight = 0;
    }
};

class Agent{
  public:
    vector<Node> nodes;
    vector<Conn
  public:
    
};


int main() {
  cout << "Hello World!\n";
}
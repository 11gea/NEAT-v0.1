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
    void debug_print(){
      cout << "ID: " << id << endl;
      cout << "TYPE: " << type << endl;
      cout << "ACTIVATION: " << activ << endl;
      cout << "SUM: " << sum << endl;
      cout << "BIAS: " << bias << endl;
      cout << "PREVIOUS NODES: ";
      for (auto const&node:prevNodes){
        cout << node << ", ";
      }
      cout << endl;
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
      from = from;
      to = to;
      weight = weight;
    }
    void debug_print(){
      cout << "INNOV: " << innov << endl;
      cout << "FROM: " << from << endl;
      cout << "TO: " << to << endl;
      cout << "WEIGHT: " << weight << endl;
    }
};

class Agent{
  public:
    int numIn; //input nodes
    int numOut; // output nodes
    vector<Node> nodes;
    vector<Connection> connections;
  public:
    Agent(int numIn, int numOut){
      srand((unsigned)time(NULL));
      vi previous; // previous nodes for output
      for (int i=0; i<numIn; i++){
        nodes.push_back(Node(-1, i, {}, 0)); 
        previous.push_back(i); 
      }
      for (int i=0; i<numOut; i++){
        dd bias = dd(rand());
        nodes.push_back(Node(1, i+numIn, previous, bias)); 
      }

      for (int i=0; i<numIn; i++){
        for (int j=0; j<numOut; j++){
          dd weight = dd(rand());
          connections.push_back(Connection(globalInnov, i, j, weight));
          globalInnov++;
        }
      }
    }

    void debug_print(){
      cout << "NODES" << endl;
      // for (auto const&node:nodes){
      //   node.debug_print();
      //   cout << endl;
      // }
      // for (auto const&conn:connections){
      //   conn.debug_print();
      //   cout << endl;
      // }
      for (int i=0; i<nodes.size(); i++){
        nodes[i].debug_print();
        cout << endl;
      }
      for (int i=0; i<connections.size(); i++){
        connections[i].debug_print();
        cout << endl;
      }
    }
    //Find out what nodes go to a given node

};


int main() {
  cout << "\n";
  Agent FBIagent = Agent(3,2);
  FBIagent.debug_print();
}
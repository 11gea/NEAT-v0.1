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
dd maxRandom = 100;

double relu(double x){
  return max(0.0,x);
}

class Node{
  public:
    int type; //-1 = input, 0 = hidden, 1 = output
    int id; //id of node
    vi prevNodes; 
    int activ;
    dd sum; 
    dd bias; 
  public:
    Node(int Type, int Id, vi PrevNodes, dd Bias, int Activ = 0, int Sum = 0){
      type = Type; 
      id = Id; 
      prevNodes = PrevNodes; 
      activ = Activ; 
      bias = Bias;
      sum = Sum+bias;
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
    Connection(int From, int To, dd Weight){
      //FIX INNOV NUMBER
      innov = globalInnov; //globalInnov starts at 0.
      from = From;
      to = To;
      weight = Weight;
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
    Agent(int numIn, int numOut, vd inputs){
      srand((unsigned)time(NULL));
      vi previous; // previous nodes for output
      for (int i=0; i<numIn; i++){
        nodes.push_back(Node(-1, i, {}, 0, 0, inputs[i])); 
        previous.push_back(i); 
      }
      for (int i=0; i<numOut; i++){
        dd bias = double(rand())*maxRandom/(double)RAND_MAX;
        nodes.push_back(Node(1, i+numIn, previous, bias, 0, 0)); 
        // int type, int id, vi prevNodes, dd bias, int activ = 0, int sum = 0
      }

      for (int i=0; i<numIn; i++){
        for (int j=0; j<numOut; j++){
          dd weight = double(rand())*maxRandom/(double)RAND_MAX;
          connections.push_back(Connection(i, j, weight));
          globalInnov++;
        }
      }
    }

    void debug_print(){
      cout << "NODES" << endl;
      for (auto node:nodes){
        node.debug_print();
        cout << endl;
      }
      cout << "CONNECTIONS" << endl;
      for (auto conn:connections){
        conn.debug_print();
        cout << endl;
      }
    }

    // vd run_ntwrk(vd inputs){
    //   for (int i=0; i<numIn){
    //     nodes[i].sum = inputs[i]; 
    //   }
    //   for 
    // }

    void get_sums(int id){
      Node curNode = nodes[id];
      for (auto vertex:curNode.prevNodes){
        if (vertex.type != -1){ //else we've reached the end
          get_sums(vertex);
          curNode.sum += vertex.sum;
        } else {
          curNode.sum += vertex.sum;
        }
      }
    }

    // for (i in outputs){
    //   push f(i.pre)
    // }
    // return list

    // f(int pre) {
    //   int sum
    //   if pre.leng is 0{
    //     return sum
    //   } else {
    //     for ( i in pre) {
    //       sum += f(i.pre)
    //     }
    //   }
    //   return activation(sum)
    // }

    //Find out what nodes go to a given node

};


int main() {
  cout << "\n";
  Agent FBIagent = Agent(3,2, {0,0,1});
  FBIagent.debug_print();
  FBIagent.get_sums();
  // Node X = Node(-1, 10, {}, 0);
  // X.debug_print();
}
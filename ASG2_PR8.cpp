/*

8. You’re a government consultant  and you’re trying to figure out the best way to arrange for Internet access in your small island, Sunderban. There are N (3 ≤ N ≤ 250) villages on your island connected by M (N ≤ M ≤ 250) various roads and you can walk between any two villages on the island by traversing some sequence of roads. However, you’ve got a limited budget and have determined that the cheapest way to arrange for internet access is to build some fiber-optic cables along existing roadways. You have a list of the costs of laying fiber-optic cable down along any particular road, and want to figure out how much money you’ll need to successfully complete the project–meaning that, at the end, every village will be connected along some sequence of fiber-optic cables. Luckily, you’re also Sunderban’s resident computer scientist, and you remember hearing about Prim’s algorithm in one of your old programming classes. This algorithm is exactly the solution to your problem, but it requires a priority queue... Here’s the C++ standard template library to the rescue.

*/
#include<iostream>
#include<cstdlib>
#include<list>
#include<climits>
#include<queue>
#include<set>

using namespace std;

class Graph{

private:
    int V;
    list<pair<int,int> > * adj;//Using C++ Stl for list
    friend void primMST(const Graph& graph,set<int>& covered,int i);//Function For Prims' Algorithm

public:
    Graph(int V){//Initialisation of graph
         this->V=V;
         adj = new list<pair<int,int> >[V + 10];
    }
    void addEdge(int v,int w,int wt){//Function to add edge
         adj[v].push_back(pair<int,int>(w,wt));
         adj[w].push_back(pair<int,int>(v,wt));
    }
};//End of Class Graph

struct heapNode{//Structure for Heap Node
    friend void primMST(const Graph& graph,set<int>& covered,int i);
    int v;
    int dest;
    int key;
    heapNode(int init,int final,int prior){
        v = init;
        dest = final;
        key = prior;
    }
    int get_key(){
        return key;
    }
};

bool operator >(const heapNode& lhs,const heapNode& rhs){
    return lhs.key > rhs.key;
}

void primMST(const Graph& graph,set<int>& covered,int i) {//Function for Prims algo
    covered.insert(i);
    priority_queue<heapNode,vector<heapNode>,greater<heapNode> > pq;

    list<pair<int,int> >::iterator idx;

    for(idx = graph.adj[i].begin(); idx!=graph.adj[i].end(); idx++){
           pq.push(heapNode(i,idx->first,idx->second));
    }

    vector<pair<int,int> > temp;

    while(covered.size() != graph.V){
        if(covered.find((pq.top()).dest) == covered.end()){
            int j = (pq.top()).dest;
            covered.insert(j);

            temp.push_back(pair<int,int> ((pq.top()).v,(pq.top()).dest));

            for(idx=graph.adj[j].begin();idx!=graph.adj[j].end();idx++){
                if(covered.find(idx->first)==covered.end()){
                   pq.push(heapNode(j,idx->first,idx->second));
                }
            }
        }
        else {
            pq.pop();
        }
    }

    vector<pair<int,int> >::iterator it;
    for(it=temp.begin();it!=temp.end();it++){
        cout<< it->first<<" - "<<it->second<<endl;
    }
}//End of function primMST

int main(void){
    int vertex;
    int edge,ref_edge;
    int v,w,wt;
    cout<<"Enter the no. of vertices in the graph : ";
    cin>>vertex;
    cout<<endl;
    Graph graph(vertex);
    cout<<"Enter the no. of edges in the graph : ";
    cin>>edge;
    cout<<endl;
    ref_edge=edge;
    while(ref_edge--){
        cout<<"Enter the vertices which you would like to connect : ";
        cin>> v >> w;
        cout<<endl;
        cout<<"Enter the weight of the edge : ";
        cin>> wt;
        cout<<endl;
        graph.addEdge(v,w,wt);
    }

    set<int> covered;
    int choice;
    cout<<"Enter a start vertex : ";
    cin>>choice;
    cout<<endl;

    primMST(graph,covered,choice);
    return 0;
}//End of main()

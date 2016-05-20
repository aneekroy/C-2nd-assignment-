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
    list<pair<int,int> > * adj;
    friend void primMST(const Graph& graph,set<int>& covered,int i);

public:
    Graph(int V){
         this->V=V;
         adj = new list<pair<int,int> >[V + 10];
    }
    void addEdge(int v,int w,int wt){
         adj[v].push_back(pair<int,int>(w,wt));
         adj[w].push_back(pair<int,int>(v,wt));
    }
};

struct heapNode{
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

void primMST(const Graph& graph,set<int>& covered,int i) {
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
}

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
}

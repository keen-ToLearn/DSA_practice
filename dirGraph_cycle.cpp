//detect cycle in directed graph using DFS
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(){}
        Node(int data){
            this->data=data;
            next = NULL;
        }
};

class LL{
    public:
        Node *start;

        void insertNode(int data){
            Node *tmp = new Node(data);
            if(start == NULL){
                start = tmp;
                return;
            }
            Node *p = new Node();
            p = start;
            while(p->next != NULL)
                p = p->next;
            p->next = tmp;
        }

        void display(){
            Node *p = new Node();
            p = start;
            while(p != NULL){
                cout << "-> " << p->data;
                p = p->next;
            }
            cout << "\n";
        }
};

class Graph{
    public:
        int v;
        LL *ll;

        Graph(int v){
            this->v = v;
            ll = new LL[v];
        }

        void addEdge(int i, int j){
            ll[i].insertNode(j);
        }

        void displayGraph(){
            for(int i=0; i<v; i++){
                cout << i << ": ";
                ll[i].display();
            }
        }

        bool hasCycle(int start, bool visited[1000000], bool recStack[1000000]){
            visited[start]=true;
            recStack[start]=true;
            for(int i=0; i<v; i++){
                if(!visited[i] && hasCycle(i, visited, recStack))
                    return true;
                else if(recStack[i])    //if node i is in recursion stack => there is a back-edge to node i
                    return true;
            }
            recStack[start]=false;
            return false;
        }

        //outer function to find cycle in disconnected graph
        bool detectCycle(){
            bool visited[v], recStack[v];
            for(int i=0; i<v; i++){
                if(!visited[i] && hasCycle(i, visited, recStack))
                    return true;
            }
            return false;
        }
};

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.displayGraph();
    bool cycle = g.detectCycle();
    if(cycle)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
//detect cycle in undirected graph using DFS
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node() {}
        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

class LL {
    public:
        Node *start;

        void insertNode(int data) {
            Node *tmp = new Node(data);
            if(start == NULL) {
                start = tmp;
                return;
            }
            Node *p = new Node();
            p = start;
            while(p->next != NULL)
                p = p->next;
            p->next = tmp;
        }

        void display() {
            Node *p = new Node();
            p = start;
            while(p != NULL) {
                cout << "-> " << p->data;
                p = p->next;
            }
            cout << "\n";
        }
};

class Graph {
    public:
        int v;
        LL *ll;

        Graph(int v) {
            this->v = v;
            ll = new LL[v];
        }

        void addEdge(int i, int j) {
            ll[i].insertNode(j);
            ll[j].insertNode(i);
        }

        void displayGraph() {
            for(int i=0; i<v; i++) {
                cout << i << ": ";
                ll[i].display();
            }
        }

        bool hasCycle(int start, bool visited[1000000], int parent) {
            visited[start] = true;
            for(int i=0; i<v; i++) {
                if(!visited[i] && hasCycle(i, visited, start))
                    return true;
                else if(i != parent)    //if node i has been visited but, it is not the parent of start => cycle exists
                    return true;
            }
            return false;
        }

        //outer function to find cycle in a disconnected graph
        bool detectCycle() {
            bool visited[v];
            for(int i=0; i<v; i++)
                if(!visited[i] && hasCycle(i, visited, -1))
                    return true;
            return false;
        }
};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.displayGraph();
    bool cycle = g.detectCycle();
    if(cycle)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
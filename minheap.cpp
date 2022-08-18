//MinHeap
#include <iostream>
#include <utility>
#include <climits>
using namespace std;

class MinHeap{
    int *heaparr;
    int capacity;
    int heapsize;
    
    public:
    
    MinHeap(int capacity){
        this->capacity = capacity;
        heapsize = 0;
        heaparr = new int[capacity];
    }
    
    int parent(int i){
        return (i-1)/2;
    }
    
    int left(int i){
        return 2*i+1;
    }
    
    int right(int i){
        return 2*i+2;
    }
    
    int getMin(){
        return heaparr[0];
    }
    
    void insert(int val);
    void decreaseAVal(int i, int val);
    void heapify(int i);
    int extractMin();
    void deleteAVal(int i);
};

void MinHeap::insert(int val){
    if(heapsize + 1 > capacity){
        cout << "Max capacity reached\n";
        return;
    }
    int i = heapsize;
    heaparr[heapsize++]=val;
    while(i != 0 && heaparr[i] < heaparr[parent(i)]){
        swap(heaparr[i], heaparr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseAVal(int i, int val){
    heaparr[i] = val;
    
    while(i != 0 && heaparr[i] < heaparr[parent(i)]){
        swap(heaparr[i], heaparr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heapsize && heaparr[i] > heaparr[l])
        smallest = l;
    if(r < heapsize && heaparr[smallest] > heaparr[r])
        smallest = r;
    if(smallest != i){
        swap(heaparr[i], heaparr[smallest]);
        heapify(smallest);
    }
}

int MinHeap::extractMin(){
    if(heapsize == 0)
        return INT_MAX;
    if(heapsize == 1){
        heapsize--;
        return heaparr[0];
    }
    int root = heaparr[0];
    heaparr[0]=heaparr[heapsize-1];
    heapsize--;
    heapify(0);
    return root;
}

void MinHeap::deleteAVal(int i){
    decreaseAVal(i,INT_MIN);
    extractMin();
}

int main()
{
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.deleteAVal(1);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseAVal(2, 1);
    cout << h.getMin();
    return 0;
}
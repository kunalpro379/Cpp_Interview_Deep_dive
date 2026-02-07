//each node either red or black
// root is always black
// no two red nodes can be adjacent
//every path from a node to its null has the same no. of black nodes
// alll nulll leaves are considered black
//how balanceing happens
// recoloring red to black to red
// roatations left roatations and right roatations
/*
Time Complexity :-
Search O of logn
Insert O of logn
Delete O of logn

where used? map and set and multiset multimap
java: treemap treeset

*/
enum Color {RED, BLACK};
class Node{
    public:
    int data; 
    Color color;
    Node* left, *right, *parent;
    Node(int val){
        this->data=val;
        this->color=color;
        left=right=parent=nullptr;
    }
};

class RedBlackTree{
    private: Node* root;
    public:
    RedBlackTree(){
        root=nullptr;
    }
}
int main(){
    RedBlackTree rdt;
    int keys[] = {10, 20, 30, 15, 25, 5};
    for(int x:keys){
        rdt.insert(x);
    }
    rdt.print();
    return 0;
}
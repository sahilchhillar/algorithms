//bfs using adjacency matrix
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define max 5

class bfs{
    //create a matrix
    int **arr;

    public:
    bfs(){
        //add rows to the matrix
        arr = new int*[max];

        //initializing the adjacency matrix to 0
        for(int i=0;i<max;i++){
            arr[i] = new int[max];
            for(int j=0;j<max;j++){
                arr[i][j] = 0;
            }
        }
    }

    //add edge in the matrix
    //undirected matrix 
    void addEdge(int start, int end){
        if(start >= max || start < 0 || end >= max || end < 0){
            cout<<"\nWrong node number";
            return;
        }else{
            arr[start][end] = 1;
            arr[end][start] = 1;
        }
    }

    //display the adjacency matrix
    void dispMatrix(){
        for(int i=0;i<max;i++){
            for(int j=0;j<max;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    /*
    Supply the starting node value to the function
    create a boolean vector and initialise it to false 
    create another vector to store the visited nodes and then traverse the node
    initially push the starting node to the vector and mark the node as visited
    store the node at the beginning in an integer and show it visited
    then remove that element from the beginning and traverse the node to find all the nodes that are connected to it
    store all the connected and not visited nodes of the vector
    and start again with the beginning node value of the vector
    */
    void bfsAlgo(int start){
        vector<bool> visited (max, false);
        vector<int> visNode;
        visNode.push_back(start);
        visited[start] = true;
        int nodeValue;

        while(!visNode.empty()){
            nodeValue = visNode[0];

            //print visited node
            cout<<"\nVisited node:"<<nodeValue;

            //remove the starting node from vector 
            visNode.erase(visNode.begin());

            //store the adjacent connected nodes to the visited node vector and mark them as visited
            for(int i=0;i<max;i++){
                if(arr[nodeValue][i] == 1 && (!visited[i])){
                    visNode.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }

    ~bfs(){
        cout<<"Memory released";
    }
};



int main(){
    bfs b;
    int choice, start;
    string node;

    do{
        cout<<"\n0.Enter 0 to exit";
        cout<<"\n1.Enter 1 to add an edge";
        cout<<"\n2.Enter 2 to display the matrix";
        cout<<"\n3.Enter 3 to perform bfs operation";
        cout<<"\n\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cin.ignore(1);
                cout<<"\nEnter the node numbers:";
                getline(cin,node);
                b.addEdge(((int)node[0] - 48), ((int)node[2] - 48));
                break;
            }
            case 2:{
                b.dispMatrix();
                break;
            }
            case 3:{
                cout<<"\nEnter the starting node:";
                cin>>start;
                b.bfsAlgo(start);
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout<<"\nWrong choice!!!";
            }
        }
    }while(choice != 0);

    return 0;
}
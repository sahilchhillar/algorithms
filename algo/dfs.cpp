//dfs using adjancency matrix
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define max 5

class dfs{
    int **arr;

    public:
    dfs(){
        //create max number of rows
        arr = new int*[max];

        //initialize the matrix to 0
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
        if (start >= max || start < 0 || end >= max || end < 0){
            cout << "\nWrong node number";
            return;
        }else{
            arr[start][end] = 1;
            arr[end][start] = 1;
        }
    }

    //display the adjacency matrix
    void dispMatrix(){
        for (int i = 0; i < max; i++){
            for (int j = 0; j < max; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    /*
    starts with the start node
    checks all the nodes conected to it and mark them visited if not visited yet
    like this the algorithm checks all the nodes one by one and also the nodes connected to them
    */
    void dfsAlgo(int start, vector<bool> &visited){
        cout<<"\nVisited node:"<<start;
        visited[start] = true;

        //check all the nodes in the graph
        for(int i=0;i<max;i++){
            //traverse the nodes connected to the current node and mark them visited
            if(arr[start][i] == 1 && (!visited[i])){
                dfsAlgo(i, visited);
            }
        }
    }
};  


int main(){
    dfs d;
    int choice, start;
    string node;

    do{
        cout<<"\n1.Enter 1 to enter an edge";
        cout<<"\n2.Enter 2 to display the matrix";
        cout<<"\n3.Enter 3 to perform dfs algorithm";
        cout<<"\n0.Enter 0 to exit";
        cout<<"\n\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:{
                cin.ignore(1);
                cout<<"\nEnter your node numbers:";
                getline(cin,node);
                d.addEdge(((int)node[0]-48), ((int)node[2]-48));
                break;
            }
            case 2:{
                d.dispMatrix();
                break;
            }
            case 3:{
                cout<<"\nEnter the start node:";
                cin>>start;
                vector<bool> visited(max, false);
                d.dfsAlgo(start, visited);
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
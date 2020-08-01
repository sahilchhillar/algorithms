//bfs using linked list
#include<iostream>
#include<cstring>
#include<list>
#include<vector>
using namespace std;

#define max 5

class bfs{
    //create a list
    list<int> *adj;

    public:
    //create max number of lists
    bfs(){
        adj = new list<int>[max];
    }

    //add an edge between the nodes
    void addEdge(int start, int end){
        if (start >= max || start < 0 || end >= max || end < 0){
            cout << "\nWrong node number";
            return;
        }else{
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
    }

    /*
    Supply the starting node value to the function
    create a boolean vector and initialise it to false 
    create another vector to store the visited nodes and then traverse the node
    initially push the starting node to the vector and mark the node as visited
    store the node at the beginning in an integer and show it visited
    then remove that element from the beginning and traverse the node to find all the nodes that are connected to it
    store all the connected and not visited nodes of the lists
    and start again with the beginning node value of the list
    */
    void bfsAlgo(int start){
        vector<int> visited(max, false);

        //create a list of all visited nodes
        list<int> visNode;
        visNode.push_back(start);
        visited[start] = true;

        //iterating over the list
        list<int>::iterator itr;

        //variable to store the visited node
        int n;

        while(!visNode.empty()){
            n = visNode.front();
            cout<<"\nVisited node:"<<n;
            visNode.pop_front();

            //get all the connected nodes that are not yet visited
            for(itr=adj[n].begin(); itr!=adj[n].end(); itr++){
                if(!visited[*itr]){
                    visited[*itr] = true;
                    visNode.push_back(*itr);
                }
            }
        }
    }

    ~bfs(){
        cout<<"\nMemory released";
    }
};

int main(){
    bfs b;
    int choice, start;
    string node;

    do{
        cout << "\n0.Enter 0 to exit";
        cout << "\n1.Enter 1 to add an edge";
        cout << "\n2.Enter 2 to perform bfs operation";
        cout << "\n\nEnter your choice:";
        cin >> choice;

        switch (choice){
            case 1:{
                cin.ignore(1);
                cout << "\nEnter the node numbers:";
                getline(cin, node);
                b.addEdge(((int)node[0] - 48), ((int)node[2] - 48));
                break;
            }
            case 2:{
                cout << "\nEnter the starting node:";
                cin >> start;
                b.bfsAlgo(start);
                break;
            }
            case 0:{
                break;
            }
            default:{
                cout << "\nWrong choice!!!";
            }
        }
    } while (choice != 0);

    return 0;
}
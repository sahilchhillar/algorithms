//dfs using adjacency list
#include<iostream>
#include<cstring>
#include<vector>
#include<list>
using namespace std;

#define max 5

class dfs{
    list<int> *adj;

    public:
    dfs(){
        adj = new list<int>[max];
    }

    void addEdge(int start, int end){
        adj[start].push_back(end);
    }

    void dfsAlgo(int start, vector<bool> &visited){
        visited[start] = true;
        cout<<"\nVisited node:"<<start;

        //iterate over the list
        list<int>::iterator itr;
        for(itr = adj[start].begin(); itr != adj[start].end(); itr++){
            if(!visited[*itr]){
                dfsAlgo(*itr, visited);
            }
        }
    }
};

int main(){
    dfs d;
    int choice, start;
    string node;

    do{
        cout << "\n1.Enter 1 to enter an edge";
        cout << "\n2.Enter 2 to perform dfs algorithm";
        cout << "\n0.Enter 0 to exit";
        cout << "\n\nEnter your choice:";
        cin >> choice;

        switch (choice){
            case 1:{
                cin.ignore(1);
                cout << "\nEnter your node numbers:";
                getline(cin, node);
                d.addEdge(((int)node[0] - 48), ((int)node[2] - 48));
                break;
            }
            case 2:{
                cout << "\nEnter the start node:";
                cin >> start;
                vector<bool> visited(max, false);
                d.dfsAlgo(start, visited);
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
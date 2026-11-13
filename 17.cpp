//17.Write a program to represent flight connections between cities using a graphs to stored as an adjacency matrix and determine whether the graph is connected.
#include <iostream>
#include <string>
using namespace std;
#define max 10
class graph{
    string city[max];
    int n;
    int g[max][max];
public:
    graph()
    {
        n = 0;
        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max; j++)
            {
                g[i][j] = 0;
            }
        }
    }
    void read();
    void display();
    void connected();
    void DFS(int, int[]);
};
void graph::read(){
    string r;
    cout << "Enter the number of cities: ";
    cin >> n;
    if (n < 1 || n > max)
    {
        cout << "Invalid number of cities!";
        n = 0;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of city: ";
        cin >> city[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << "Is it possible to travel between "
                     << city[i] << " and " << city[j] << "? (Y/N): ";
                cin >> r;
                if (r == "Y" || r == "y")
                {
                    cout << "Enter the time required to travel: ";
                    cin >> g[i][j];
                }
            }
        }
    }
}
void graph::display(){
    if (n == 0)
        return;
    cout << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << city[i] << "\t";
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\n" << city[i] << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << "\t";
        }
    }
    cout << endl;
}
void graph::DFS(int v, int visited[]){
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (g[v][i] != 0 && visited[i] == 0)
        {
            DFS(i, visited);
        }
    }
}
void graph::connected(){
    if (n == 0)
        return;
    int visited[max] = {0};
    DFS(0, visited);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            cout << "Graph is not connected.";
            return;
        }
    }
    cout << "Graph is connected.";
}
int main(){
    graph g;
    g.read();
    g.display();
    g.connected();
    return 0;
}

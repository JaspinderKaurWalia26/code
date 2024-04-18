#include <iostream>
#include <queue>
#include <stack>
#include <limits> // for numeric_limits
#include <ios> // for streamsize

using namespace std;

class Graph {
private:
    int** adjacencyMatrix;
    int numVertices;
public:
    Graph(int numVertices);
    void addEdge(int startVertex, int endVertex);
    void printReachableNodesDFS(int startVertex);
    void printReachableNodesBFS(int startVertex);
    ~Graph();
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;

    adjacencyMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencyMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int startVertex, int endVertex) {
    if (startVertex >= 0 && startVertex < numVertices && endVertex >= 0 && endVertex < numVertices) {
        adjacencyMatrix[startVertex][endVertex] = 1;
    } else {
        cout << "Invalid vertices!" << endl;
    }
}

void Graph::printReachableNodesDFS(int startVertex) {
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    visited[startVertex] = true;
    cout << "Nodes reachable from " << startVertex << " using DFS: ";
    cout << startVertex << " ";

    stack<int> stack;
    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                stack.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }

    cout << endl;
    delete[] visited;
}

void Graph::printReachableNodesBFS(int startVertex) {
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    visited[startVertex] = true;
    cout << "Nodes reachable from " << startVertex << " using BFS: ";
    cout << startVertex << " ";

    queue<int> queue;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();

        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }

    cout << endl;
    delete[] visited;
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}

int main() {
	cout<<"Name:Jaspinder Kaur Walia"<<endl<<"Class:CSE-C2"<<endl<<"URN:2203843"<<endl;
	cout<<endl;
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    Graph graph(numCities);

    int choice;
    do {
        cout << "-------------------------" << endl;
        cout << "Operations on Graph" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add an edge" << endl;
        cout << "2. Print reachable nodes using DFS" << endl;
        cout << "3. Print reachable nodes using BFS" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        // Handle invalid input
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter an integer." << endl;
            cin.clear(); // clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard incorrect input
            continue; // go back to the start of the loop
        }

        switch (choice) {
            case 1: {
                int start, end;
                cout << "Enter the start city: ";
                cin >> start;
                cout << "Enter the end city: ";
                cin >> end;
                graph.addEdge(start, end);
                break;
            }
            case 2: {
                int start;
                cout << "Enter the starting city: ";
                cin >> start;
                graph.printReachableNodesDFS(start);
                break;
            }
            case 3: {
                int start;
                cout << "Enter the starting city: ";
                cin >> start;
                graph.printReachableNodesBFS(start);
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
    } while (choice != 4);

    return 0;
}


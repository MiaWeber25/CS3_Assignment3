#include <iostream>

using namespace std;
    
    const int numNodes = 10;  


// Finds the next node with minimum weight that ISN'T set
int findMinNode(unsigned int weight[], bool set[]) {
    int minValue = INT_MAX;
    int minIndex;

    for (int i=0; i<numNodes;i++) {
        if (!set[i] && weight[i]<minValue) {
            minValue = weight[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to print the completed Minimum Spanning Tree (MST)
void printMST(int MST[], int adjMatrix[numNodes][numNodes]) {
    cout << "Edge \tWeight\n";
    for (int i=1; i<numNodes; i++) {
        cout << MST[i] << " - " << i << " \t" << adjMatrix[i][MST[i]] << " \n";
    }
}

void prim(int adjMatrix[numNodes][numNodes]) {
    int MST[numNodes];
    unsigned int weight[numNodes];
    bool set[numNodes];
    for (int i=0; i < numNodes; i++) {
        weight[i] = INT_MAX;
        set[i] = false;
    }
    weight[0] = 0;
    MST[0] = -1; 

    for (int count = 0; count < numNodes - 1; count++) {
        int minNode = findMinNode(weight, set);
        set[minNode] = true;
        for (int i=0;i<numNodes;i++) {
            if (adjMatrix[minNode][i] && !set[i] && adjMatrix[minNode][i] < weight[i]) {
                MST[i] = minNode;
                weight[i] = adjMatrix[minNode][i];
            }
        }
    }

    printMST(MST, adjMatrix);
}

int main() {
    //int adjMatrix[numNodes][numNodes];
    int adjMatrix[numNodes][numNodes] = { { 0, 6, 10, 0, 0, 0, 0, 0, 0, 0 }, //Using adjancency matrix
						{ 6, 0, 12, 11, 14, 0, 0, 0, 0, 0 },
						{ 10, 12, 0, 12, 0, 0, 8, 16, 0, 0 },
						{ 11, 11, 12, 0, 0, 6, 3, 0, 0, 0 },
						{ 14, 14, 0, 0, 0, 4, 0, 0, 6, 0 },
                        { 0, 0, 0, 6, 4, 0, 0, 0, 12, 0 },
                        { 0, 0, 8, 3, 0, 0, 0, 0, 16, 6 },
                        { 0, 0, 16, 0, 0, 0, 0, 0, 0, 8 },
                        { 0, 0, 0, 0, 6, 12, 16, 0, 0, 13 },
                        { 0, 0, 0, 0, 0, 0, 6, 8, 13, 0 } };
    prim(adjMatrix);
    return 0;
}
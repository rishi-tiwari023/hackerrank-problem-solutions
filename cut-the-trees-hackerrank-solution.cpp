#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

int visited[100009];
int nodeWeight[100009];
int subTreeWeight[100009];
std::vector<int> edges[100009];

int difference(int value, int sum) {
    return std::abs(sum - 2 * value);
}

int dfs(int node) {
    if (visited[node])
        return 0;
    
    if (edges[node].size() == 1) {
        subTreeWeight[node] = nodeWeight[node];
        visited[node] = 1;
        return subTreeWeight[node];
    } else {
        visited[node] = 1;
        
        int totalWeight = nodeWeight[node];
        std::vector<int>::iterator it;
        for (it = edges[node].begin(); it != edges[node].end(); it++) {
            int nodeIndex = *it;
            totalWeight += dfs(nodeIndex);
        }
        
        subTreeWeight[node] = totalWeight;
        return subTreeWeight[node];
    }
}

int main() {
    int numberOfVertices, rootNode;
    std::cin >> numberOfVertices;
    
    // Setup the sub-tree weight and visited arrays.
    for (int i = 0; i < numberOfVertices; i++) {
        subTreeWeight[i] = 0;
        visited[i] = 0;
    }
    
    // Sum the weights of the entire tree.
    int sum = 0;
    for (int i = 1; i <= numberOfVertices; i++) {
        std::cin >> nodeWeight[i];
        sum += nodeWeight[i];
    }
    
    // Setup the tree edges.
    for (int i = 0; i < numberOfVertices; i++) {
        int node1, node2;
        std::cin >> node1 >> node2;
        edges[node1].push_back(node2);
        edges[node2].push_back(node1);
    }
    
    // Assign the root node for nodes with multiple branches.
    for (int i = 0; i < numberOfVertices; i++) {
        if (edges[i].size() > 1) {
            rootNode = i;
            break;
        }
    }
    
    int temp = dfs(rootNode);
    
    for (int i = 1; i <= numberOfVertices; i++) {
        subTreeWeight[i - 1] = difference(subTreeWeight[i], sum);
    }
    
    std::sort(subTreeWeight, subTreeWeight + numberOfVertices);
    std::cout << subTreeWeight[0] << std::endl;
    
    return 0;
}


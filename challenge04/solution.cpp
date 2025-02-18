/* Program Name: dfs tester
 * Student Name: David Carpenter
 * Net ID: dcarpe23
 * Student ID: 000722316
 * Program Description: tests a given graph to see if a specified path exists using dfs method*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

// Main Execution

struct Node {
    string name;
    vector <Node *> edges;
};

bool dfs(Node* src, Node* dst, unordered_set<string>& visited) {

	if (src == dst) return true; //base case: source and destination are the same
	if (visited.count(src->name)) return false; //base case: node has already been visited

	visited.insert(src->name);
	for (Node* neighbor : src->edges)  {

		if(dfs(neighbor, dst, visited)) return true;
	}

	return false;

}

int main() {

  string line;
  int graphCount = 0;

  while (getline(cin, line)) {
	
	  if(graphCount != 0) cout << "\n";

	  graphCount++;
	  unordered_map<string, Node*> nodes;

	  int nEdges = stoi(line);

	  for (int i = 0; i < nEdges; i++) {
		
		  string src, dst;
		  cin >> src >> dst;

		  //adds nodes if not already in map
		  if(nodes.find(src) == nodes.end()) nodes[src] = new Node{src};
		  if(nodes.find(dst) == nodes.end()) nodes[dst] = new Node{dst};

		  //defines dst as an edge of src
		  nodes[src]->edges.push_back(nodes[dst]);

	  }

	  int nPaths = 0;
	  cin >> nPaths;

	
	  for (int i = 0; i < nPaths; i++) {
	
		  string src, dst;
		  cin >> src >> dst;
		  unordered_set<string> visited;

		  //searchs for a path from src to dst
		  if(dfs(nodes[src], nodes[dst], visited)) {

			cout << "In Graph " << graphCount << " there is a path from " << src << " to " << dst << "\n";	

		  } else {

			cout << "In Graph " << graphCount << " there is no path from " << src << " to " << dst << "\n";

		  }

	  }

		
	  cin.ignore();

	  //clears nodes for next graph
	  for (unordered_map<string, Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
		              
		  delete it->second;
	  }

  }

  return (0);
}

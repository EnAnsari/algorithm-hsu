// greedy/main.cpp
#include <iostream>
#include <fstream>
#include <list>
using namespace std;
#include "../src/graphic.txt"

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V) { this->V = V; adj = new list<int>[V]; }
	~Graph() { delete [] adj; }
	void addEdge(int v, int w) {
	    adj[v].push_back(w);
	    adj[w].push_back(v);
    }
	void greedyColoring(int result[]) {
        result[0] = 0;
        for(int u = 1; u < V; u++)
            result[u] = -1;
        bool available[V] = {0};
        for(int u = 1; u < V; u++) {
            list<int>::iterator i;
            for(i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = true;
            int cr;
            for(cr = 0; cr < V; cr++)
                if(available[cr] == false) break;
            result[u] = cr;
            for(i = adj[u].begin(); i != adj[u].end(); ++i)
                if(result[*i] != -1)
                    available[result[*i]] = false;
        }
    }
};

int main(int argc, char **argv) {
    string str, inputFileName = "", outputFileName = "";

    if (argc <= 4) {
        cout << "Error message goes here." << endl;
        exit(0);
    }
    for (int i = 1; i < argc; i++) {
        string tempS = argv[i];
        if (tempS == "-i") inputFileName  = argv[++i];
        else if (tempS == "-o") outputFileName  = argv[++i];
    }

    ifstream inputFile(inputFileName.c_str(), ios::in);
    if(!checkFile(inputFile, inputFileName)) return 0;
    ifstream inputFileTemp(inputFileName.c_str(), ios::in);
    ofstream outputFile(outputFileName.c_str(), ios::out);

    int vertex = setVertex(inputFile, inputFileTemp, outputFile);
    Graph g(vertex);

    while (!inputFile.eof()) {
        inputFile >> str;
        if(str_in_str(str, "source") != -1) {
            int a = ret_value(str);
            inputFile >> str;
            int b = ret_value(str);
            g.addEdge(a, b);
        }
    }

	int color[vertex];
	g.greedyColoring(color);
    
    write_end(vertex, inputFileTemp, outputFile, color, 0);

    inputFile.close();
    inputFileTemp.close();
    outputFile.close();
	return 0;
}
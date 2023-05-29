// backtrack/main.cpp
#include <iostream>
#include <fstream>
using namespace std;
#include "../src/graphic.hpp"

#define MAX 100

// void printSolution(int v, int color[]) {
// 	for (int i = 0; i < v; i++) cout << color[i] << " ";
// 	cout << endl;
// }

bool isSafe(int v, bool graph[MAX][MAX], int color[]) {
	for (int i = 0; i < v; i++)
		for (int j = i + 1; j < v; j++)
			if (graph[i][j] && color[j] == color[i])
				return false;
	return true;
}

bool graphColoring(int v, bool graph[MAX][MAX], int m, int i, int color[]) {
	if (i == v) {
		if (isSafe(v, graph, color)) {
            // cout << "\nSolution Exists: Following are the assigned colors \n";
			// printSolution(v, color);
			return true;
		}
		return false;
	}
	for (int j = 1; j <= m; j++) {
		color[i] = j;
		if (graphColoring(v, graph, m, i + 1, color))
			return true;
		color[i] = 0;
	}
	return false;
}

int main(int argc, char **argv) {
    int m, vertex;
    string str, inputFileName = "", outputFileName = "";

    if (argc <= 6) {
        cout << "Error message goes here." << endl;
        exit(0);
    }
    for (int i = 1; i < argc; i++) {
        string tempS = argv[i];
        if (tempS == "-m") m  = to_int(argv[++i]);
        else if (tempS == "-i") inputFileName  = argv[++i];
        else if (tempS == "-o") outputFileName  = argv[++i];
    }

    ifstream inputFile(inputFileName.c_str(), ios::in);
    if(!checkFile(inputFile, inputFileName)) return 0;
    ifstream inputFileTemp(inputFileName.c_str(), ios::in);
    ofstream outputFile(outputFileName.c_str(), ios::out);

    vertex = setVertex(inputFile, inputFileTemp, outputFile);
	bool graph[MAX][MAX] = {0};
    while (!inputFile.eof()) {
        inputFile >> str;
        if(str_in_str(str, "source") != -1) {
            int a = ret_value(str);
            inputFile >> str;
            int b = ret_value(str);
            graph[a][b] = graph[b][a] = 1;
        }
    }

	int color[vertex] = {0};
	if (!graphColoring(vertex, graph, m, 0, color))
		cout << "\nSolution does not exist";
    else cout << "\nproccess is successfull!";
    
    write_end(vertex, inputFileTemp, outputFile, color, 1);

    inputFile.close();
    inputFileTemp.close();
    outputFile.close();
	return 0;
}
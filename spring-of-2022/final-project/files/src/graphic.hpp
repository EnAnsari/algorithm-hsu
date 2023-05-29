// src/graphic.cpp

string COLOR[] = {
    "RED", "BLUE", "AQUA", "PINK", "BROWN", "ORANGE",
    "CHOCOLATE", "GOLD", "OLIVE", "SALMON", "LIME",
    "GREEN", "TEAL", "WHILTE", "BLACK", "GRAY", "SILVER"
};

int to_int(string s) {
    int i = 0;
    for(int j = 0; s[j] >= '0' && s[j] <= '9'; j++)
        i = i * 10 + (s[j] - '0');
    return i;
}

int str_in_str(string a, string b) {
    for(int i = 0; a[i]; i++)
        if(a[i] == b[0]) {
            int j = 1;
            for(; b[j] && a[i + j] == b[j]; j++);
            if(!b[j]) return i;
        }
    return -1;
}

void endline_by_shift(string str, ofstream &output) {
    int i = 0;
    while(str[i]) {
        for(; str[i] && str[i] != '>'; i++) output << str[i];
        if(str[i] == '>') output << ">\n", i++;
        else output << ' ';
    }
}

int ret_value(string str) {
    string temp = "";
    int i = 0;
    for(; str[i] != '"'; i++);
    for(i++; str[i] != '"'; i++) temp += str[i];
    return to_int(temp);
}

bool checkFile(ifstream &inputFile, string inputFileName) {
    if(!inputFile.is_open()) {
        inputFile.close();
        cout << "\nCan not open " << inputFileName << endl;
        return false;
    }
    return true;
}

int setVertex(ifstream &inputFile, ifstream &inputFileTemp, ofstream &outputFile) {
    int vertex;
    string str;
    while(!inputFile.eof()) {
        inputFile >> str;
        if(str_in_str(str, "node") != -1) {
            vertex = 1;
            break;
        }
        else if(str_in_str(str, ">") != -1) endline_by_shift(str, outputFile);
        else outputFile << str << ' ';
        inputFileTemp >> str;
    }
    while(!inputFile.eof()) {
        inputFile >> str;
        if(str_in_str(str, "<node") != -1) vertex++;
        else if(str_in_str(str, "<edge") != -1) break;
    }
    return vertex;
}

void write_end(int vertex, ifstream &inputFileTemp, ofstream &outputFile, int color[], int x) {
    int count = 0;
    string str;
    while(!inputFileTemp.eof() && count < vertex) {
        inputFileTemp >> str;
        if(str_in_str(str, ">") != -1) endline_by_shift(str, outputFile);
        else if(str_in_str(str, "upText") != -1) outputFile << "upText=\"" << COLOR[color[count++] - x] << "\" ";
        else outputFile << str << ' ';
    }
    while(!inputFileTemp.eof()) {
        inputFileTemp >> str;
        if(str_in_str(str, ">") != -1) endline_by_shift(str, outputFile);
        else outputFile << str << ' ';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
using namespace std;
//주석
#define endl '\n'
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 int128;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }

    return result;
}

int main() {
    fastio();
    ifstream compileFile("test.lgd");
    ofstream outputFile("test.cpp");
    outputFile.write("#include <iostream>\nusing namespace std;\nint main(void){\n\t", 21+20+17);
    if (compileFile.is_open()) {
        while (!compileFile.eof()) {
            string line;
            getline(compileFile, line);
            vector<string> tokens = split(line, ' ');
            for (auto& str: tokens) {
                cout << str << endl;
            }
            // parsing Using
            // Todo Using 구현

            // parsing Define
            // 문법: Define [<타입>] [<구조>] [<이름>]
            if (tokens[0] == "Define") {
                string type = tokens[1];
                string structure = tokens[2];
                string name = tokens[3];
                name.pop_back();

                if (structure == "Variable") {
                    if (type == "Integer") {
                        outputFile.write(("int " + name + ";").c_str(), 5+name.length());
                    }
                }

            }
        }
    }

    outputFile.write("\n}", 2);
    outputFile.close();
}

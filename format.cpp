#include"format.h"

void writeToOutput(string in, string out) {
    ifstream indata(in);
    ofstream outdata(out);
    string line;
    while (getline(indata, line)) {
        outdata << line << endl;
    }
    indata.close();
}
void format(string in, string out) {
    ifstream indata(in);
    ofstream outdata(out);
    string line, spaces;
    int lines = 0;
    bool closedInLine = false;
    stack<string> st;
    while (getline(indata, line)) {
        string starttag, closetag;
        if (line[0] == '<') {
            if (line[1] == '/') {
                for (int i = 1; i < line.size(); i++) {
                    if (line[i] == '>') {
                        break;
                    }
                    closetag = closetag + line[i];
                }
            }
            else {
                for (int i = 1; i < line.size(); i++) {
                    if (line[i] == '>') {
                        break;
                    }
                    starttag = starttag + line[i];
                }
                if (starttag != "") {
                    st.push(starttag);
                }
            }
        }
        if (line[line.size() - 1] == '>') {
            if (line[line.size() - starttag.size() - 2] == '/') {
                closedInLine = true;
                st.pop();
            }
        }
        if (lines > 0 && line[0] == '<') {
            spaces = spaces + "    ";
            if (closetag == "/" + st.top()) {
                spaces = spaces.substr(0, spaces.size() - 4);
                st.pop();
                line = spaces + line;
                outdata << line << endl;
                spaces = spaces.substr(0, spaces.size() - 4);
            }
            else {
                line = spaces + line;
                outdata << line << endl;
            }
        }
        else if (lines > 0 && line[0] == ' ') {
            outdata << line << endl;
        }

        else if (lines > 0 && line[0] != '<') {
            spaces = spaces + "    ";
            line = spaces + line;
            outdata << line << endl;
            spaces = spaces.substr(0, spaces.size() - 4);
        }
        else if (lines == 0 && line[0] == '<') {
            outdata << line << endl;
        }
        lines++;
        if (closedInLine) {
            spaces = spaces.substr(0, spaces.size() - 4);
        }
        closedInLine = false;
    }
    indata.close();
}

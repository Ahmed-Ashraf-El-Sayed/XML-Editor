#include"checkConsistency.h"

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

bool XMLConsistency(string file_name) {
    fstream file(file_name.c_str());
    string s = "";
    int closetag1, opentag1, closetag2, opentag2;
    string str1 = "", str2 = "";
    int numberofline = 1;
    stack<int> n;                 // stack for number of line that have mistakes
    stack<string> stack1, stack2;
    bool a = 0;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            s = removeSpaces(line.c_str());
            closetag1 = s.find(">");
            opentag1 = s.find("<");
            closetag2 = s.find(">", closetag1 + 1);
            opentag2 = s.find("<", opentag1 + 1);
            int l = s.length();

            if (opentag1 != -1 && closetag1 != -1 && opentag2 == -1 && closetag2 == -1)         // case open tag only in line
            {
                if (s[opentag1 + 1] != '/') {
                    if ((s.length() - 1) > closetag1) {
                        n.push(numberofline);
                        stack2.push(s);
                    }
                    if ((s.length() - 1) == closetag1) {
                        str1.clear();
                        while (opentag1 < closetag1 - 1) {
                            str1 += s[opentag1 + 1];
                            opentag1++;
                        }
                        stack1.push(str1);
                    }
                }

                else {
                    str2.clear();
                    while (opentag1 < closetag1 - 2) {
                        str2 += s[opentag1 + 2];
                        opentag1++;
                    }
                    if (str2 != stack1.top()) {
                        stack2.push(stack1.top());
                        stack1.pop();
                        n.push(numberofline);
                    }
                    if (str2 == stack1.top()) {
                        stack1.pop();
                    }
                }


            }

            if (opentag1 == -1 && closetag1 == -1 && opentag2 == -1 && closetag2 == -1) {
                if (s.length() == 0) {
                    n.push(numberofline);
                    stack2.push(s);
                }
            }

            if (opentag1 != -1 && closetag1 != -1 && opentag2 != -1 && closetag2 != -1)         // case open and close tag in one line
            {
                str1.clear();
                while (opentag1 < closetag1 - 1) {
                    str1 += s[opentag1 + 1];
                    opentag1++;
                }
                stack1.push(str1);
                str2.clear();
                while (opentag2 < closetag2 - 2) {
                    str2 += s[opentag2 + 2];
                    opentag2++;
                }
                if (str2 != stack1.top()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                    n.push(numberofline);
                }
                if (str2 == stack1.top()) {
                    stack1.pop();
                }
            }

            numberofline++;
        }
        if (!n.empty()) {
            string ErrorLines = "";
            while (!n.empty()) {
                ErrorLines.append(to_string(n.top()));
                ErrorLines.append(" and ");
                n.pop();
            }
            ErrorLines.resize(ErrorLines.size() - 4);
        }

        if (stack2.empty()) {
            a = 0;
        }
        else {
            a = 1;
        }
        file.close();
    }
    return a;
}

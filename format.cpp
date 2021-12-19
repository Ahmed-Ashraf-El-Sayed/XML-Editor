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
void format(string in,string out){
    ifstream indata(in);
    ofstream outdata(out);
    string line,spaces;
    int lines =-1;
    bool closedInLine=false;
    stack<string> st;
    while (getline(indata,line)){
        string starttag,closetag;
        if(line[0]=='<'){
            if(line[1]=='/'){
                for(int i = 1;i<line.size();i++){
                    if(line[i]=='>'){
                        break;
                    }
                    closetag = closetag+line[i];
                }
            }
            else{
                char charc = line[1];
                    for(int i = 1;i<line.size();i++){
                        if(line[i]=='>'||line[i]==' '){
                            break;
                        }
                        starttag = starttag+line[i];
                    }
                    if(starttag!=""){
                        st.push(starttag);
                    }
                    if(!((int)st.top()[1]>(int)'A'&&(int)st.top()[1]<(int)'z')){
                        st.pop();
                    }
                    if(st.top()=="frame"){
                        st.pop();
                    }

            }
        }
        if(line[line.size()-1] =='>' &&line[0]!='<'){
                for(int i = line.size()-2;i>0;i--){
                    if(line[i]=='<'){
                        break;
                    }
                closetag = line[i]+closetag;
                }
        }
        //cout<<"this is the stack top "<<st.top()<<endl;
        if(line[line.size()-1] =='>'){
            if(line[line.size()-starttag.size()-2]=='/'){
            closedInLine = true;
            st.pop();
            }
        }
        if(lines>0&&line[0]=='<'){
            spaces = spaces+"    ";
            if (closetag=="/"+st.top()){
                spaces = spaces.substr(0,spaces.size()-4);
                st.pop();
                line = spaces+line;
                outdata<<line<<endl;
                spaces = spaces.substr(0,spaces.size()-4);
            }
            else if(line[line.size()-2]=='/'||line[1]=='!'||line[line.size()-2]=='-'||line[line.size()-2]=='?'){
                spaces = spaces.substr(0,spaces.size()-4);
                line = spaces+line;
                outdata<<line<<endl;
            }
            else{
                line = spaces+line;
                outdata<<line<<endl;
            }
        }
        else if(lines>0&&line[0]!='<'){
            if(line[line.size()-1] =='>'){
                line = spaces+line;
                outdata<<line<<endl;
                spaces =spaces.substr(0,spaces.size()-4);
                st.pop();
                }
            else if(line[line.size()-2]=='/'||line[1]=='!'||line[line.size()-2]=='-'||line[line.size()-2]=='?'){
                spaces = spaces.substr(0,spaces.size()-4);
                line = spaces+line;
                outdata<<line<<endl;
            }
            else{
                spaces = spaces+"    ";
                line = spaces+line;
                outdata<<line<<endl;
                spaces =spaces.substr(0,spaces.size()-4);
            }
        }
        else if(lines<=0 &&line[0]=='<'){
            outdata<<line<<endl;
        }
        lines++;
        if(closedInLine){
            spaces = spaces.substr(0,spaces.size()-4);
        }
        closedInLine = false;
    }
    indata.close();
}

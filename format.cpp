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
void formatting(string in, string out) {
    ifstream indata(in);
    ofstream outdata(out);
    string line,spaces;
    int lines =-1;
    bool closedInLine=false;
    stack<string> st;
    while (getline(indata,line)){
        string starttag,closetag;
        //first we extract the start and close tags from the line
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
                for(int i = 1;i<line.size();i++){
                    if(line[i]=='>'||line[i]==' '){
                        break;
                    }
                    starttag = starttag+line[i];
                }
                if(starttag!=""){
                    st.push(starttag);
                }
                //if we pushed unto the stack tags that start<-- or anything else
                if(!((int)st.top()[1]>(int)'A'&&(int)st.top()[1]<(int)'z')){
                    st.pop();
                }
                //if we pushed unto the stack frame tag
                if(st.top()=="frame"){
                    st.pop();
                }
            }
        }
        //this block gets the end tag if its in the end of the line
        if(line[line.size()-1] =='>' &&line[0]!='<'){
            for(int i = line.size()-2;i>0;i--){
                if(line[i]=='<'){
                    break;
                }
            closetag = line[i]+closetag;
            }
        }
        //this block to check if the tag is closed in the same line
        if(line[line.size()-1] =='>'){
            if(line[line.size()-starttag.size()-2]=='/'){
                closedInLine = true;
                st.pop();
            }
        }
        cout<<st.top()<<endl;
        //this checks if the lines are already formatted then it prints them without any editing
        if(line[0] ==' '){
            outdata<<line<<endl;
            continue;
        }
        //this block is in charge of the output lines
        else if(lines>0&&line[0]=='<'){
            spaces = spaces+"    ";
            //if the tag is getting closed this closes the tag and reduces the spaces before it
            if (closetag=="/"+st.top()){
                spaces = spaces.substr(0,spaces.size()-4);
                st.pop();
                line = spaces+line;
                outdata<<line<<endl;
                spaces = spaces.substr(0,spaces.size()-4);
            }
            //this takes care of the tags that have ! / - ? and prints it after formatting
            else if(line[line.size()-2]=='/'||line[1]=='!'||line[line.size()-2]=='-'||line[line.size()-2]=='?'){
                spaces = spaces.substr(0,spaces.size()-4);
                line = spaces+line;
                outdata<<line<<endl;
            }
            // this prints the lines with tags that is opened in this line
            else{
                line = spaces+line;
                outdata<<line<<endl;
            }
        }
        else if(lines>0&&line[0]!='<'){
            //this outputs the lines that has the closing tag in the end of the line and removes tag from the stack
            if(line[line.size()-1] =='>'){
                line = spaces+line;
                outdata<<line<<endl;
                spaces =spaces.substr(0,spaces.size()-4);
                st.pop();
                }
            //this outputs the lines with / ! - ? in the end of it
            else if(line[line.size()-2]=='/'||line[1]=='!'||line[line.size()-2]=='-'||line[line.size()-2]=='?'){
                spaces = spaces.substr(0,spaces.size()-4);
                line = spaces+line;
                outdata<<line<<endl;
            }
            //this outputs the lines that has normal text in it and doesnt have any closing or starting tag
            else{
                spaces = spaces+"    ";
                line = spaces+line;
                outdata<<line<<endl;
                spaces =spaces.substr(0,spaces.size()-4);
            }
        }
        //this outputs the lines in the start of the block without formatting
        else if(lines<=0 &&line[0]=='<'){
            outdata<<line<<endl;
        }
        lines++;
        //this removes the spaces in the case of closing the tag in the same line that it was opened in
        if(closedInLine){
            spaces = spaces.substr(0,spaces.size()-4);
        }
        closedInLine = false;
    }
    indata.close();
}

#include"minify.h"

void minify(string in,string out){
    ifstream indata(in);
    ofstream outdata(out);
    string line;
    while (getline(indata,line)){
        for(int i =0;i<2000000000;i++){
            if(line[line.size()-1]==' '){
                line.erase(line.size()-1,1);
            }
            else if(line[line.size()-1]=='\t'){
                line.erase(line.size()-1,1);
            }
            else if(line[0]=='\t'){
                line.erase(0,1);
            }
            else if(line[0]==' '){
                line.erase(0,1);
            }
            else{
                break;
            }
        }
        outdata<<line;
    }
    indata.close();
}

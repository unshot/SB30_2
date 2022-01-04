#include <iostream>
#include <cpr/cpr.h>

std::string getHeader(std::string &str){

    int begin = 0;
    int end = 0;

    if(str.find("<h1>") != std::string::npos){
        begin = str.find("<h1>") + 4;
    }else if(str.find("<H1>") != std::string::npos){
        begin = str.find("<H1>") + 4;
    }
    
    if(str.find("</h1>") != std::string::npos){
        end = str.find("</h1>") - begin;
    }else if(str.find("</H1>") != std::string::npos){
        end = str.find("</H1>") - begin;
    }

    return str.substr(begin, end);
}

int main(){
    std::cout << "#######--Capturing the title of a web page--########\n\n";

    auto responce = cpr::Get(cpr::Url("http://httpbin.org/html")).text;
    std::cout << getHeader(responce) << "\n";

    return 0;
}

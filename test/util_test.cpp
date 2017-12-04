#include<iostream>
#include<string>
#include<fstream> 

#include "../util.h"


int main() {
    char fname[] = "../dic/coreDict.txt";
    std::ifstream in(fname);
    std::string line;
    char encoding[] = "GBK";

    if (in) {
        while (getline(in, line)) {
            std::string outline;
            int res = decode(line, outline, encoding);
            //std::cout << outline << std::endl;
        }
    }
    return 0;
}


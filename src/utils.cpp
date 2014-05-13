#include "utils.h"
#include <fstream>
#include <string>
#include <cerrno>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdarg>

char* stringToAllocChar(std::string a){
    char* s = new char[a.size()];
    strcpy(s, a.c_str());
    return s;
}

void recycleMem(std::vector< std::vector<void*> > a){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++)
            delete [] a[i][j];
    }
}

std::vector<void*> loadStack(int n, ... ){
    va_list arguments;
    va_start (arguments, n);

    std::vector<void*> stk;

    for (int i = 0; i < n; i++){
        stk.push_back(va_arg(arguments, void*));
    }

    va_end(arguments);
    return stk;
}

/*All following Code is From StackOverFlow Credit to the Original Author*/

std::string get_file_contents(const char *filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  throw(errno);
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

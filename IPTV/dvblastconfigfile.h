#ifndef DVBLASTCONFIGFILE_H
#define DVBLASTCONFIGFILE_H
#include <iostream>
#include <vector>
using namespace std;

class DVBlastConfigFile{
public:
    void setInitAddress(string _address);
    void setPort(string _port);
    void readFile(string file);
    void parseFiles();
    void printParsedToConsole();
    void writeConfigFiles();
    string createAddress(int iter);
    string getParsedLine(int i);

    string address;
    string port;

    vector <string> tunerFiles;
    vector <vector<string>> parsedConfigFiles;

};

#endif // DVBLASTCONFIGFILE_H

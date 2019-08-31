#include "dvblastconfigfile.h"
#include <fstream>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;
//-------------------------------------------------------------------
void DVBlastConfigFile::setInitAddress(string _address){
    address = _address;
}
//-------------------------------------------------------------------
void DVBlastConfigFile::setPort(string _port){
    port = _port;
}
//-------------------------------------------------------------------
void DVBlastConfigFile::readFile(string file){
    ifstream file_(file);
    if(file_.is_open()){
        string channel;
        while(getline(file_, channel)){
            tunerFiles.push_back(channel);
        }
        cout << "tuner file found" << endl;
        cout << "channels:  " + to_string(tunerFiles.size()) << endl;
        parseFiles();
        file_.close();
    }
    else{cout << "TunerFileNotFound" << endl;}
}
//-------------------------------------------------------------------
string DVBlastConfigFile::createAddress(int iter){
    //initAddress.first.last
    vector<string> split;
    string _line = address;
    boost::split(split, _line, boost::is_any_of("."));

    int last = stoi(split[3]) + iter % 256;
    int first = stoi(split[2]) + iter / 256;

    string addressMod = split[0] + "." + split[1] + "." + to_string(first) + "." + to_string(last) + ":" + port;

    return addressMod;
}
//-------------------------------------------------------------------
void DVBlastConfigFile::parseFiles(){
    //if change in frequency flag up

    //EXAMPLE of O
    //;channelName
    //239.255.adress    1   pid

    int frequencyChange= 0;
    int frequency = 0;

    vector<string> split;       //to remove blank config file
    string _line = tunerFiles[0];
    boost::split(split, _line, boost::is_any_of(":"));
    frequencyChange = stoi(split[1]);

    vector <string> channels;
    for(int i = 0; i < tunerFiles.size(); i++){
        vector<string> split;
        string _line = tunerFiles[i];
        boost::split(split, _line, boost::is_any_of(":"));
        string parsedLine = ";" + split[0] + "\n" + createAddress(i)+ "    1   " + split[split.size() - 1];
        frequency = stoi(split[1]);

            if(frequency != frequencyChange){
            parsedConfigFiles.push_back(channels);
            channels.clear();       //clearing last frequency FIX!
            frequencyChange = frequency;
        }
        channels.push_back(parsedLine);
    }
    if(channels.size() > 0){
        cout << "Parsed tuner files in DVBlast format using given address and port number" << endl;
        cout << "frequencies found: " + to_string(parsedConfigFiles.size()) << endl;
    }
}
//-------------------------------------------------------------------
void DVBlastConfigFile::writeConfigFiles(){
    for(int i = 0; i < parsedConfigFiles.size(); i ++){

        string fileName = "\configFile" + to_string(i) + ".txt";
        ofstream configFile(fileName);
        for(int j = 0; j < parsedConfigFiles[i].size(); j++){
            configFile << parsedConfigFiles[i][j] << endl;
        }
        cout << "written conf file to: " + fileName << endl;
    }
}
//-------------------------------------------------------------------
//string DVBlastConfigFile::getParsedLine(int i){
//    if(parsedChannels.size() > 0){
//        return parsedChannels[i];
//    }
//    else{ return "tunerFileNotRead";}
//}
//-------------------------------------------------------------------
void DVBlastConfigFile::printParsedToConsole(){
    for(int i = 0; i < parsedConfigFiles.size(); i++){
        cout << "NEW FREQUENCY!!" << endl;
        for(int j = 0; j < parsedConfigFiles[i].size(); j++){
            cout << parsedConfigFiles[i][j] << endl;
        }
    }
}
//-------------------------------------------------------------------
//    if(newFrequency.equals(frequency) == false){
//      println("/////////////////////////////////////NEW Frequency:" + frequency + "/////////////////////////////////////");
//      println(split[1]+":"+split[2]+":"+split[3]+":"+split[4]+":"+split[5]+":"+split[6]+":"+split[7]+":"+split[8]+":"+split[9]+":"+split[10]+":"+split[11]+":"+split[12]);
//      newFrequency = frequency;
//    }

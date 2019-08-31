#include "iptv.h"

void IPTV::setup(){
    cout << "DVBlast File Parser - videoTree" << endl;
    cout << "Enter desired address in format XXX.XXX.XXX.XXX: ";
    string address;
    cin >> address;
    configFile.setInitAddress(address);   //sets sending adresss 239.255.0.0 -> 239.255.0.nChannels

    cout << "Enter desired port address in format XXXX: ";
    string port;
    cin >> port;
    configFile.setPort(port);

    configFile.readFile("/home/william/Desktop/IP-TV files/DVBlastC++/channels.txt");
//    configFile.readFile("/home/william/channels.txt");
    configFile.writeConfigFiles();
//    configFile.printParsedToConsole();

}



#ifndef IPTV_H
#define IPTV_H
#include <iostream>
#include "dvblastconfigfile.h"
using namespace std;

class IPTV{
public:
    void setup();
    DVBlastConfigFile configFile;
};

#endif // IPTV_H

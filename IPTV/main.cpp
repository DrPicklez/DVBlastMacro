#include <iostream>
#include "iptv.h"
using namespace std;

IPTV ipTv;
int main()
{
//    system("w_scan -ft -cGB -X ~/channels.txt");
    ipTv.setup();
//    system("dvblast -a 0 -c /home/william/Desktop/ipTvFiles/dvBlastConfig/test.cfg -f 490000000 -m qam_64 -b 8 -e");
//    system("vlc udp://@239.255.0.0:9874");
    return 0;
}

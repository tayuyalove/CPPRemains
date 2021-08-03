#include "textquery.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char**argv)
{
    if(argc!=3)
    {
        cout<<"wrong input"<<endl;
        return -1;
    }
    ifstream ifs(argv[2]);
    if(!ifs.is_open()) 
    {
        cout<<"wrong filename"<<endl;
        return -1;
    }
    TextQuery tq(ifs);
    QueryResult qr = tq.query(argv[1]);
    qr.disp();
    return 0;
}
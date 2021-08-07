#include "queryresult.h"
#include <map>
#include <fstream>

class QueryResult;
class TextQuery
{
    public:
    TextQuery(ifstream &);
    QueryResult query(const string &);
    private:
    shared_ptr<vector<string>> _file;
    map<string,shared_ptr<set<vector<string>::size_type>>> _res;
    string cleanup_str( const string &);
};
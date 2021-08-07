#include "textquery.h"
#include <iostream>
#include <sstream>

using namespace std;
TextQuery::TextQuery(ifstream &f)
:_file(new vector<string>){
    string text;
    while( getline(f,text))
    {
        _file->push_back(text);
        int n = _file->size()-1;
        istringstream iss(text);
        string word;
        while(iss>> word)
        {
            word = cleanup_str(word);
            shared_ptr <set<vector<string>::size_type>> &lines = _res[word];
            if(!lines)
                lines.reset(new set<vector<string>::size_type>);
            lines->insert(n);
        }
    }
}

string TextQuery::cleanup_str(const string & word)
{
    string ret;
    for(auto s : word)
    {
        if(!ispunct(s))
            ret+= tolower(s);
    }
    return ret;
}

QueryResult TextQuery::query(const string &sought)
{
    shared_ptr<set<vector<string>::size_type>> nodata (new (set<vector<string>::size_type>));
    auto _r = _res.find(cleanup_str(sought));
    if(_r == _res.end())
        return QueryResult(sought,nodata,_file);
    return QueryResult(sought,_r->second,_file);
}

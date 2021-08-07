#include <memory>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

class QueryResult
{
    public:
    QueryResult(string s,shared_ptr<set<vector<string>::size_type>> p ,shared_ptr<vector<string>> f)
    :_file(f),_sought(s),_lines(p){}
    set<vector<string>::size_type>::size_type size() const { return _lines->size();}
    set<vector<string>::size_type>::const_iterator begin()const { return _lines->begin();}
    set<vector<string>::size_type>::const_iterator end()const { return _lines->end();}
    shared_ptr<vector<string>> getFile() { return _file;}
    void disp()
    {
        cout<<_sought<<"'s result is"<<endl;
        auto bit = _lines->begin();
        for(;bit!=_lines->end();++bit)
            cout<<*bit<<" ";
        cout<<endl;
    }
    private:
    shared_ptr<vector<string>> _file;
    string _sought;
    shared_ptr<set<vector<string>::size_type>> _lines;

};
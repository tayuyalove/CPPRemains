#ifndef __NOCP__
#define __NOCP__
class NoneCopyable
{

    NoneCopyable(const NoneCopyable&);
    NoneCopyable &operator =(const NoneCopyable &);
    protected:
    NoneCopyable(){}
    ~NoneCopyable(){}
};
#endif
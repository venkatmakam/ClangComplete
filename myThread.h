#ifndef MYTHREAD_H_INCLUDED
#define MYTHREAD_H_INCLUDED

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <clang-c/Index.h>


DECLARE_EVENT_TYPE(wxEVT_MY_EVENT, 52346)

class cbPlugin;
class cbProject;

struct transferData
{
    CXTranslationUnit unit;
    wxCharBuffer filename;
    int id;
    cbProject* project;
};

const int threadDoneId = 5634563;


class myThread : public wxThread
{
    cbPlugin *handle;

    CXIndex index;
    wxCharBuffer buffer;
    const char** args;
    int numOfTokens;
    int id;
    cbProject* project;

public:
    myThread(cbPlugin *cb,CXIndex _index, const  wxCharBuffer& _buffer, const char** _args, int _numOfTokens,int _id, cbProject * _project)
    {
        handle = cb;

        index = _index;
        buffer = _buffer;
        args = _args;
        numOfTokens = _numOfTokens;
        id = _id;
        project = _project;

    }

protected:

    CXTranslationUnit threadFunc();


    virtual void* Entry();

};


#endif

#ifndef CXXMIDI_CALLBACK_HPP
#define CXXMIDI_CALLBACK_HPP

//#include <cxxmidi/note.hpp>

namespace CxxMidi {

class Callback
{
public:
    inline Callback(){}

    virtual void operator()()=0;
};

}

//class MyNoteCallback
//{
//	inline MyNoteCallback() {}
//
//	virtual void operator() (CxxMidi::Note, int) = 0;
//};

// namespace CxxMidi

#endif // CXXMIDI_CALLBACK_HPP

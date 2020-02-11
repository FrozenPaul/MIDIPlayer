#ifndef MYNOTECALLABACK_HPP
#define MYNOTECALLABACK_HPP
#include <cxxmidi/note.hpp>

namespace CxxMidi {

	class MyNoteCallaback
	{
	public:
		inline MyNoteCallaback() {};
		//inline ~MyNoteCallaback();

		virtual void operator() (CxxMidi::Note, bool) = 0;
	};
}

#endif
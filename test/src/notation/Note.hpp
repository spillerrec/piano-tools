/*	This file is part of piano-tools, which is free software and is licensed
 * under the terms of the GNU GPL v3.0. (see http://www.gnu.org/licenses/ ) */
#ifndef NOTATION__NOTE_HPP
#define NOTATION__NOTE_HPP

#include "Duration.hpp"
#include "Tone.hpp"

namespace Notation{

struct Note{
	Tone tone;
	Duration duration;
	
	Note( Tone tone, Duration duration )
		: tone(tone), duration(duration) { }
};
//TODO: basic math operations

}
#endif

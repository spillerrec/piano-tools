/*	This file is part of piano-tools, which is free software and is licensed
 * under the terms of the GNU GPL v3.0. (see http://www.gnu.org/licenses/ ) */

#include "MidiContents.hpp"

#include <midifile/MidiFile.h>

#include <iostream>

using namespace Midi;
using namespace std;

MidiContents::MidiContents( const string& filepath ){
	MidiFile file( filepath );
	
	cout << "MIDI file contains " << file.size() << " tracks" << endl;
	/*
	for( int track=0; track<file.size(); track++ )
		for( int event=0; event<file[track].size(); event++ ){
			cout << "Event" << endl;
		}
		*/
}

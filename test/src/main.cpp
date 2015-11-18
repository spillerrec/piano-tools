#include <iostream>
#include <vector>
#include <RtMidi.h>

double total_time = 0.0;

void callback( double deltatime, std::vector<unsigned char>* message, void *userData ){
	total_time += deltatime;
	if( message->size() == 3 && message->at(0) == 144 ){
		int key = message->at(1);
		int octave = (key / 12) - 2;
		std::string letter = std::vector<std::string>( { "C", "C#", "D", "Eb", "E", "F", "F#", "G", "G#", "A", "Bb", "B" } )[ (key %12) ];
		std::cout << "Key " << (message->at(2) > 0 ? "pressed" : "released") << ": " << letter << " in octave: " << octave << std::endl;
	}
	else{
		unsigned int nBytes = message->size();
		for ( unsigned int i=0; i<nBytes; i++ )
			std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
		if ( nBytes > 0 )
			std::cout << "stamp = " << total_time << std::endl;
	}
}

#include <QWidget>
#include <QApplication>
#include <QRawFont>
#include <QFont>
#include <QPainter>
class DrawFont : public QWidget{
	private:
		QFont font;
	
	public:
		DrawFont() : QWidget( nullptr ), font( QString("Bravura" ), 32.0 ){
		};
	
	private:
		void paintEvent( QPaintEvent* ) override{
			QPainter painter( this );
			painter.setFont( font );
			painter.drawText( 100,100, QString( "\uE01B\uE01B\uE01B\uE01B\uE01B\uE01B\uE01B\uE01B" ) );
			painter.drawText( 100,100, QString( "\uE050\uE1D7\uE1D4\uE1E7 \uE1E5 \uE1D5\uE1F3" ) );
		}
};

int main( int argc, char *argv[] ){
	//*
	try{
	//	std::vector<RtMidi::Api> apis;
	//	RtMidi::getCompiledApi( apis );
	//	for( auto api : apis )
	//		std::cout << api << std::endl;
		
		RtMidiIn  midiin;
		RtMidiOut midiout;
		
		unsigned nPorts = midiin.getPortCount();
		std::cout << "\nThere are " << nPorts << " MIDI input sources available.\n";
		for( unsigned i=0; i<nPorts; i++ )
			std::cout << "\tInput Port #" << i+1 << ": " << midiin.getPortName(i) << std::endl;
		
		if( nPorts > 0 ){
			midiin.openPort( 1 );
			midiin.setCallback( &callback );
			midiin.ignoreTypes( false, false, false );
			
			char input;
			std::cin >> input;
		}
		
		nPorts = midiout.getPortCount();
		std::cout << "\nThere are " << nPorts << " MIDI output ports available.\n";
		for( unsigned i=0; i<nPorts; i++ )
			std::cout << "\tOutput Port #" << i+1 << ": " << midiout.getPortName(i) << std::endl;
		
		std::cout << std::endl;
	}
	catch( RtMidiError &error ){
		error.printMessage();
		return -1;
	}
	return 0;
	/*/
	QApplication a( argc, argv );
	DrawFont font;
	font.show();
	font.update();
	return a.exec();
	//*/
	
}
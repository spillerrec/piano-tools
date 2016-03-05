######################################################################
# Automatically generated by qmake (3.0) ma maj 25 20:25:52 2015
######################################################################

TEMPLATE = app
TARGET = miditest
LIBS += -lrtmidi -lmidifile
INCLUDEPATH += deps/include /usr/include/guido
QT += gui widgets printsupport
QMAKE_CXXFLAGS += -std=c++14

# Input
#HEADERS += 
SOURCES += src/main.cpp

HEADERS += src/midi/MidiContents.hpp
SOURCES += src/midi/MidiContents.cpp

HEADERS += src/notation/Duration.hpp src/notation/Note.hpp src/notation/Tone.hpp
SOURCES += 

LIBS += -Ldeps/libs -lGuidoQt
LIBS += -lGUIDOEngine

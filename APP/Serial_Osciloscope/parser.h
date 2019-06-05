#ifndef PARSER_H
#define PARSER_H

#include   <QSerialPort>


struct Frame
{
    uchar id;
    uchar length;
    uchar data[256];

    uchar GetHeaderSum();
    uchar GetDataSum();
    Frame();
};

enum ParserState
{
    PARSER_ERROR = 0,
    PARSER_COMPLETE,
};

class Parser
{
private:
    enum State{
        STATE_WAIT,
        STATE_GOT_MARKER,
        STATE_GOT_ID,
        STATE_GOT_LEN,
        STATE_GOT_HEADER,
        STATE_GOT_DATA
    };

    Parser();

public:
    static const char STATRT_BYTE = '>';
    static const char ID_DATA = 'i';

    static ParserState ReadFrame(QByteArray &bytes, Frame &out);
};

#endif // PARSER_H

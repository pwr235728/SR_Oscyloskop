#include "parser.h"

Frame::Frame()
    : id(0), length(0)
{
}
uchar Frame::GetHeaderSum()
{
    return (id + length);
}
uchar Frame::GetDataSum()
{
    uchar sum = 0;
    for(int i=0; i<length && i<256; i++)
    {
        sum += data[i];
    }
    return sum;
}
Parser::Parser()
{

}

ParserState Parser::ReadFrame(QByteArray &bytes, Frame &out)
{
    Frame frame;

    State state = STATE_WAIT;
    uchar data_index = 0;

    for(int readIndex=0; readIndex<bytes.length(); readIndex++)
    {

        uchar byte =  uchar(bytes[readIndex]);
        switch(state)
        {
        case STATE_WAIT:{
            if(byte == STATRT_BYTE){
                state = STATE_GOT_MARKER;
            }else
            {

            }
        } break;

        case STATE_GOT_MARKER:{
            frame.id = byte;
            state = STATE_GOT_ID;

        } break;

        case STATE_GOT_ID:{
            frame.length = byte;
            state = STATE_GOT_LEN;
        } break;

        case STATE_GOT_LEN:{
            if(byte == frame.GetHeaderSum())
            {
                state = (frame.length == 0 ? STATE_GOT_DATA : STATE_GOT_HEADER);
            }else{
                // some bananas happened


                state = STATE_WAIT;
            }

        } break;

        case STATE_GOT_HEADER:{
            frame.data[data_index++] = byte;
            if(data_index == frame.length)
            {
                state = STATE_GOT_DATA;
            }else
            {

            }
        } break;

        case STATE_GOT_DATA:{
            state = STATE_WAIT;

            if(byte == frame.GetDataSum())
            {
                out = frame;

                bytes.remove(0, readIndex+1);
                return PARSER_COMPLETE;
            }else
            {


                bytes.remove(0, readIndex+1); // remove corrupted data
                return PARSER_ERROR;
            }
        } break;
        }
    }


    return PARSER_ERROR;
}

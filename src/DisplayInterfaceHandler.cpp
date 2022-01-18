#include "DisplayInterfaceHandler.h"

DisplayInterfaceHandler::DisplayInterfaceHandler() = default;

void DisplayInterfaceHandler::setup()
{
    ardDisplaySerial.begin(baudRate);
    changePage(startPage);
}

uint8_t* DisplayInterfaceHandler::getDrinkData()
{
    static uint8_t dataBuffer[contentsBuffLen];

    if (!ardDisplaySerial.available()){
        return nullptr;
    }

    ardDisplaySerial.readBytes(dataBuffer, contentsBuffLen);
    return dataBuffer;
}

void DisplayInterfaceHandler::writeUselessBytes(){
    for (int i = 0; i < 3 ; ++i) {
        ardDisplaySerial.write(0xFF);
    }
};

void DisplayInterfaceHandler::changePage(const String& page){
    ardDisplaySerial.print(page);
    writeUselessBytes();
}

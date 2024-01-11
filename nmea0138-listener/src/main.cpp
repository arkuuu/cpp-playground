#include <iostream>
#include <string>

#include "connection.h"
#include "nmea_0138.h"

#define MAX_LENGTH 200
#define NMEA_PORT 54321
#define NMEA_IP_ADDRESS "127.0.0.1"

int main()
{
    // TODO catch exceptions
    Connection connection;
    connection.connect(NMEA_IP_ADDRESS, NMEA_PORT);

    std::cout << "Receiving NMEA data..." << std::endl;

    std::string message;
    int bytesReceived;
    Nmea0138Parser nmeaParser;
    while (true)
    {
        bytesReceived = connection.receive(message);
        std::cout << message;
        // bool isValid = nmeaParser.isValid(message);
        Nmea0138Sentence sentence = nmeaParser.parse(message);
        std::cout << "talkerId: " << sentence.talkerId << std::endl;
        std::cout << "dataType: " << sentence.dataType << std::endl;
        for (int i = 0; i <= sentence.data.size(); i++)
        {
            std::cout << "data[" << i << "]: " << sentence.data[i] << std::endl;
        }

        std::cout << "checksum: " << sentence.checksum << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

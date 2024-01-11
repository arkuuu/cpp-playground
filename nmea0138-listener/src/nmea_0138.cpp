#include "nmea_0138.h"

#include <sstream>

bool Nmea0138Parser::isValid(const std::string message)
{
    // Must start with $ or !
    if (message[0] != '$' && message[0] != '!')
    {
        return false;
    }

    // Must have checksum `*xx\r\n` at the end
    if (message[message.size() - 5] != '*')
    {
        return false;
    }

    // TODO verify checksum
    return true;
}

Nmea0138Sentence Nmea0138Parser::parse(const std::string message)
{
    Nmea0138Sentence sentence;
    sentence.talkerId = message.substr(1, 2);
    sentence.dataType = message.substr(3, 3);
    sentence.checksum = message.substr(message.size() - 4, 2);

    // Split the comma separated data fields
    std::stringstream ss(message.substr(7, message.size() - 12));
    std::string str;
    while (getline(ss, str, ','))
    {
        sentence.data.push_back(str);
    }

    return sentence;
}

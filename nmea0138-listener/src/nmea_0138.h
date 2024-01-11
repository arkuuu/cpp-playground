#ifndef NMEA_0138_H_
#define NMEA_0138_H_

#include <string>
#include <vector>

struct Nmea0138Sentence
{
    std::string talkerId;
    std::string dataType;
    std::vector<std::string> data;
    std::string checksum;
};

class Nmea0138Parser
{
public:
    bool isValid(const std::string message);
    Nmea0138Sentence parse(const std::string message);
};

#endif // NMEA_0138_H_

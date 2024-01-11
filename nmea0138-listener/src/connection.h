#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>
#include <netinet/in.h>

class Connection
{
public:
    ~Connection();
    void connect(std::string ipAdress, int port);
    bool isConnected();
    int receive(std::string &sentence);

private:
    int socketfd = 0;
    sockaddr_in socketAddress;
};

#endif // CONNECTION_H_

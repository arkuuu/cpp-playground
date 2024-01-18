#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>
#include <netinet/in.h>

#define BUFFER_SIZE 200

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
    char buffer[BUFFER_SIZE] = {0};
};

#endif // CONNECTION_H_

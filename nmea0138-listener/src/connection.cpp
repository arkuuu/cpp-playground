#include "connection.h"

#include <unistd.h>
#include <arpa/inet.h>

Connection::~Connection()
{
    if (isConnected())
    {
        close(socketfd);
    }
}

void Connection::connect(const std::string ipAdress, const int port)
{
    socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socketfd < 0)
    {
        throw "Unable to open socket"; // TODO errno
    }

    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(port);
    socketAddress.sin_addr.s_addr = inet_addr(ipAdress.c_str());

    int bindStatus = bind(
        socketfd,
        (sockaddr *)&socketAddress,
        sizeof(socketAddress));

    if (bindStatus < 0)
    {
        throw "Unable to bind socket"; // TODO errno
    }
}

bool Connection::isConnected()
{
    return socketfd > 0;
}

int Connection::receive(std::string &message)
{
    if (!isConnected())
    {
        throw "Need active connection to read from";
    }

    int bytesReceived;
    socklen_t sizeofSocketAddress = sizeof(sockaddr_storage);

    // TODO Maybe use recvmsg, recv instead, what's the difference?
    bytesReceived = recvfrom(
        socketfd,
        buffer,
        BUFFER_SIZE,
        MSG_WAITALL,
        (sockaddr *)&socketAddress,
        &sizeofSocketAddress);

    message.assign(buffer, bytesReceived);

    if (bytesReceived < 0)
    {
        throw "Unable to read from socket"; // TODO errno
    }

    return bytesReceived;
}

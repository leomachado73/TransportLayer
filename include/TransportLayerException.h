#ifndef TRANSPORT_LAYER_EXCEPTION_H
#define TRANSPORT_LAYER_EXCEPTION_H

#include <exception>
#include <string>

class TransportLayerException : public std::exception
{
private:
    std::string reason;
public:

    TransportLayerException(const std::string &reason)
    {
        this->reason = reason;
    }

    ~TransportLayerException() override
    {
    }

    const char *what() const throw()
    {
        return this->reason.c_str();
    }
};

#endif //TRANSPORT_LAYER_EXCEPTION_H

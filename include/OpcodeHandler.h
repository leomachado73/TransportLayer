#ifndef OPCODE_HANDLER_H
#define OPCODE_HANDLER_H

#include <string>
#include <vector>
#include "Permission.h"
#include "Middleware.h"
#include "TransportLayerException.h"


class OpcodeHandler
{
private:
    // Name
    std::string _name;

    // Summary
    std::string _summary;

    // Description
    std::string _description;

    // Specifies who has authorization to access this handler
    std::vector<Permission*> _authorizations;

    // Local Middlewares
    Middleware* _localMiddlewares;

public:

    OpcodeHandler()
    {
        _name = "";
        _summary = "";
        _description = "";
        _authorizations.clear();
        _localMiddlewares = nullptr;
    }

     ~OpcodeHandler()
     {
        for(auto &i : _authorizations)
        {
            delete i;
        }

        _authorizations.clear();

        if(_localMiddlewares)
        {
            delete _localMiddlewares;
            _localMiddlewares = nullptr;
        }
     }


    std::string getName() const {
        return _name;
    }

    OpcodeHandler& name(const std::string &value)
    {
        this->_name = value;

        return *this;
    }

    std::string getSmmary() const {
        return _summary;
    }

    OpcodeHandler& summary(const std::string &value)
    {
        this->_summary = value;

        return *this;
    }

    std::string getDescription() const {
        return _description;
    }

    OpcodeHandler& description(const std::string &value)
    {
        this->_description = value;

        return *this;
    }

    template<typename ...T>
    OpcodeHandler& authorizations(T... auth)
    {
        Permission* args[]{ auth... };

        for(auto &i : args)
            _authorizations.push_back(i);

        return *this;

    }

    std::vector<Permission*> getAuthorizations() const {
        return _authorizations;
    }



    template<typename ... T>
    OpcodeHandler& handlers(T&& ... handler)
    {
        Middleware* args[]{ handler... };

        for(auto &i : args)
        {
            if(!i)
                throw TransportLayerException("Cannot add a null pointer handler.");

            if(_localMiddlewares)
                _localMiddlewares->append(i);
            else
                _localMiddlewares = i;
        }


        return *this;
    }

    Middleware* handlers() const {
        return _localMiddlewares;
    }




};


#endif //OPCODE_HANDLER_H

#include "Rabbids.hpp"

class Rabbids : public IControlable
{
private:
    std::string objectSymbol = "V";
    std::unordered_map<Commands, ICommand *> _command;
    int _x;
    int _y;
    Directions _z;
    bool _isSucked;

public:
    Rabbids()
    {
        _x = 0;
        _y = 0;
        _z = Directions::Right;
        _isSucked = false;
    }

    void Rabbids::setCommand(ICommand *command)
    {
        if (_command.find(command->getEnum()) == _command.end())
        {
            _command[command->getEnum()] = command;
        }
    }

    ICommand *Rabbids::getCommand(Commands commands)
    {
        return _command[commands];
    }

    void Rabbids::setPosition(int x, int y)
    {
        _x = x;
        _y = y;
    }

    void Rabbids::setPositionX(int x)
    {
        _x = x;
    }

    void Rabbids::setPositionY(int y)
    {
        _y = y;
    }

    std::pair<int, int> getPosition()
    {
        return std::make_pair(_x, _y);
    }

    void Rabbids::setDirection(int direction)
    {
        switch (direction)
        {
        case 0:
            _z = Directions::Right;
            break;
        case 90:
            _z = Directions::Down;
            break;
        case 180:
            _z = Directions::Left;
            break;
        case 270:
            _z = Directions::Up;
            break;
        default:
            std::cout << "Invalid direction!" << std::endl;
            break;
        }
    }

    Directions Rabbids ::getDirection()
    {
        return _z;
    }

    bool Rabbids::isSucked()
    {
        return _isSucked;
    }

    std::string getObjectSymbol()
    {
        return objectSymbol;
    }
};
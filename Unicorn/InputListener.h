#ifndef INPUTLISTENER_H_INCLUDED
#define INPUTLISTENER_H_INCLUDED

#include <SFML/Window.hpp>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Singleton.h"
#include <cmath>

namespace unicorn {
    struct JoystickButton {
        int joystickID;
        int buttonID;
    };

    struct JoystickAxis {
        int joystickID;
        sf::Joystick::Axis axisID;
    };


    class InputListener : public Singleton<InputListener> {
        friend class Singleton<InputListener>;
    public:
    bool loadConfigFile(std::string filepath);

    float MouseCursorX() {return sf::Mouse::getPosition().x;};
    float MouseCursorY() {return sf::Mouse::getPosition().x;};

    float AxisPosition(std::string key);
        
    void addInput(std::string key, std::string input);

    bool listen(std::string key);
        bool SingleInput(std::string key);

    private:
    InputListener();
        
    void initKeyboardMap();
    void initMouseMap();
    void initJoystickMap();
    void init();

    std::map<std::string, sf::Keyboard::Key> _keyboardMap;
    std::map<std::string, sf::Mouse::Button> _mouseMap;
    std::map<std::string, JoystickButton> _joystickButton;
    std::map<std::string, JoystickAxis> _joystickAxis;
        
    std::map<std::string, bool> _singleInput;
    };
};

#endif // INPUTLISTENER_H_INCLUDED

#include "InputListener.h"

namespace unicorn {
    InputListener::InputListener(){
        init();
    }

    bool InputListener::loadConfigFile(std::string filepath) {
        return true;
    }

    void InputListener::addInput(std::string key, std::string input) { //méthode d'ajout d'entrés en temps réels
        for(std::map<std::string, sf::Mouse::Button>::iterator it = _mouseMap.begin(); it != _mouseMap.end(); it++) {
            if(it->first == input) {
                _mouseMap[key] = it->second; // on parcout la std::map de la souris pour connaitre si l'entré correspond si oui on ajoute
                return;
            }
        }
        for(std::map<std::string, sf::Keyboard::Key>::iterator it = _keyboardMap.begin(); it != _keyboardMap.end(); it++) {
            if(it->first == input) {
                _keyboardMap[key] = it->second; // meme chose sauf avec le clavier
                return;
            }
        }
        for(std::map<std::string, JoystickButton>::iterator it = _joystickButton.begin(); it != _joystickButton.end(); it++) {
            if(it->first == input) {
                _joystickButton[key] = it->second; // meme chose sauf avec le clavier
                return;
            }
        }
        for(std::map<std::string, JoystickAxis>::iterator it = _joystickAxis.begin(); it != _joystickAxis.end(); it++) {
            if(it->first == input) {
                _joystickAxis[key] = it->second; // meme chose sauf avec le clavier
                return;
            }
        }
    }

    bool InputListener::listen(std::string key) { // renvoi true si l'entré correspondant est activé

        for(std::map<std::string, sf::Mouse::Button>::iterator it = _mouseMap.begin(); it != _mouseMap.end(); it++) {
            if(it->first == key) {
                if(sf::Mouse::isButtonPressed(it->second))
                    return true;
            }
        }

        for(std::map<std::string, sf::Keyboard::Key>::iterator it = _keyboardMap.begin(); it != _keyboardMap.end(); it++) {
            if(it->first == key) {
                if(sf::Keyboard::isKeyPressed(it->second))
                    return true;
            }
        }
        
        for(std::map<std::string, JoystickButton>::iterator it = _joystickButton.begin(); it != _joystickButton.end(); it++) {
            if(it->first == key) {
                if(sf::Joystick::isButtonPressed(it->second.joystickID, it->second.buttonID)) {
                    return true;
                }
            }
        }

    return false;
    }

    bool InputListener::SingleInput(std::string key) {
        
        if(this->listen(key) && !_singleInput[key]) {
            _singleInput[key] = true;
            return true;
        } else if (!this->listen(key)) {
            _singleInput[key] = false;
        }
        
        return false;
    }

    float InputListener::AxisPosition(std::string key) {
        for(std::map<std::string, JoystickAxis>::iterator it = _joystickAxis.begin(); it != _joystickAxis.end(); it++) {
            if(it->first == key) {
                float pos = sf::Joystick::getAxisPosition(it->second.joystickID, it->second.axisID);
                
                if(fabs(pos) > 10.0f)
                    return pos / 100;
                else
                    return 0;
            }
        }
        
        return 0;
    }

    void InputListener::initKeyboardMap() { // ici on initialise chacunes des touches et boutons
        _keyboardMap["a"] = sf::Keyboard::A;
        _keyboardMap["b"] = sf::Keyboard::B;
        _keyboardMap["c"] = sf::Keyboard::C;
        _keyboardMap["d"] = sf::Keyboard::D;
        _keyboardMap["e"] = sf::Keyboard::E;
        _keyboardMap["f"] = sf::Keyboard::F;
        _keyboardMap["g"] = sf::Keyboard::G;
        _keyboardMap["h"] = sf::Keyboard::H;
        _keyboardMap["i"] = sf::Keyboard::I;
        _keyboardMap["j"] = sf::Keyboard::J;
        _keyboardMap["k"] = sf::Keyboard::K;
        _keyboardMap["l"] = sf::Keyboard::L;
        _keyboardMap["m"] = sf::Keyboard::M;
        _keyboardMap["n"] = sf::Keyboard::N;
        _keyboardMap["o"] = sf::Keyboard::O;
        _keyboardMap["p"] = sf::Keyboard::P;
        _keyboardMap["q"] = sf::Keyboard::Q;
        _keyboardMap["r"] = sf::Keyboard::R;
        _keyboardMap["s"] = sf::Keyboard::S;
        _keyboardMap["t"] = sf::Keyboard::T;
        _keyboardMap["u"] = sf::Keyboard::U;
        _keyboardMap["v"] = sf::Keyboard::V;
        _keyboardMap["w"] = sf::Keyboard::W;
        _keyboardMap["x"] = sf::Keyboard::X;
        _keyboardMap["y"] = sf::Keyboard::Y;
        _keyboardMap["z"] = sf::Keyboard::Z;

        _keyboardMap["1"] = sf::Keyboard::Num1;
        _keyboardMap["2"] = sf::Keyboard::Num2;
        _keyboardMap["3"] = sf::Keyboard::Num3;
        _keyboardMap["4"] = sf::Keyboard::Num4;
        _keyboardMap["5"] = sf::Keyboard::Num5;
        _keyboardMap["6"] = sf::Keyboard::Num6;
        _keyboardMap["7"] = sf::Keyboard::Num7;
        _keyboardMap["8"] = sf::Keyboard::Num8;
        _keyboardMap["9"] = sf::Keyboard::Num9;
        _keyboardMap["0"] = sf::Keyboard::Num0;

        _keyboardMap["space"] = sf::Keyboard::Space;
        _keyboardMap["return"] = sf::Keyboard::Return;
        _keyboardMap["backspace"] = sf::Keyboard::Back;
        _keyboardMap["escape"] = sf::Keyboard::Escape;

        _keyboardMap["left"] = sf::Keyboard::Left;
        _keyboardMap["right"] = sf::Keyboard::Right;
        _keyboardMap["up"] = sf::Keyboard::Up;
        _keyboardMap["down"] = sf::Keyboard::Down;

        _keyboardMap["ctrL"] = sf::Keyboard::LControl;
        _keyboardMap["ctrR"] = sf::Keyboard::RControl;
        _keyboardMap["altL"] = sf::Keyboard::LAlt;
        _keyboardMap["altR"] = sf::Keyboard::RAlt;
        _keyboardMap["shiftL"] = sf::Keyboard::LShift;
        _keyboardMap["shiftR"] = sf::Keyboard::RShift;
    }

    void InputListener::initMouseMap() {
        _mouseMap["leftButton"] = sf::Mouse::Left;
        _mouseMap["rightButton"] = sf::Mouse::Right;
        _mouseMap["middleButton"] = sf::Mouse::Middle;

        _mouseMap["extraButton1"] = sf::Mouse::XButton1;
        _mouseMap["extraButton2"] = sf::Mouse::XButton2;
    }

    void InputListener::initJoystickMap() {
        for(int joy = 0; joy < sf::Joystick::Count; joy++) { //Pour chaque joystick supportŽ, on compte crŽe une entrŽ pour tous les boutons possibles
            for(int button = 0; button < sf::Joystick::ButtonCount; button++) { // soit 32
                std::stringstream out;
                
                out << "joy" << joy << "button" << button;
                
                JoystickButton a;
                a.joystickID = joy;
                a.buttonID = button;
                
                _joystickButton[out.str()] = a;
            }
            
            for(int axis = 0; axis < sf::Joystick::AxisCount; axis++) {
                std::stringstream out;
                
                std::string axisName;
                JoystickAxis a;
                a.joystickID = joy;
                
                switch (axis) {
                    case 0:
                        axisName = "X";
                        a.axisID = sf::Joystick::X;
                        break;
                    case 1:
                        axisName = "Y";
                        a.axisID = sf::Joystick::Y;
                        break;
                    case 2:
                        axisName = "Z";
                        a.axisID = sf::Joystick::Z;
                        break;
                    case 3:
                        axisName = "R";
                        a.axisID = sf::Joystick::R;
                        break;
                    case 4:
                        axisName = "U";
                        a.axisID = sf::Joystick::U;
                        break;
                    case 5:
                        axisName = "V";
                        a.axisID = sf::Joystick::V;
                        break;
                    case 6:
                        axisName = "PovX";
                        a.axisID = sf::Joystick::PovX;
                        break;
                    case 7:
                        axisName = "PovY";
                        a.axisID = sf::Joystick::PovY;
                        break;
                    default:
                        break;
                }
                
                out << "joy" << joy << "axis" << axisName;
                
                _joystickAxis[out.str()] = a;
            }
        }
    }

    void InputListener::init() { // fonction d'initialisation
        initMouseMap(); //initialisation de la souris
        initKeyboardMap(); // du clavier
        initJoystickMap(); // des joysticks
    }
};
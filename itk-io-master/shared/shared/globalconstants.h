#ifndef GLOBALCONSTANTS_H
#define GLOBALCONSTANTS_H

#include <QtCore>

enum class verticalDirection { FORWARD, BACKWARD , REST };
enum class turnDirection {LEFT,RIGHT,REST};
enum class fireDirection {LEFT,RIGHT,LEFTRIGHT, NONE};


QString verticalDirectionToString(verticalDirection e){
    switch(e){
        case verticalDirection::FORWARD:
            return "FORWARD";

        case verticalDirection::BACKWARD:
            return "BACKWARD";

        case verticalDirection::REST:
            return "REST";

    }
};
QString turnDirectionToString(turnDirection e){
    switch(e){
        case turnDirection::LEFT:
            return "LEFT";

        case turnDirection::RIGHT:
            return "RIGHT";

        case turnDirection::REST:
            return "REST";

    }
};
QString fireDirectionToString(fireDirection e){
    switch(e){
        case fireDirection::LEFT:
            return "LEFT";

        case fireDirection::RIGHT:
            return "RIGHT";

        case fireDirection::NONE:
            return "NONE";
        case fireDirection::LEFTRIGHT:
            return "LEFTRIGHT";

    }
};

verticalDirection verticalDirectionFromString(QString str){
    if(str == "FORWARD"){
        return verticalDirection::FORWARD;

    }else if(str == "BACKWARD"){
        return verticalDirection::BACKWARD;

    }else if(str == "REST"){
        return verticalDirection::REST;

    }
}
turnDirection turnDirectionFromString(QString str){
    if(str == "LEFT"){
        return turnDirection::LEFT;

    }else if(str == "RIGHT"){
        return turnDirection::RIGHT;

    }else if(str == "REST"){
        return turnDirection::REST;

    }
}
fireDirection fireDirectionFromString(QString str){
    if(str == "LEFT"){
        return fireDirection::LEFT;

    }else if(str == "RIGHT"){
        return fireDirection::RIGHT;


    }else if(str == "LEFTRIGHT"){
        return fireDirection::LEFTRIGHT;

    }
    else if(str == "NONE"){
        return fireDirection::NONE;

    }
}
#endif // GLOBALCONSTANTS_H

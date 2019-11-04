#include "serializable.h"

QString Serializable::verticalDirectionToString(verticalDirection e){
    switch(e){
        case verticalDirection::FORWARD:
            return "FORWARD";

        case verticalDirection::BACKWARD:
            return "BACKWARD";

        case verticalDirection::REST:
            return "REST";

    }
};
QString Serializable::turnDirectionToString(turnDirection e){
    switch(e){
        case turnDirection::LEFT:
            return "LEFT";

        case turnDirection::RIGHT:
            return "RIGHT";

        case turnDirection::REST:
            return "REST";

    }
};
QString Serializable::fireDirectionToString(fireDirection e){
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

verticalDirection Serializable::verticalDirectionFromString(QString str){
    if(str == "FORWARD"){
        return verticalDirection::FORWARD;

    }else if(str == "BACKWARD"){
        return verticalDirection::BACKWARD;

    }else if(str == "REST"){
        return verticalDirection::REST;

    }
}
turnDirection Serializable::turnDirectionFromString(QString str){
    if(str == "LEFT"){
        return turnDirection::LEFT;

    }else if(str == "RIGHT"){
        return turnDirection::RIGHT;

    }else if(str == "REST"){
        return turnDirection::REST;

    }
}
fireDirection Serializable::fireDirectionFromString(QString str){
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

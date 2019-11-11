#include "serializehelper.h"
#include "playerinfo.cpp"
serializeHelper::serializeHelper()
{

}
QString serializeHelper::verticalDirectionToString(verticalDirection e){
    switch(e){
        case verticalDirection::FORWARD:
            return "FORWARD";

        case verticalDirection::BACKWARD:
            return "BACKWARD";

        case verticalDirection::REST:
            return "REST";

    }
};
QString serializeHelper::turnDirectionToString(turnDirection e){
    switch(e){
        case turnDirection::LEFT:
            return "LEFT";

        case turnDirection::RIGHT:
            return "RIGHT";

        case turnDirection::REST:
            return "REST";

    }
};
QString serializeHelper::fireDirectionToString(fireDirection e){
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

verticalDirection serializeHelper::verticalDirectionFromString(QString str){
    if(str == "FORWARD"){
        return verticalDirection::FORWARD;

    }else if(str == "BACKWARD"){
        return verticalDirection::BACKWARD;

    }else if(str == "REST"){
        return verticalDirection::REST;

    }
}
turnDirection serializeHelper::turnDirectionFromString(QString str){
    if(str == "LEFT"){
        return turnDirection::LEFT;

    }else if(str == "RIGHT"){
        return turnDirection::RIGHT;

    }else if(str == "REST"){
        return turnDirection::REST;

    }
}
fireDirection serializeHelper::fireDirectionFromString(QString str){
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
QString serializeHelper::playerInfoListToString(list<Playerinfo*> plist){
    QString result = "";
    for(auto player : plist){
        result.append(player->getSerializedClass()).append("%");
    }
    return result;

};
list<Playerinfo*> serializeHelper::playerInfoListFromString(QString str){

};

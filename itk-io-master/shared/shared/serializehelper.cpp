#include "serializehelper.h"

QString serializeHelper::verticalDirectionToString(verticalDirection e){
    switch(e){
        case verticalDirection::FORWARD:
            return "FORWARD";

        case verticalDirection::BACKWARD:
            return "BACKWARD";

        case verticalDirection::REST:
            return "REST";
    }
    return "REST";
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
    return "REST";
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
    return "NONE";
};

verticalDirection serializeHelper::verticalDirectionFromString(QString str){
    if(str == "FORWARD"){
        return verticalDirection::FORWARD;

    }else if(str == "BACKWARD"){
        return verticalDirection::BACKWARD;

    }else if(str == "REST"){
        return verticalDirection::REST;

    }
     return verticalDirection::REST;
}
turnDirection serializeHelper::turnDirectionFromString(QString str){
    if(str == "LEFT"){
        return turnDirection::LEFT;

    }else if(str == "RIGHT"){
        return turnDirection::RIGHT;

    }else if(str == "REST"){
        return turnDirection::REST;

    }
    return turnDirection::REST;
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
     return fireDirection::NONE;
}
QString serializeHelper::playerInfoListToString(list<Playerinfo*> plist){
    QString result = "";
    for(auto player : plist){
        result.append(player->getSerializedClass()).append("%");
    }
    return result;

};
list<Playerinfo*> serializeHelper::playerInfoListFromString(QString str){
    list<Playerinfo*> newplayers;
     QStringList playerinfos = str.split("%");
     for(auto e:playerinfos){
          QStringList pieces = e.split("|");
          Playerinfo* p;
          if(pieces[1] == "A"){
              //advancedplayerinfo
               p = new AdvancedPlayerInfo();
          }else if(pieces[1] == "B"){
                //boringplayerinfo
              p = new BoringPlayerInfo(e);

          }else if(pieces[1] == "F"){
              //firstplayerinfo
            p = new FirstPlayerInfo(e);

          }else if(pieces[1] == "M"){
            p = new MinimalPlayerInfo(e);
          }
          else if(pieces[1] == "O"){
              //ownplayerinfo
            p = new OwnPlayerInfo(e);
          }
          newplayers.push_back(p);
     }
    return newplayers;
};

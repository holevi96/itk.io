#ifndef PLAYERINFO_H
#define PLAYERINFO_H
#include <QtCore>
#include "serializable.h"


class Playerinfo : public Serializable{
public:
    Playerinfo();
    Playerinfo(int id);
    virtual ~Playerinfo();
   // QString getSerializedClass();
  //  void setClassBySerializedString(QString serial) = 0;
    int getId() const;

protected:
    int id;
private:

};

#endif // PLAYERINFO_H

#ifndef DESIGN_H
#define DESIGN_H
#include "serializable.h"

class Design : public Serializable
{
public:
    Design();
    int color;
    QString getSerializedClass();
    void setClassBySerializedString(QString serial);
};

#endif // DESIGN_H

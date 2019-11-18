#ifndef DESIGN_H
#define DESIGN_H
#include "serializable.h"

class Design : public Serializable
{
public:
    Design();
    Design(QString serial);
    virtual ~Design();
    int color;
    QString getSerializedClass();
};

#endif // DESIGN_H

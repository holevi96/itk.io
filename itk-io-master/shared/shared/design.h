#ifndef DESIGN_H
#define DESIGN_H
#include "serializable.h"
#include <cstdlib>
class Design : public Serializable
{
public:
    Design();
    Design(QString serial);
    Design(int color);
    virtual ~Design();
    int color;
    QString getSerializedClass() override;
    QString getName() override;
};

#endif // DESIGN_H

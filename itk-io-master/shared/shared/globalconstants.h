#ifndef GLOBALCONSTANTS_H
#define GLOBALCONSTANTS_H

#include <QtCore>

enum class verticalDirection { FORWARD, BACKWARD , REST };
enum class turnDirection {LEFT,RIGHT,REST};
enum class fireDirection {LEFT,RIGHT,LEFTRIGHT, NONE};

static const float shipSpeed = 0.1;
static const float turningSpeed = 1;

#endif // GLOBALCONSTANTS_H

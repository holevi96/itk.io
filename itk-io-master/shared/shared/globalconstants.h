#ifndef GLOBALCONSTANTS_H
#define GLOBALCONSTANTS_H

#include <QtCore>

enum class verticalDirection { FORWARD, BACKWARD , REST };
enum class turnDirection {LEFT,RIGHT,REST};
enum class fireDirection {LEFT,RIGHT,LEFTRIGHT, NONE};

static const float shipSpeed = 0.02;
static const float turningSpeed = 0.02;
static const float defaultRange = 200;

static const int globalShift = 500;

static const int reConnectDelay = 1000;

static const int halfFireHugeness = 5;

static const int env_sizeX = 1000;
static const int env_sizey = 1000;
static const float env_drag = 0.01;
static const float env_stepSize = 1;
static const float env_msPerStep = 10;

#endif // GLOBALCONSTANTS_H

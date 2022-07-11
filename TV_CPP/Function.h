#pragma once

#include <windows.h>
#include <iostream>
#include "Coordinates.h."
#include "Point.h"
#include "GetConsoleWin.h"
#include "PlasmaTV.h"
#include "PlasmaTVonStand.h"
#include "PlasmaTVwLegs.h"
#include "PlasmaTVScreenOn.h"
#include "PlasmaTVScreenOff.h"
#include "Remote.h"

bool Collision(PlasmaTV* figure1, Remote* figure2);
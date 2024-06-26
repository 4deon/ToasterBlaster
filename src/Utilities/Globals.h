#pragma once

#include "Utilities/Typedefs.h"
#include "Arduino.h"

extern Timestamp deltaTime;
extern u32 frameCount;
extern u32 boopCount;
extern u16 micValue;
extern char btStatus[16];
extern char uptime[16];

extern const char
    *PROJECT_NAME,
    *VERSION_NUMBER,
    *COMPILE_TIMESTAMP,
    *LINK_1,
    *LINK_2;
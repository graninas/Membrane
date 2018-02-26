#ifndef LOGIC_H
#define LOGIC_H

#include "membrane.h"
#include "schememanager.h"

namespace membrane
{

TwoBraneWorld step(const TwoBraneWorld& world, SchemeManager& bottomManager, SchemeManager &topManager);

} // namespace membrane

#endif // LOGIC_H

#ifndef PATTERN_H
#define PATTERN_H

#include "membrane.h"

#include <vector>

namespace membrane
{

struct Pattern
{
    Area area;

    I w() const;
    I h() const;
};

struct Scheme
{
    Pattern base;
    Pattern prod;
    I xOffset;
    I yOffset;
};

using Schemes = std::vector<Scheme>;

Pattern createPattern(I w, I h, bool filled);

} // namespace membrane

#endif // PATTERN_H

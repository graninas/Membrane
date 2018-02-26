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
    Pattern top;
    Pattern bottom;
};

using Schemes = std::vector<Scheme>;

Pattern createPattern(I w, I h, bool filled);
Scheme createScheme(const Pattern& bottom, const Pattern& top);


} // namespace membrane

#endif // PATTERN_H

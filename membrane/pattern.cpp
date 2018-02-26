#include "pattern.h"

#include <stdexcept>

namespace membrane
{

I Pattern::w() const
{
    return area.size();
}

I Pattern::h() const
{
    return area[0].size();
}

Pattern createPattern(I w, I h, bool filled)
{
    if (w <= 0 || h <= 0)
        throw std::runtime_error("Invalid bounds");

    return Pattern {createArea(w, h, filled)};
}

Scheme createScheme(const Pattern& bottom, const Pattern& top)
{
    return Scheme { bottom, top };
}

} // namespace membrane

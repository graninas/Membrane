#include "schememanager.h"

#include <functional>

namespace membrane {

void SchemeManager::setSchemes(const Schemes& bottomToTop)
{
    _schemes = bottomToTop;

    _wLimitations = std::accumulate(_schemes.begin(), _schemes.end(), 0, [](I acc, const Scheme& scheme){
        return std::max(acc, scheme.base.w());
    });

    _hLimitations = std::accumulate(_schemes.begin(), _schemes.end(), 0, [](I acc, const Scheme& scheme){
        return std::max(acc, scheme.base.h());
    });
}

I SchemeManager::getWLimitations() const
{
    return _wLimitations;
}

I SchemeManager::getHLimitations() const
{
    return _hLimitations;
}

bool matchPattern(const Pattern& pattern, const Area& area, I x, I y)
{
    bool matched = true;
    for (I i = 0; i < pattern.area.size(); ++i)
        for (I j = 0; j < pattern.area[i].size(); ++j)
        {
            matched = matched && pattern.area[i][j] == area[x + i][y + j];
        }
    return matched;
}

std::optional<Scheme> SchemeManager::match(const Area& area, I x, I y) const
{
    for (auto s = 0; s < _schemes.size(); s++)
    {
        if (matchPattern(_schemes.at(s).base, area, x, y))
        {
            return _schemes.at(s);
        }
    }

    return {};
}


} // namespace membrane

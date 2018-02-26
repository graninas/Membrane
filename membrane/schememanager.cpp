#include "schememanager.h"

#include <functional>

namespace membrane {

void SchemeManager::setSchemes(const Schemes& bottomToTop)
{
    _schemes = bottomToTop;

    _wLimitations = std::accumulate(_schemes.begin(), _schemes.end(), 0, [](I acc, const Scheme& scheme){
        return std::max(acc, scheme.bottom.w());
    });

    _hLimitations = std::accumulate(_schemes.begin(), _schemes.end(), 0, [](I acc, const Scheme& scheme){
        return std::max(acc, scheme.bottom.h());
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

Schemes SchemeManager::match(const Area& area, I i, I j) const
{
    return {};
}


} // namespace membrane

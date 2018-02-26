#ifndef SCHEMEMANAGER_H
#define SCHEMEMANAGER_H

#include <optional>

#include "pattern.h"

namespace membrane
{

class SchemeManager
{
public:
    SchemeManager() {}

    void setSchemes(const Schemes& bottomToTop);

    I getWLimitations() const;
    I getHLimitations() const;

    std::optional<Scheme> match(const Area &area, I x, I y) const;

private:

    Schemes _schemes;
    I _wLimitations;
    I _hLimitations;
};

}

#endif // SCHEMEMANAGER_H

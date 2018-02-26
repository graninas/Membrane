#ifndef SCHEMEMANAGER_H
#define SCHEMEMANAGER_H

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

    Schemes match(const Area &area, I i, I j) const;

private:

    Schemes _schemes;
    I _wLimitations;
    I _hLimitations;
};

}

#endif // SCHEMEMANAGER_H

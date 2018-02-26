#include "patterns.h"

namespace membrane {

Pattern block()
{
    return createPattern(2, 2, true);
}

Pattern h3Line()
{
    return createPattern(1, 3, true);
}

Pattern v3Line()
{
    return createPattern(3, 1, true);
}

Pattern point()
{
    return createPattern(1, 1, true);
}

}

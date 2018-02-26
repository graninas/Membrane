#include "patterns.h"

namespace membrane {

Pattern block()
{
    return Pattern {
        { {0, 0, 0, 0}
        , {0, 1, 1, 0}
        , {0, 1, 1, 0}
        , {0, 0, 0, 0}
        }
    };
}

Pattern h3Line()
{
    return Pattern {
        { {0, 0, 0, 0, 0}
        , {0, 1, 1, 1, 0}
        , {0, 0, 0, 0, 0}
        }
    };
}

Pattern v3Line()
{
    return Pattern {
        { {0, 0, 0}
        , {0, 1, 0}
        , {0, 1, 0}
        , {0, 1, 0}
        , {0, 0, 0}
        }
    };
}

Pattern pointBlueprint()
{
    return Pattern {
        { {1}
        }
    };
}

}

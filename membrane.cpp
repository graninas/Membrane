#include "membrane.h"

namespace membrane
{

TwoBraneWorld createWorld(I dim)
{
    TwoBraneWorld w;
    w.areaDimension = dim;

    w.topBrane.resize(w.areaDimension);
    w.bottomBrane.resize(w.areaDimension);

    for (auto i = 0; i < w.topBrane.size(); ++i)
    {
        w.topBrane[i].resize(w.areaDimension);
        w.bottomBrane[i].resize(w.areaDimension);

        for (auto j = 0; j < w.topBrane[i].size(); ++j)
        {
            w.topBrane[i][j] = 0;
            w.bottomBrane[i][j] = 0;
        }
    }

    return w;
}

TwoBraneWorld createRandomWorld(I dim, I l, I r, I t, I b)
{
    TwoBraneWorld w = createWorld(dim);

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,6);

    auto dice = std::bind ( distribution, generator );

    for (auto i = l; i < r; ++i)
        for (auto j = t; j < b; ++j)
        {
            auto rndVal = dice();
            w.bottomBrane[i][j] = rndVal == 1 ? 1 : 0;
        }

    return w;
}

void setCell(TwoBraneWorld& world, I i, I j, bool topBrane, I state)
{
    if (topBrane)
    {
        world.topBrane[i][j] = state;
    }
    else
    {
        world.bottomBrane[i][j] = state;
    }
}

} // namepspace membrane

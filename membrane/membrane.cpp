#include "membrane.h"

#include "patterns.h"
#include "schememanager.h"

namespace membrane
{

Area createArea(I w, I h, bool filled)
{
    Area a;
    a.resize(w);
    for (I i = 0; i < a.size(); ++i)
    {
        a[i].resize(h);

        // Filling can be done more effective with C++11 features
        if (filled)
        {
            for (I j = 0; j < a[i].size(); ++j)
            {
                a[i][j] = cAlive;
            }
        }
    }
    return a;
}

TwoBraneWorld createWorld(I areaDimension)
{
    TwoBraneWorld w;
    w.areaDimension = areaDimension;

    w.topBrane.resize(w.areaDimension);
    w.bottomBrane.resize(w.areaDimension);

    for (I i = 0; i < w.topBrane.size(); ++i)
    {
        w.topBrane[i].resize(w.areaDimension);
        w.bottomBrane[i].resize(w.areaDimension);
    }

    return w;
}

TwoBraneWorld createRandomWorld(I areaDimension, I l, I r, I t, I b)
{
    TwoBraneWorld w = createWorld(areaDimension);

    fillRandomUnsafe(w.bottomBrane, l, r, t, b, 4);

    return w;
}

void fillRandomUnsafe(Area &brane, I l, I r, I t, I b, int oneOfN)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, oneOfN);

    auto dice = std::bind ( distribution, generator );

    for (auto i = l; i < r; ++i)
        for (auto j = t; j < b; ++j)
        {
            auto rndVal = dice();
            brane[i][j] = rndVal == 1 ? cAlive : cDead;
        }
}

void fill2SideBlocks(Area &brane, I gridSize)
{
    for (I i = 0; i < brane.size() - 1; i += gridSize)
        for (I j = 0; j < brane.size() - 1; j += gridSize)
        {
            brane[i][j] = cAlive;
            brane[i + 1][j] = cAlive;
            brane[i][j + 1] = cAlive;
            brane[i + 1][j + 1] = cAlive;
        }
}

void setCell(TwoBraneWorld& world, I i, I j, bool topBrane, State state)
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

int neighboursUnsafe(const Area& area, I i, I j)
{
    return area[i - 1][j - 1]
         + area[i - 1][j]
         + area[i - 1][j + 1]
         + area[i][j - 1]
         + area[i][j + 1]
         + area[i + 1][j - 1]
         + area[i + 1][j]
         + area[i + 1][j + 1];
}

bool isAliveUnsafe(const Area& area, I i, I j)
{
    auto ns = neighboursUnsafe(area, i, j);
    return ((area[i][j] == cAlive) && (ns == 2))
            || (ns == 3);
}

} // namepspace membrane

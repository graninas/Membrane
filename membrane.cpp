#include "membrane.h"

namespace membrane
{

TwoBraneWorld createWorld(I areaDimension)
{
    TwoBraneWorld w;
    w.areaDimension = areaDimension;

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

TwoBraneWorld createRandomWorld(I areaDimension, I l, I r, I t, I b)
{
    TwoBraneWorld w = createWorld(areaDimension);

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,4);

    auto dice = std::bind ( distribution, generator );

    for (auto i = l; i < r; ++i)
        for (auto j = t; j < b; ++j)
        {
            auto rndVal = dice();
            w.bottomBrane[i][j] = rndVal == 1 ? 1 : 0;
        }

    return w;
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

bool isResourceGeneratorUnsafe(const Area& area, I i, I j)
{
    if (area[i][j] == cDead)
        return false;

    if ((area[i - 1][j] + area[i][j] + area[i + 1][j]) != 3)
        return false;

    return  ( area[i - 2][j - 1]
            + area[i - 2][j]
            + area[i - 2][j + 1]

            + area[i + 2][j - 1]
            + area[i + 2][j]
            + area[i + 2][j + 1]

            + area[i - 1][j - 1]
            + area[i][j - 1]
            + area[i + 1][j - 1]

            + area[i - 1][j + 1]
            + area[i][j + 1]
            + area[i + 1][j + 1]
            ) == 0;
}

void createResourceUnsafe(Area& area, I i, I j)
{
    area[i - 2][j - 2] = cAlive;
    area[i - 2][j] = cAlive;
    area[i - 2][j + 2] = cAlive;

    area[i][j - 2] = cAlive;
    area[i][j + 2] = cAlive;

    area[i + 2][j - 2] = cAlive;
    area[i + 2][j] = cAlive;
    area[i + 2][j + 2] = cAlive;

    area[i - 1][j - 1] = cAlive;
    area[i - 1][j + 1] = cAlive;
    area[i + 1][j - 1] = cAlive;
    area[i + 1][j + 1] = cAlive;
}

TwoBraneWorld step(TwoBraneWorld& world)
{
    TwoBraneWorld updatedWorld = createWorld(world.areaDimension);
    for (auto i = 1; i < world.areaDimension - 1; ++i)
        for (auto j = 1; j < world.areaDimension - 1; ++j)
        {
            updatedWorld.bottomBrane[i][j] = isAliveUnsafe(world.bottomBrane, i, j) ? cAlive : cDead;
            updatedWorld.topBrane[i][j]    = isAliveUnsafe(world.topBrane, i, j) ? cAlive : cDead;
        }

    for (auto i = 2; i < world.areaDimension - 2; ++i)
        for (auto j = 2; j < world.areaDimension - 2; ++j)
        {
            bool generator = isResourceGeneratorUnsafe(updatedWorld.bottomBrane, i, j);

            if (generator)
            {
                createResourceUnsafe(updatedWorld.topBrane, i, j);
            }
        }

    return updatedWorld;
}

} // namepspace membrane

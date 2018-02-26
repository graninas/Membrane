#include "logic.h"

namespace membrane
{

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
      area[i][j] = cAlive;
}

void applyBranesLogic(const TwoBraneWorld& world1, TwoBraneWorld& world2, SchemeManager &bottomManager, SchemeManager &topManager)
{
    I wLimitations = std::max(bottomManager.getWLimitations(), topManager.getWLimitations());
    I hLimitations = std::max(bottomManager.getHLimitations(), topManager.getHLimitations());

    for (I i = 0; i < world1.areaDimension - wLimitations; ++i)
        for (I j = 0; j < world1.areaDimension - hLimitations; ++j)
        {
            auto bottomMatched = bottomManager.match(world1.bottomBrane, i, j);
            auto topMatched    = topManager   .match(world1.topBrane,    i, j);
        }
}

TwoBraneWorld step(const TwoBraneWorld& world, SchemeManager &bottomManager, SchemeManager &topManager)
{
    TwoBraneWorld world1 = createWorld(world.areaDimension);

    for (I i = 1; i < world.areaDimension - 1; ++i)
        for (I j = 1; j < world.areaDimension - 1; ++j)
        {
            world1.bottomBrane[i][j] = isAliveUnsafe(world.bottomBrane, i, j) ? cAlive : cDead;
            world1.topBrane   [i][j] = isAliveUnsafe(world.topBrane,    i, j) ? cAlive : cDead;
        }

    TwoBraneWorld world2 = world1;
    applyBranesLogic(world1, world2, bottomManager, topManager);
    return world2;
}

} // namespace membrane

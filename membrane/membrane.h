#ifndef MEMBRANE_H
#define MEMBRANE_H

#include <vector>
#include <stdexcept>
#include <random>
#include <functional>

namespace membrane
{

using Row = std::vector<unsigned char>;
using Area = std::vector<Row>;

using I = std::size_t;
using State = unsigned char;

const State cDead = 0;
const State cAlive = 1;

const bool cTopBrane = true;
const bool cBottomBrane = false;

struct TwoBraneWorld
{
    I areaDimension;
    Area topBrane;
    Area bottomBrane;
};

Area createArea(I w, I h, bool filled);
TwoBraneWorld createWorld(I areaDimension);
TwoBraneWorld createRandomWorld(I areaDimension, I l, I r, I t, I b);
void fillRandomUnsafe(Area &brane, I l, I r, I t, I b, int oneOfN);
void fill2SideBlocks(Area &brane, I gridSize);

void setCell(TwoBraneWorld& world, I i, I j, bool topBrane, State state);

int neighboursUnsafe(const Area& area, I i, I j);
bool isAliveUnsafe(const Area& area, I i, I j);

} // namespace membrane

#endif // MEMBRANE_H

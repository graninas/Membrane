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

TwoBraneWorld createWorld(I areaDimension);
TwoBraneWorld createRandomWorld(I areaDimension, I l, I r, I t, I b);

void setCell(TwoBraneWorld& world, I i, I j, bool topBrane, State state);

TwoBraneWorld step(TwoBraneWorld& world);


} // namespace membrane

#endif // MEMBRANE_H

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

const I cDead = 0;
const I cAlive = 1;

const bool cTopBrane = true;
const bool cBottomBrane = false;

struct TwoBraneWorld
{
    I areaDimension;
    Area topBrane;
    Area bottomBrane;
};

TwoBraneWorld createWorld(I dim);
TwoBraneWorld createRandomWorld(I dim, I l, I r, I t, I b);

void setCell(TwoBraneWorld& world, I i, I j, bool topBrane, I state);


} // namespace membrane

#endif // MEMBRANE_H

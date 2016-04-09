#pragma once

#include "../IMouseAlgorithm.h"
#include "Byte.h"
#include "Direction.h"
#include "Heap.h"
#include "Maze.h"

namespace mackAlgoTwo {

class MackAlgoTwo : public IMouseAlgorithm {

public:
    std::string initialDirection() const;
    int tileTextNumberOfRows() const;
    int tileTextNumberOfCols() const;
    bool useTileEdgeMovements() const;
    void solve(
        int mazeWidth, int mazeHeight, bool isOfficialMaze,
        char initialDirection, sim::MouseInterface* mouse);

private:
    sim::MouseInterface* m_mouse;
    byte m_x;
    byte m_y;
    byte m_d;
    bool m_onWayToCenter;

    float getTurnCost();
    float getStraightAwayCost(byte length);

    bool inCenter();

    bool move();
    void checkNeighbor(byte cell, byte direction);

    void resetDestinationCellDistances();
    byte getClosestDestinationCell();

    bool hasNeighboringCell(byte cell, byte direction);
    byte getNeighboringCell(byte cell, byte direction);

    bool isOneCellAway(byte target);
    void moveOneCell(byte target);

    void readWalls();
    bool readWall(byte direction);

    void turnLeftUpdateState();
    void turnRightUpdateState();
    void turnAroundUpdateState();
    void moveForwardUpdateState();

    void turnLeft();
    void turnRight();
    void turnAround();

    void moveForward();
    void leftAndForward();
    void rightAndForward();
    void aroundAndForward();

    void colorCenter(char color);
    void colorCell(byte cell, char color);

    void setCellDistance(byte mazeIndex, float distance);
    void setCellWall(byte cell, byte direction, bool isWall);
};

} // namespace mackAlgoTwo

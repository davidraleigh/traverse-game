#include "Traverse.h"
#include <cstdlib>

Traverse::Traverse(int boardSize) :
    m_boardSize(boardSize) ,
    m_boardState(boardSize, std::vector<PositionType>(boardSize))
{
}

Traverse::PositionType Traverse::GetPosition(int x, int y)
{
    return m_boardState[x][y];
}

std::string Traverse::GetPrintableRow(int x)
{
    
}

bool Traverse::MoveSequenceTest(std::vector<position_t> moves)
{
    for (int i = 0; i < moves.size() - 1; i++) {
        if (!_MoveTest(moves[i], moves[i + 1]))
            return false;
    }
    
    return true;
}

bool Traverse::_MoveTest(Traverse::position_t fromPos, Traverse::position_t toPos)
{
    // check that the positions are in bounds
    if (!_OnBoard(fromPos) || !_OnBoard(toPos))
        return false;
    
    // check that the position isn't restricted
    
    // check that the positions aren't inline
    if (fromPos.x == toPos.x || fromPos.y == toPos.y)
        return false;
    
    int xDiff = std::abs(fromPos.x - toPos.x);
    int yDiff = std::abs(fromPos.y - toPos.y);
    // check valid knight movement
    if (xDiff + yDiff != 3)
        return false;
    
    return true;
}

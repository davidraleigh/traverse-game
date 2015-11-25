#include "Traverse.h"

Traverse::Traverse(int boardSize) :
    m_boardState(boardSize, std::vector<PositionType>(boardSize))
{
}

Traverse::PositionType Traverse::GetPosition(int x, int y)
{
    return m_boardState[x][y];
}

bool Traverse::MoveSequenceTest(std::vector<move_t> moves)
{
    return true;
}

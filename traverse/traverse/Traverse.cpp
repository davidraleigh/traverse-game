#include "Traverse.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

Traverse::Traverse(int boardSize) :
    m_boardSize(boardSize) ,
    m_boardState(boardSize, std::vector<PositionType>(boardSize)),
    m_currentPosition(position_t()) // start at -1 -1
{
}

Traverse::PositionType Traverse::GetPosition(int x, int y)
{
    return m_boardState[x][y];
}

std::string Traverse::GetPrintableRow(int x)
{
    std::stringstream ss;
    for (int i = 0; i < m_boardSize; i++) {
        PositionType positionType = m_boardState[x][i];
        switch (positionType) {
            case Barrier:
                ss << "B";
                break;
            case Knight:
                ss << "K";
                break;
            case Lava:
                ss << "L";
                break;
            case Open:
                ss << ". ";
                break;
            case Rock:
                ss << "R";
                break;
            case Teleport:
                ss << "T";
                break;
            case Water:
                ss << "W";
                break;
            default:
                break;
        }
    }
    
    return ss.str();
}

void Traverse::PrintBoard()
{
    for (int i = 0; i < m_boardSize; i++)
    {
        std::cout << GetPrintableRow(i) << std::endl;
    }
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

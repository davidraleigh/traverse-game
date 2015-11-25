#include "Traverse.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <regex>
#include <cmath>


Traverse::Traverse(int boardSize) :
    m_boardSize(boardSize) ,
    m_boardState(boardSize, std::vector<positionInfo_t>(boardSize)),
    m_currentPosition(position_t()) // start at -1 -1
{
}

Traverse::Traverse(std::string boardLayout) :
    m_boardState(0, std::vector<positionInfo_t>(0))
{
    std::regex re("[/.RrBbLlWwTtOoKk]+");
    std::stringstream ss;
    
    // read all characters and check for board piece characters
    try {
        std::sregex_iterator next(boardLayout.begin(), boardLayout.end(), re);
        std::sregex_iterator end;
        while (next != end) {
            std::smatch match = *next;
            ss << match.str();
            next++;
        }
    } catch (std::regex_error& e) {
        // Syntax error in the regular expression
    }

    std::string s = ss.str();
    
    // get the length of the string. if it's not a square than reject
    m_boardSize = (int)::floor(::sqrt((double)s.size()));
    size_t squareTest = ::pow(m_boardSize, 2);
    if (s.size() != squareTest)
        throw std::invalid_argument( "received input that wasn't a square" );
    

    int x = 0;
    int y = 0;
    std::vector<positionInfo_t> row;
    for(char& c : s) {
        if (c == 'K' || c == 'k')
        {
            if (m_currentPosition.x != -1) {
                throw std::invalid_argument("Can't have multiple K's on input string");
            }
            m_currentPosition = position_t(x, y);
            row.push_back(positionInfo_t(Open, true));
        } else if (c == 'l' || c == 'L') {
            row.push_back(positionInfo_t(Lava));
        } else if (c == 'r' || c == 'R') {
            row.push_back(positionInfo_t(Rock));
        } else if (c == 'b' || c == 'B') {
            row.push_back(positionInfo_t(Barrier));
        } else if (c == 'w' || c == 'W') {
            row.push_back(positionInfo_t(Water));
        } else if (c == 't' || c == 'T') {
            row.push_back(positionInfo_t(Teleport));
        } else { // if o O or .
            row.push_back(positionInfo_t(Open));
        }
        
        y++;
        if (y == m_boardSize) {
            m_boardState.push_back(row);
            row.clear();
            x++;
            y = 0;
        }
    }
}

Traverse::positionInfo_t Traverse::GetPosition(int x, int y)
{
    return m_boardState[x][y];
}

std::string Traverse::GetPrintableRow(int x)
{
    std::stringstream ss;
    for (int i = 0; i < m_boardSize; i++) {
        if (x == m_currentPosition.x && i == m_currentPosition.y) {
            ss << "K ";
            continue;
        }
        
        PositionType positionType = m_boardState[x][i].type;
        switch (positionType) {
            case Barrier:
                ss << "B ";
                break;
            case Lava:
                ss << "L ";
                break;
            case Open:
                ss << ". ";
                break;
            case Rock:
                ss << "R ";
                break;
            case Teleport:
                ss << "T ";
                break;
            case Water:
                ss << "W ";
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

bool Traverse::MoveTo(Traverse::position_t position)
{
    if (m_currentPosition.x == -1 || _MoveTest(m_currentPosition, position)) {
        m_currentPosition = position;
        return true;
    }
    return false;
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
    
    // check that the position isn't a rock
    
    
    // check that a position isn't blocked
    
    
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

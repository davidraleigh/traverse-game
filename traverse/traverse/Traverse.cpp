#include "Traverse.h"

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <regex>
#include <cmath>
#include <map>
#include <algorithm>

#define MOVE_COST 3
#define LAVA_COST 5
#define WATER_COST 2
Traverse::Traverse(int boardSize) :
    m_boardSize(boardSize) ,
    m_boardState(boardSize, std::vector<std::shared_ptr<Node>>(boardSize))
{
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize; y++) {
            m_boardState[x][y] = std::make_shared<Node>();
        }
    }
}

Traverse::Traverse(std::string boardLayout) :
    m_boardState(0, std::vector<std::shared_ptr<Node>>(0))
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
    std::vector<std::shared_ptr<Node>> row;
    for(char& c : s) {
        if (c == 'K' || c == 'k')
        {
            if (m_currentPosition.x != -1) {
                throw std::invalid_argument("Can't have multiple K's on input string");
            }
            
            m_currentPosition = position_t(x, y);
            row.push_back(std::make_shared<Node>(x, y, Open));
        } else if (c == 'l' || c == 'L') {
            row.push_back(std::make_shared<Node>(x, y, Lava));
        } else if (c == 'r' || c == 'R') {
            row.push_back(std::make_shared<Node>(x, y, Rock));
        } else if (c == 'b' || c == 'B') {
            row.push_back(std::make_shared<Node>(x, y, Barrier));
        } else if (c == 'w' || c == 'W') {
            row.push_back(std::make_shared<Node>(x, y, Water));
        } else if (c == 't' || c == 'T') {
            row.push_back(std::make_shared<Node>(x, y, Teleport));
        } else { // if o O or .
            row.push_back(std::make_shared<Node>(x, y, Open));
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

std::shared_ptr<Traverse::Node> Traverse::GetNode(int x, int y)
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
        
        switch (m_boardState[x][i]->GetType()) {
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

bool Traverse::HasBarrier(Traverse::position_t fromPos, Traverse::position_t toPos)
{
    Traverse::position_t centerFrom(toPos.x, toPos.y);
    Traverse::position_t centerTo(fromPos.x, fromPos.y);
    
    if (::abs(fromPos.x - toPos.x) == 2) {
        double xMiddle = fromPos.x - toPos.x > 1 ? fromPos.x - 1 : toPos.x - 1;
        centerFrom.x = xMiddle;
        centerTo.x = xMiddle;
    } else {
        double yMiddle = fromPos.y - toPos.y > 1 ? fromPos.y - 1 : toPos.y - 1;
        centerTo.y = yMiddle;
        centerFrom.y = yMiddle;
    }

    if (m_boardState[fromPos.x][centerFrom.y]->GetType() == Barrier && m_boardState[centerFrom.x][fromPos.y]->GetType() == Barrier)
        return true;
    else if (m_boardState[centerFrom.x][centerFrom.y]->GetType() == Barrier && m_boardState[centerTo.x][centerTo.y]->GetType() == Barrier)
        return true;
    else if (m_boardState[toPos.x][centerTo.y]->GetType() == Barrier && m_boardState[centerTo.x][toPos.y]->GetType() == Barrier)
        return true;
    
    return false;
}

std::vector<Traverse::position_t> Traverse::_NodesToPath(std::shared_ptr<Traverse::Node> fromNode, std::shared_ptr<Traverse::Node> toNode)
{
    std::vector<Traverse::position_t> path;
    std::shared_ptr<Traverse::Node> currentNode = toNode;
    while (currentNode->GetParent())
    {
        path.push_back(currentNode->GetPosition());
        currentNode = currentNode->GetParent();
    }
    path.push_back(currentNode->GetPosition());
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Traverse::position_t> Traverse::CreatePath(Traverse::position_t fromPos, Traverse::position_t toPos)
{
    // clean up data structures
    m_openNodes.clear();
    m_closedNodes.clear();

    // update the H values for the to Position
    _PopulateHValues(toPos);
    
    // grab our starting node
    std::shared_ptr<Traverse::Node> initialNode = m_boardState[fromPos.x][fromPos.y];
    // as the starting point it's g cost is 0
    initialNode->SetGCost(0);
    
    // place in the vector and make a heap structure
    m_openNodes.push_back(initialNode);
    std::make_heap(m_openNodes.begin(), m_openNodes.end());

    // while there are open nodes
    while (m_openNodes.size() > 0)
    {
        std::shared_ptr<Traverse::Node> currentNode = m_openNodes.front();
        std::pop_heap(m_openNodes.begin(), m_openNodes.end());
        m_openNodes.pop_back();

        m_closedNodes[currentNode->GetPosition()] = currentNode;
        
        if (currentNode->GetPosition().x == toPos.x && currentNode->GetPosition().y == toPos.y)
        {
            return _NodesToPath(initialNode, currentNode);
        }
        
        _PushNeighborsToOpen(currentNode);
    }
    
    // failed to find a path. return an empty path
    std::vector<Traverse::position_t> empty;
    return empty;
}

void Traverse::_PushNeighborsToOpen(std::shared_ptr<Node> fromNode)
{
    int xOffsets[] = {-2,-1,1,2,2,1,-1,-2};
    int yOffsets[] = {1,2,2,1,-1,-2,-2,-1};
    int xFrom = fromNode->GetPosition().x;
    int yFrom = fromNode->GetPosition().y;
    for (int i = 0; i < 8; i++) {
        int x = xOffsets[i] + xFrom;
        int y = yOffsets[i] + yFrom;
        // create position from coordinates
        Traverse::position_t neighborPos(x, y);
        
        // if the move isn't viable                     or if the move is already in the closed set
        if (!_MoveTest(fromNode->GetPosition(), neighborPos) ||
            m_closedNodes.count(neighborPos) > 0)
            continue;
        
        std::shared_ptr<Node> neighborNode = m_boardState[x][y];
        int newGCost = fromNode->GetGCost() + MOVE_COST;
        if (neighborNode->GetType() == Lava)
            newGCost = fromNode->GetGCost() + MOVE_COST * LAVA_COST;
        else if (neighborNode->GetType() == Water)
            newGCost = fromNode->GetGCost() + MOVE_COST * WATER_COST;
        
        
        bool bContainsNeighbor = std::find(m_openNodes.begin(), m_openNodes.end(), neighborNode) != m_openNodes.end();
        if (newGCost < neighborNode->GetGCost() || // if newGCost is less than previous
            !bContainsNeighbor) // or if neighborNode isn't in the openNodes set
        {
            neighborNode->SetGCost(newGCost);
            neighborNode->SetParent(fromNode);
            
            if (!bContainsNeighbor)
            {
                m_openNodes.push_back(neighborNode);
                std::push_heap(m_openNodes.begin(), m_openNodes.end());
            }
        }
    }
}

void Traverse::_PopulateHValues(Traverse::position_t toPos)
{
    for (int x = 0; x < m_boardSize; x++) {
        for (int y = 0; y < m_boardSize; y++) {
            int hVal = ::abs(toPos.x - x);
            hVal += ::abs(toPos.y - y);
            m_boardState[x][y]->SetHCost(hVal);
        }
    }
}

bool Traverse::_MoveTest(Traverse::position_t fromPos, Traverse::position_t toPos)
{
    // check that the positions are in bounds
    if (!_OnBoard(fromPos) || !_OnBoard(toPos))
        return false;
    
    // check that the positions aren't inline
    if (fromPos.x == toPos.x || fromPos.y == toPos.y)
        return false;
    
    int xDiff = std::abs(fromPos.x - toPos.x);
    int yDiff = std::abs(fromPos.y - toPos.y);
    // check valid knight movement
    if (xDiff + yDiff != 3)
        return false;
    
    Traverse::PositionType toType = m_boardState[toPos.x][toPos.y]->GetType();
    // check that the position isn't a rock
    if (toType == Rock || toType == Barrier)
        return false;
    
    // check that the path isn't blocked
    if (HasBarrier(fromPos, toPos))
        return false;
    
    return true;
}

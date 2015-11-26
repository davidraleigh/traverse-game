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
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            m_boardState[i][j] = std::make_shared<Node>();
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
    

    int i = 0;
    int j = 0;
    std::vector<std::shared_ptr<Node>> row;
    for(char& c : s) {
        if (c == 'K' || c == 'k')
        {
            if (m_currentPosition.i != -1) {
                throw std::invalid_argument("Can't have multiple K's on input string");
            }
            
            m_currentPosition = position_t(i, j);
            row.push_back(std::make_shared<Node>(i, j, Open));
        } else if (c == 'l' || c == 'L') {
            row.push_back(std::make_shared<Node>(i, j, Lava));
        } else if (c == 'r' || c == 'R') {
            row.push_back(std::make_shared<Node>(i, j, Rock));
        } else if (c == 'b' || c == 'B') {
            row.push_back(std::make_shared<Node>(i, j, Barrier));
        } else if (c == 'w' || c == 'W') {
            row.push_back(std::make_shared<Node>(i, j, Water));
        } else if (c == 't' || c == 'T') {
            row.push_back(std::make_shared<Node>(i, j, Teleport));
        } else { // if o O or .
            row.push_back(std::make_shared<Node>(i, j, Open));
        }
        
        j++;
        if (j == m_boardSize) {
            m_boardState.push_back(row);
            row.clear();
            i++;
            j = 0;
        }
    }
}

std::shared_ptr<Traverse::Node> Traverse::GetNode(int i, int j)
{
    return m_boardState[i][j];
}

std::string Traverse::GetPrintableRow(int i)
{
    std::stringstream ss;
    for (int j = 0; j < m_boardSize; j++) {
        if (i == m_currentPosition.i && j == m_currentPosition.j) {
            ss << "K ";
            continue;
        }
        
        switch (m_boardState[i][j]->GetType()) {
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
    if (m_currentPosition.i == -1 || _MoveTest(m_currentPosition, position)) {
        m_currentPosition = position;
        return true;
    }
    return false;
}

bool Traverse::MoveSequenceTest(std::vector<position_t> moves)
{
    for (int idx = 0; idx < moves.size() - 1; idx++) {
        if (!_MoveTest(moves[idx], moves[idx + 1]))
            return false;
    }
    
    return true;
}

bool Traverse::HasBarrier(Traverse::position_t fromPos, Traverse::position_t toPos)
{
    Traverse::position_t centerFrom(toPos.i, toPos.j);
    Traverse::position_t centerTo(fromPos.i, fromPos.j);
    
    if (::abs(fromPos.i - toPos.i) == 2) {
        double iMiddle = fromPos.i - toPos.i > 1 ? fromPos.i - 1 : toPos.i - 1;
        centerFrom.i = iMiddle;
        centerTo.i = iMiddle;
    } else {
        double jMiddle = fromPos.j - toPos.j > 1 ? fromPos.j - 1 : toPos.j - 1;
        centerTo.j = jMiddle;
        centerFrom.j = jMiddle;
    }

    if (m_boardState[fromPos.i][centerFrom.j]->GetType() == Barrier && m_boardState[centerFrom.i][fromPos.j]->GetType() == Barrier)
        return true;
    else if (m_boardState[centerFrom.i][centerFrom.j]->GetType() == Barrier && m_boardState[centerTo.i][centerTo.j]->GetType() == Barrier)
        return true;
    else if (m_boardState[toPos.i][centerTo.j]->GetType() == Barrier && m_boardState[centerTo.i][toPos.j]->GetType() == Barrier)
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


//struct greaterComp{
//    bool operator()(const Traverse::Node& a, const Traverse::Node& b) const{
//        return a>b;
//    }
//};

//struct comparator{
//    bool operator()(const long& a,const long& b) const{
//        return a>b;
//    }
//};

struct greater1{
    bool operator()(const std::shared_ptr<Traverse::Node> a, const std::shared_ptr<Traverse::Node> b)
    {
        return (a->GetFCost() > b->GetFCost());
    }
};


std::vector<Traverse::position_t> Traverse::CreatePath(Traverse::position_t fromPos, Traverse::position_t toPos)
{
    // clean up data structures
    m_openNodes.clear();
    m_closedNodes.clear();

    // update the H values for the to Position
    _PopulateHValues(toPos);
    
    // grab our starting node
    std::shared_ptr<Traverse::Node> initialNode = m_boardState[fromPos.i][fromPos.j];
    // as the starting point it's g cost is 0
    initialNode->SetGCost(0);
    
    // place in the vector and make a heap structure
    m_openNodes.push_back(initialNode);
    std::make_heap(m_openNodes.begin(), m_openNodes.end(), greater1());

    // while there are open nodes
    while (m_openNodes.size() > 0)
    {
        std::pop_heap(m_openNodes.begin(), m_openNodes.end(), greater1());
        std::shared_ptr<Traverse::Node> currentNode = m_openNodes.back();
        m_openNodes.pop_back();
        
        m_closedNodes[currentNode->GetPosition()] = currentNode;
        
        if (currentNode->GetPosition().i == toPos.i && currentNode->GetPosition().j == toPos.j)
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
    int iOffsets[] = {-2,-1,1,2,2,1,-1,-2};
    int jOffsets[] = {1,2,2,1,-1,-2,-2,-1};
    int iFrom = fromNode->GetPosition().i;
    int jFrom = fromNode->GetPosition().j;
    for (int idx = 0; idx < 8; idx++) {
        int i = iOffsets[idx] + iFrom;
        int j = jOffsets[idx] + jFrom;
        // create position from coordinates
        Traverse::position_t neighborPos(i, j);
        
        // if the move isn't viable                     or if the move is already in the closed set
        if (!_MoveTest(fromNode->GetPosition(), neighborPos) ||
            m_closedNodes.count(neighborPos) > 0)
            continue;
        
        std::shared_ptr<Node> neighborNode = m_boardState[i][j];
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
                std::push_heap(m_openNodes.begin(), m_openNodes.end(), greater1());
            } else
            {
                int wierd = 0;
            }
        }
    }
}

void Traverse::_PopulateHValues(Traverse::position_t toPos)
{
    for (int i = 0; i < m_boardSize; i++) {
        for (int j = 0; j < m_boardSize; j++) {
            int hVal = ::abs(toPos.i - i);
            hVal += ::abs(toPos.j - j);
            m_boardState[i][j]->SetHCost(hVal);
        }
    }
}

bool Traverse::_MoveTest(Traverse::position_t fromPos, Traverse::position_t toPos)
{
    // check that the positions are in bounds
    if (!_OnBoard(fromPos) || !_OnBoard(toPos))
        return false;
    
    // check that the positions aren't inline
    if (fromPos.i == toPos.i || fromPos.j == toPos.j)
        return false;
    
    int iDiff = std::abs(fromPos.i - toPos.i);
    int jDiff = std::abs(fromPos.j - toPos.j);
    // check valid knight movement
    if (iDiff + jDiff != 3)
        return false;
    
    Traverse::PositionType toType = m_boardState[toPos.i][toPos.j]->GetType();
    // check that the position isn't a rock
    if (toType == Rock || toType == Barrier)
        return false;
    
    // check that the path isn't blocked
    if (HasBarrier(fromPos, toPos))
        return false;
    
    return true;
}

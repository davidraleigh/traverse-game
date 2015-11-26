/*
 *  traverse.h
 *  traverse
 *
 *  Created by David Raleigh on 11/25/15.
 *  Copyright (c) 2015 David Raleigh. All rights reserved.
 *
 */

#ifndef traverse_
#define traverse_

/* The classes below are exported */
#pragma GCC visibility push(default)
#include <vector>
#include <string>
#include <set>
#include <map>
#define REGEX "[/.RrBbLlWwTtOoKk]+"


class Traverse
{
public:
    
    enum PositionType
    {
        Rock  = 16,
        Barrier = 8,
        Lava  = 4,
        Water = 2,
        Teleport = 1,
        Open = 0
    };
    
    struct position_t
    {
        position_t() {
            x = -1;
            y = -1;
        }
        position_t(int xIn, int yIn) {
            x = xIn;
            y = yIn;
        }
        int x;
        int y;
        
        bool operator < (const position_t& pos) const {
            return x < pos.x || (x == pos.x && y < pos.y);
        }
        bool operator == (const position_t& pos) const {
            return x == pos.x && y == pos.y;
        }
    };
    
    class Node
    {
    private:
        std::shared_ptr<Node> m_parentNode;
        int m_hCost;
        int m_gCost;
        int m_fCost;
        PositionType m_positionType;
        position_t m_position;
    public:
        Node() {
            m_positionType = Open;
            m_gCost = INT32_MAX;
            m_parentNode = nullptr;
        }
        Node(int x, int y, PositionType type) :
            m_position(x, y)
        {
            m_positionType = type;
            m_gCost = INT32_MAX;
            m_parentNode = NULL;
        }
        void SetGCost(int gCost) { m_gCost = gCost; m_fCost = m_gCost + m_hCost; }
        void SetHCost(int hCost) { m_hCost = hCost; m_fCost = m_gCost + m_hCost; }
        void SetParent(std::shared_ptr<Node> parentNode) { m_parentNode = parentNode; }
        PositionType GetType() {return m_positionType; }
        inline int GetGCost() { return m_gCost;}
        inline int GetFCost() { return m_hCost + m_gCost; }
        inline position_t GetPosition() { return m_position; }
        inline std::shared_ptr<Node> GetParent() { return m_parentNode; }
        bool operator < (const Node& other) const
        {
            return (m_fCost < other.m_fCost) || (m_fCost == other.m_fCost && m_hCost < other.m_hCost);
//            if (m_fCost < other.m_fCost)
//                return true;
//            else if (m_fCost > other.m_fCost)
//                return false;
//            else if (m_hCost < other.m_hCost)
//                return true;
//            return false;
        }
    };
    
    Traverse(int boardSize);
    Traverse(std::string boardLayout);
    
    std::shared_ptr<Traverse::Node> GetNode(int x, int y);
    
    // Write a function that accepts a sequence of moves and reports
    // whether the sequence contains only valid knight moves.
    bool MoveSequenceTest(std::vector<position_t> moves);
    
    // It should also
    // optionally print the state of the knight board to the terminal as shown
    // above after each move.  The current position should be marked with a 'K'.
    void PrintBoard();
    std::string GetPrintableRow(int x);
    
    bool MoveTo(position_t node);

    // Compute a valid sequence of moves from a given start point to a
    // given end point in the fewest number of moves.
    std::vector<position_t> CreatePath(position_t fromPos, position_t toPos);

    bool HasBarrier(position_t fromPos, position_t toPos);
private:
    int m_boardSize;
    std::vector<std::vector<std::shared_ptr<Node>>> m_boardState;
    position_t m_currentPosition;
    std::vector<std::shared_ptr<Node>> m_openNodes;
    std::map<position_t, std::shared_ptr<Node>> m_closedNodes;
    
    void _PopulateHValues(position_t toPos);
    
    void _PushNeighborsToOpen(std::shared_ptr<Node> fromNode);
    
    std::vector<Traverse::position_t> _NodesToPath(std::shared_ptr<Traverse::Node> fromNode, std::shared_ptr<Traverse::Node> toNode);
    
    bool _MoveTest(position_t fromPos, position_t toPos);

    inline bool _OnBoard(position_t position) {
        if (position.x < m_boardSize && position.x >= 0 && position.y < m_boardSize && position.y >= 0 )
            return true;
        return false;
    };

    
//    Now repeat the Level 3 task for this 32x32 board.  Also, modify
//        your validator from Level 1 to check your solutions.  This board has the
//        following additional rules

//    1) W[ater] squares count as two moves when a piece lands there
//    2) R[ock] squares cannot be used
//    3) B[arrier] squares cannot be used AND cannot lie in the path
//    4) T[eleport] squares instantly move you from one T to the other in
//    the same move
//    5) L[ava] squares count as five moves when a piece lands there
    
};

#pragma GCC visibility pop
#endif

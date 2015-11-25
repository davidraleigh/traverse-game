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
    
    struct positionInfo_t {
        positionInfo_t() {
            visited = false;
            type = Open;
        }
        positionInfo_t(PositionType positionType) {
            visited = false;
            type = positionType;
        }
        positionInfo_t(PositionType positionType, bool visit) {
            visited = visit;
            type = positionType;
        }
        bool visited;
        PositionType type;
    };
    
    struct position_t {
        position_t()
        {
            x = -1;
            y = -1;
        }
        position_t(int pos_x, int pos_y)
        {
            x = pos_x;
            y = pos_y;
        }
        
        int x;
        int y;
    };
    
    struct node_t {
        node_t() {
            gCost = INT32_MAX;
        }
        node_t(position_t position, int hCost) {
            position = position;
            hCost = hCost;
            gCost = INT32_MAX;
        }
        
        position_t position;
        int hCost;
        int gCost;
        int fCost;
        position_t parentPosition;
    };
    
    struct cmpNodeByHCost {
        bool operator()(const node_t& a, const node_t& b) const {
            return a.fCost < b.fCost;
        }
    };
    
    Traverse(int boardSize);
    Traverse(std::string boardLayout);
    
    positionInfo_t GetPosition(int x, int y);
    
    // Write a function that accepts a sequence of moves and reports
    // whether the sequence contains only valid knight moves.
    bool MoveSequenceTest(std::vector<position_t> moves);
    
    // It should also
    // optionally print the state of the knight board to the terminal as shown
    // above after each move.  The current position should be marked with a 'K'.
    void PrintBoard();
    std::string GetPrintableRow(int x);
    
    bool MoveTo(position_t position);

    // Compute a valid sequence of moves from a given start point to a
    // given end point in the fewest number of moves.
    std::vector<position_t> CreatePath(position_t fromPos, position_t toPos);

    bool HasBarrier(position_t fromPos, position_t toPos);
private:
    int m_boardSize;
    std::vector<std::vector<positionInfo_t>> m_boardState;
    position_t m_currentPosition;
    std::map<position_t, node_t> m_nodeSpace;
    std::set<node_t, cmpNodeByHCost> m_openNodes;
    std::set<node_t, cmpNodeByHCost> m_closedNodes;
    
    
    void _PopulateNodeSpace(Traverse::position_t toPos);
    
    void _GetClosestNodes(Traverse::node_t fromPos);
    
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

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
            i = -1;
            j = -1;
        }
        position_t(int iIn, int jIn) {
            i = iIn;
            j = jIn;
        }
        int i;
        int j;
        
        bool operator < (const position_t& pos) const {
            return i < pos.i || (i == pos.i && j < pos.j);
        }
        bool operator == (const position_t& pos) const {
            return i == pos.i && j == pos.j;
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
        Node(int i, int j, PositionType type) :
            m_position(i, j)
        {
            m_positionType = type;
            m_gCost = INT32_MAX;
            m_parentNode = NULL;
        }
        void SetGCost(int gCost)
        {
            m_gCost = gCost;
            m_fCost = m_gCost + m_hCost;
        }
        void SetHCost(int hCost)
        {
            m_hCost = hCost;
            m_fCost = m_gCost + m_hCost;
        }
        void SetParent(std::shared_ptr<Node> parentNode) { m_parentNode = parentNode; }
        PositionType GetType() {return m_positionType; }
        int GetGCost() { return m_gCost;}
        const int GetFCost() const { return m_fCost; }
        position_t GetPosition() { return m_position; }
        std::shared_ptr<Node> GetParent() { return m_parentNode; }
        bool operator < (const Node& other) const
        {
            return (m_fCost < other.m_fCost);
        }
    };
    
    Traverse(int boardSize);
    Traverse(std::string boardLayout);
    
    
    std::shared_ptr<Traverse::Node> GetNode(int i, int j);
    
    // Write a function that accepts a sequence of moves and reports
    // whether the sequence contains only valid knight moves.
    bool MoveSequenceTest(std::vector<position_t> moves);
    
    // It should also
    // optionally print the state of the knight board to the terminal as shown
    // above after each move.  The current position should be marked with a 'K'.
    void PrintBoard();
    std::string GetPrintableRow(int i);
    
    bool MoveTo(position_t node);

    // Compute a valid sequence of moves from a given start point to a
    // given end point in the fewest number of moves.
    std::vector<position_t> CreatePath(position_t fromPos, position_t toPos);

    bool HasBarrier(position_t fromPos, position_t toPos);
private:
    /**** GAME STATE ****/
    // size of square board side
    int m_boardSize;
    // board positions and types of positions
    std::vector<std::vector<std::shared_ptr<Node>>> m_boardState;
    // current player position
    position_t m_currentPosition;
    // only two positions on a board can be teleport positions
    std::map<position_t, std::shared_ptr<Node>> m_teleportPair;
    // test if a move is allowable according to the boardState
    bool _MoveTest(position_t fromPos, position_t toPos);
    
    /**** A-STAR ****/
    // open set and closed set
    std::vector<std::shared_ptr<Node>> m_openSet;
    std::map<position_t, std::shared_ptr<Node>> m_closedSet;
    // best path map for print out. Position key and index value
    std::map<position_t, int> m_bestPathPrint;
    // for a destination 'toPos' change all the boardState nodes h-values
    void _PopulateHValues(position_t toPos);
    // for a given fromNode push the set of all legal moves to the open set
    void _PushNeighborsToOpen(std::shared_ptr<Node> fromNode);
    // from a calculated a-star fromNode and toNode produce position and populate the m_bestPathPrint map
    std::vector<Traverse::position_t> _NodesToPath(std::shared_ptr<Traverse::Node> fromNode, std::shared_ptr<Traverse::Node> toNode);
    // simple test if a position is in bounds of the board
    inline bool _OnBoard(position_t position) {
        if (position.i < m_boardSize && position.i >= 0 && position.j < m_boardSize && position.j >= 0 )
            return true;
        return false;
    };
};

#pragma GCC visibility pop
#endif

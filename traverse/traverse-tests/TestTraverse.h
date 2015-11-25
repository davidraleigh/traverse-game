//
//  TestTraverse.h
//  traverse
//
//  Created by David Raleigh on 11/25/15.
//  Copyright (c) 2015 David Raleigh. All rights reserved.
//

#ifndef traverse_TestTraverse_h
#define traverse_TestTraverse_h

#include <cxxtest/TestSuite.h>
#include "Traverse.h"
class TraverseTestSuite : public CxxTest::TestSuite
{
public:
    void testConstructor( void )
    {
        Traverse t(5);
    }
    
    void testBoardPosition( void )
    {
        Traverse t(5);
        Traverse::PositionType pt = t.GetPosition(0, 0);
        TS_ASSERT_EQUALS(pt, Traverse::PositionType::Open);
    }
    
    void testMoveSequence1( void )
    {
        Traverse t(5);
        std::vector<Traverse::position_t> positions;
        positions.push_back(Traverse::position_t(0,0));
        positions.push_back(Traverse::position_t(1,2));
        positions.push_back(Traverse::position_t(0,4));
        TS_ASSERT(t.MoveSequenceTest(positions));
    }
    
    void testMoveSequence2( void )
    {
        Traverse t(5);
        std::vector<Traverse::position_t> positions;
        positions.push_back(Traverse::position_t(0,0));
        positions.push_back(Traverse::position_t(1,1));
        positions.push_back(Traverse::position_t(0,4));
        TS_ASSERT(!t.MoveSequenceTest(positions));
    }
};

#endif

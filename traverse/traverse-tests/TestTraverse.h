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
        Traverse::PositionType pt = t.GetPosition(0, 0).type;
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
    
    void testMoveSequence3( void )
    {
        Traverse t(5);
        std::vector<Traverse::position_t> positions;
        positions.push_back(Traverse::position_t(0,0));
        positions.push_back(Traverse::position_t(1,2));
        positions.push_back(Traverse::position_t(0,3));
        TS_ASSERT(!t.MoveSequenceTest(positions));
    }
    
    void testRowString1( void )
    {
        Traverse t(5);
        std::string s = t.GetPrintableRow(0);
        TS_ASSERT_EQUALS(s.compare(". . . . . "), 0);
    }
    
    void testRowString2 (void)
    {
        Traverse t(5);
        TS_ASSERT(t.MoveTo(Traverse::position_t(0,0)));
        std::string s = t.GetPrintableRow(0);
        TS_ASSERT_EQUALS(s.compare("K . . . . "), 0);
    }
    
    
    void testMoveTo( void )
    {
        Traverse t(5);
        TS_ASSERT(t.MoveTo(Traverse::position_t(0,0)));
    }
    
    void testMoveTo2( void )
    {
        Traverse t(5);
        TS_ASSERT(t.MoveTo(Traverse::position_t(0,0)));
        TS_ASSERT(!t.MoveTo(Traverse::position_t(1,1)));
        TS_ASSERT(t.MoveTo(Traverse::position_t(1,2)));
        TS_ASSERT(t.MoveTo(Traverse::position_t(0,4)));
    }
    
    void testBoardFromString(void) {
        Traverse t("KoO . . . LL B");
        std::string s1 = t.GetPrintableRow(0);
        TS_ASSERT_EQUALS(s1.compare("K . . "), 0);
        std::string s2 = t.GetPrintableRow(1);
        TS_ASSERT_EQUALS(s2.compare(". . . "), 0);
        std::string s3 = t.GetPrintableRow(2);
        TS_ASSERT_EQUALS(s3.compare("L L B "), 0);
        
    }
    
};

#endif

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
        std::shared_ptr<Traverse::Node> pt = t.GetNode(0, 0);
        TS_ASSERT_EQUALS(pt->GetType(), Traverse::PositionType::Open);
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
    
    void testBoardFromString1(void) {
        Traverse t("KoO . . . LL B");
        std::string s1 = t.GetPrintableRow(0);
        TS_ASSERT_EQUALS(s1.compare("K . . "), 0);
        std::string s2 = t.GetPrintableRow(1);
        TS_ASSERT_EQUALS(s2.compare(". . . "), 0);
        std::string s3 = t.GetPrintableRow(2);
        TS_ASSERT_EQUALS(s3.compare("L L B "), 0);
    }
    
    void testBoardFromString2(void) {
        Traverse t("KoO . ddd.\n . L\nL B");
        std::string s1 = t.GetPrintableRow(0);
        TS_ASSERT_EQUALS(s1.compare("K . . "), 0);
        std::string s2 = t.GetPrintableRow(1);
        TS_ASSERT_EQUALS(s2.compare(". . . "), 0);
        std::string s3 = t.GetPrintableRow(2);
        TS_ASSERT_EQUALS(s3.compare("L L B "), 0);
    }
    
    void testHasBarrier(void) {
        Traverse t("..... .bbb. .b.b. .bbb. .....");
        Traverse::position_t center(2,2);
        for (int i = 1; i < 4; i++) {
            TS_ASSERT(t.HasBarrier(center, Traverse::position_t(i, 0)));
            TS_ASSERT(t.HasBarrier(center, Traverse::position_t(i, 4)));
            TS_ASSERT(t.HasBarrier(center, Traverse::position_t(0, i)));
            TS_ASSERT(t.HasBarrier(center, Traverse::position_t(4, i)));
            TS_ASSERT(t.HasBarrier(Traverse::position_t(i, 0), center));
            TS_ASSERT(t.HasBarrier(Traverse::position_t(i, 4), center));
            TS_ASSERT(t.HasBarrier(Traverse::position_t(0, i), center));
            TS_ASSERT(t.HasBarrier(Traverse::position_t(4, i), center));
        }
    }

    
    void testHasBarrier2(void) {
        Traverse t("..... ..... ..... ..... .....");
        Traverse::position_t center(2,2);
        for (int i = 1; i < 4; i++) {
            TS_ASSERT(!t.HasBarrier(center, Traverse::position_t(i, 0)));
            TS_ASSERT(!t.HasBarrier(center, Traverse::position_t(i, 4)));
            TS_ASSERT(!t.HasBarrier(center, Traverse::position_t(0, i)));
            TS_ASSERT(!t.HasBarrier(center, Traverse::position_t(4, i)));
            TS_ASSERT(!t.HasBarrier(Traverse::position_t(i, 0), center));
            TS_ASSERT(!t.HasBarrier(Traverse::position_t(i, 4), center));
            TS_ASSERT(!t.HasBarrier(Traverse::position_t(0, i), center));
            TS_ASSERT(!t.HasBarrier(Traverse::position_t(4, i), center));
        }
    }
    
    void testAStar1(void) {
        Traverse t("..... .rrr. .r.r. .rrr. .....");
        Traverse::position_t fromPos(0, 1);
        Traverse::position_t toPos(4, 4);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 0);
    }
    
    void testAStar2(void) {
        Traverse t("..... .rrr. .r.r. .rrr. .....");
        Traverse::position_t fromPos(0, 1);
        Traverse::position_t toPos(4, 3);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        Traverse::position_t firstPos = path[0];
        TS_ASSERT_EQUALS(fromPos.i, firstPos.i);
        TS_ASSERT_EQUALS(fromPos.j, firstPos.j);
        TS_ASSERT_EQUALS(toPos.i, path[path.size() - 1].i);
        TS_ASSERT_EQUALS(toPos.j, path[path.size() - 1].j);
        TS_ASSERT_EQUALS(2, path[1].i);
        TS_ASSERT_EQUALS(2, path[1].j);
    }
    
    void testAStar3(void) {
        Traverse t("..... .bbb. .b.b. .bbb. .....");
        Traverse::position_t fromPos(0, 1);
        Traverse::position_t toPos(4, 3);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 0);
    }
    
    void testAStar4(void) {
        Traverse t("..... .bbb. ..... .bbb. .....");
        Traverse::position_t fromPos(1, 0);
        Traverse::position_t toPos(3, 4);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(fromPos.i, path[0].i);
        TS_ASSERT_EQUALS(fromPos.j, path[0].j);
        TS_ASSERT_EQUALS(toPos.i, path[path.size() - 1].i);
        TS_ASSERT_EQUALS(toPos.j, path[path.size() - 1].j);
        TS_ASSERT_EQUALS(2, path[1].i);
        TS_ASSERT_EQUALS(2, path[1].j);
    }
    
    void testAStar5(void) {
        Traverse t("..... .bbb. ..L.. .bbb. .....");
        Traverse::position_t fromPos(1, 0);
        Traverse::position_t toPos(3, 4);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(fromPos.i, path[0].i);
        TS_ASSERT_EQUALS(fromPos.j, path[0].j);
        TS_ASSERT_EQUALS(toPos.i, path[path.size() - 1].i);
        TS_ASSERT_EQUALS(toPos.j, path[path.size() - 1].j);
        TS_ASSERT_EQUALS(2, path[1].i);
        TS_ASSERT_EQUALS(2, path[1].j);
    }
    
    void testAStar6(void) {
        Traverse t("..r.. .b.b. ..L.. ..b.. .....");
        Traverse::position_t fromPos(1, 0);
        Traverse::position_t toPos(1, 4);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 5);
        TS_ASSERT_EQUALS(fromPos.i, path[0].i);
        TS_ASSERT_EQUALS(fromPos.j, path[0].j);
        TS_ASSERT_EQUALS(toPos.i, path[path.size() - 1].i);
        TS_ASSERT_EQUALS(toPos.j, path[path.size() - 1].j);
        TS_ASSERT_EQUALS(3, path[1].i);
        TS_ASSERT_EQUALS(1, path[1].j);
        TS_ASSERT_EQUALS(1, path[2].i);
        TS_ASSERT_EQUALS(2, path[2].j);
        TS_ASSERT_EQUALS(3, path[3].i);
        TS_ASSERT_EQUALS(3, path[3].j);
    }
    
    void testAStar7(void) {
        Traverse t(".b... .b.b. ..L.. ..b.. .....");
        Traverse::position_t fromPos(1, 0);
        Traverse::position_t toPos(1, 4);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 5);
//        TS_ASSERT_EQUALS(fromPos.i, path[0].i);
//        TS_ASSERT_EQUALS(fromPos.j, path[0].j);
//        TS_ASSERT_EQUALS(toPos.i, path[path.size() - 1].i);
//        TS_ASSERT_EQUALS(toPos.j, path[path.size() - 1].j);
//        TS_ASSERT_EQUALS(3, path[1].i);
//        TS_ASSERT_EQUALS(1, path[1].j);
//        TS_ASSERT_EQUALS(1, path[2].i);
//        TS_ASSERT_EQUALS(2, path[2].j);
//        TS_ASSERT_EQUALS(3, path[3].i);
//        TS_ASSERT_EQUALS(3, path[3].j);
    }

    void testAStar8(void) {
        Traverse t(".w. .w. ...");
        Traverse::position_t fromPos(0, 0);
        Traverse::position_t toPos(0, 2);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 3);
        TS_ASSERT_EQUALS(2, path[1].i);
        TS_ASSERT_EQUALS(1, path[1].j);
    }

    void testAStar9(void) {
        Traverse t(".r. .b. .l.");
        Traverse::position_t fromPos(0, 0);
        Traverse::position_t toPos(0, 2);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 3);
        TS_ASSERT_EQUALS(2, path[1].i);
        TS_ASSERT_EQUALS(1, path[1].j);
    }

    void testAStar10(void) {
        Traverse t(".r. .r. .r.");
        Traverse::position_t fromPos(0, 0);
        Traverse::position_t toPos(1, 2);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 2);
    }

    void testAStar11(void) {
        Traverse t(".b. .b. .b.");
        Traverse::position_t fromPos(0, 0);
        Traverse::position_t toPos(1, 2);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 0);
    }
    
    void testAStarTeleport(void) {
        Traverse t("....... ....... .t..t.. ....... ....... ....... .......");
        Traverse::position_t fromPos(0, 0);
        Traverse::position_t toPos(1, 6);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);
        TS_ASSERT_EQUALS(path.size(), 4);
    }
    
    void testLongBoard(void) {
        const char *bigBoard = R"(........B...LLL................. ........B...LLL................. ........B...LLL...LLL........... ........B...LLL..LLL...RR....... ........B...LLLLLLLL...RR....... ........B...LLLLLL.............. ........B............RR......... ........BB...........RR......... ........WBB..................... ...RR...WWBBBBBBBBBB............ ...RR...WW.........B............ ........WW.........B......T..... ...WWWWWWW.........B............ ...WWWWWWW.........B..RR........ ...WW..........BBBBB..RR.WWWWWWW ...WW..........B.........W...... WWWW...........B...WWWWWWW...... ...WWWWWWW.....B............BBBB ...WWWWWWW.....BBB..........B... ...WWWWWWW.......BWWWWWWBBBBB... ...WWWWWWW.......BWWWWWWB....... ...........BBB..........BB...... .....RR....B.............B...... .....RR....B.............B.T.... ...........B.....RR......B...... ...........B.....RR............. ...........B..........RR........ ...........B..........RR........................................................................................................................................)";
        
        Traverse t(bigBoard);
        Traverse::position_t fromPos(0, 0);
        Traverse::position_t toPos(0, 9);
        std::vector<Traverse::position_t> path = t.CreatePath(fromPos, toPos);        
    }
};

#endif

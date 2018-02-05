/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <fstream>
#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/XUnitPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    std::ofstream ofstr("TestResults.xml");
    CxxTest::XUnitPrinter tmp(ofstr);
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main<CxxTest::XUnitPrinter>( tmp, argc, argv );
    return status;
}
bool suite_TraverseTestSuite_init = false;
#include "TestTraverse.h"

static TraverseTestSuite suite_TraverseTestSuite;

static CxxTest::List Tests_TraverseTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TraverseTestSuite( "/Users/davidraleigh/code/traverse-game/traverse/traverse-tests/TestTraverse.h", 14, "TraverseTestSuite", suite_TraverseTestSuite, Tests_TraverseTestSuite );

static class TestDescription_suite_TraverseTestSuite_testConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testConstructor() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 17, "testConstructor" ) {}
 void runTest() { suite_TraverseTestSuite.testConstructor(); }
} testDescription_suite_TraverseTestSuite_testConstructor;

static class TestDescription_suite_TraverseTestSuite_testBoardPosition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testBoardPosition() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 22, "testBoardPosition" ) {}
 void runTest() { suite_TraverseTestSuite.testBoardPosition(); }
} testDescription_suite_TraverseTestSuite_testBoardPosition;

static class TestDescription_suite_TraverseTestSuite_testMoveSequence1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testMoveSequence1() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 29, "testMoveSequence1" ) {}
 void runTest() { suite_TraverseTestSuite.testMoveSequence1(); }
} testDescription_suite_TraverseTestSuite_testMoveSequence1;

static class TestDescription_suite_TraverseTestSuite_testMoveSequence2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testMoveSequence2() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 39, "testMoveSequence2" ) {}
 void runTest() { suite_TraverseTestSuite.testMoveSequence2(); }
} testDescription_suite_TraverseTestSuite_testMoveSequence2;

static class TestDescription_suite_TraverseTestSuite_testMoveSequence3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testMoveSequence3() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 49, "testMoveSequence3" ) {}
 void runTest() { suite_TraverseTestSuite.testMoveSequence3(); }
} testDescription_suite_TraverseTestSuite_testMoveSequence3;

static class TestDescription_suite_TraverseTestSuite_testRowString1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testRowString1() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 59, "testRowString1" ) {}
 void runTest() { suite_TraverseTestSuite.testRowString1(); }
} testDescription_suite_TraverseTestSuite_testRowString1;

static class TestDescription_suite_TraverseTestSuite_testRowString2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testRowString2() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 66, "testRowString2" ) {}
 void runTest() { suite_TraverseTestSuite.testRowString2(); }
} testDescription_suite_TraverseTestSuite_testRowString2;

static class TestDescription_suite_TraverseTestSuite_testMoveTo : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testMoveTo() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 75, "testMoveTo" ) {}
 void runTest() { suite_TraverseTestSuite.testMoveTo(); }
} testDescription_suite_TraverseTestSuite_testMoveTo;

static class TestDescription_suite_TraverseTestSuite_testMoveTo2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testMoveTo2() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 81, "testMoveTo2" ) {}
 void runTest() { suite_TraverseTestSuite.testMoveTo2(); }
} testDescription_suite_TraverseTestSuite_testMoveTo2;

static class TestDescription_suite_TraverseTestSuite_testBoardFromString1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testBoardFromString1() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 90, "testBoardFromString1" ) {}
 void runTest() { suite_TraverseTestSuite.testBoardFromString1(); }
} testDescription_suite_TraverseTestSuite_testBoardFromString1;

static class TestDescription_suite_TraverseTestSuite_testBoardFromString2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testBoardFromString2() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 100, "testBoardFromString2" ) {}
 void runTest() { suite_TraverseTestSuite.testBoardFromString2(); }
} testDescription_suite_TraverseTestSuite_testBoardFromString2;

static class TestDescription_suite_TraverseTestSuite_testHasBarrier : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testHasBarrier() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 110, "testHasBarrier" ) {}
 void runTest() { suite_TraverseTestSuite.testHasBarrier(); }
} testDescription_suite_TraverseTestSuite_testHasBarrier;

static class TestDescription_suite_TraverseTestSuite_testHasBarrier2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testHasBarrier2() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 126, "testHasBarrier2" ) {}
 void runTest() { suite_TraverseTestSuite.testHasBarrier2(); }
} testDescription_suite_TraverseTestSuite_testHasBarrier2;

static class TestDescription_suite_TraverseTestSuite_testAStar1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar1() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 141, "testAStar1" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar1(); }
} testDescription_suite_TraverseTestSuite_testAStar1;

static class TestDescription_suite_TraverseTestSuite_testAStar2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar2() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 149, "testAStar2" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar2(); }
} testDescription_suite_TraverseTestSuite_testAStar2;

static class TestDescription_suite_TraverseTestSuite_testAStar3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar3() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 163, "testAStar3" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar3(); }
} testDescription_suite_TraverseTestSuite_testAStar3;

static class TestDescription_suite_TraverseTestSuite_testAStar4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar4() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 171, "testAStar4" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar4(); }
} testDescription_suite_TraverseTestSuite_testAStar4;

static class TestDescription_suite_TraverseTestSuite_testAStar5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar5() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 184, "testAStar5" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar5(); }
} testDescription_suite_TraverseTestSuite_testAStar5;

static class TestDescription_suite_TraverseTestSuite_testAStar6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar6() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 197, "testAStar6" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar6(); }
} testDescription_suite_TraverseTestSuite_testAStar6;

static class TestDescription_suite_TraverseTestSuite_testAStar7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar7() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 215, "testAStar7" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar7(); }
} testDescription_suite_TraverseTestSuite_testAStar7;

static class TestDescription_suite_TraverseTestSuite_testAStar8 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar8() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 233, "testAStar8" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar8(); }
} testDescription_suite_TraverseTestSuite_testAStar8;

static class TestDescription_suite_TraverseTestSuite_testAStar9 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar9() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 243, "testAStar9" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar9(); }
} testDescription_suite_TraverseTestSuite_testAStar9;

static class TestDescription_suite_TraverseTestSuite_testAStar10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar10() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 253, "testAStar10" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar10(); }
} testDescription_suite_TraverseTestSuite_testAStar10;

static class TestDescription_suite_TraverseTestSuite_testAStar11 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStar11() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 261, "testAStar11" ) {}
 void runTest() { suite_TraverseTestSuite.testAStar11(); }
} testDescription_suite_TraverseTestSuite_testAStar11;

static class TestDescription_suite_TraverseTestSuite_testAStarTeleport : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testAStarTeleport() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 269, "testAStarTeleport" ) {}
 void runTest() { suite_TraverseTestSuite.testAStarTeleport(); }
} testDescription_suite_TraverseTestSuite_testAStarTeleport;

static class TestDescription_suite_TraverseTestSuite_testLongBoard : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TraverseTestSuite_testLongBoard() : CxxTest::RealTestDescription( Tests_TraverseTestSuite, suiteDescription_TraverseTestSuite, 277, "testLongBoard" ) {}
 void runTest() { suite_TraverseTestSuite.testLongBoard(); }
} testDescription_suite_TraverseTestSuite_testLongBoard;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

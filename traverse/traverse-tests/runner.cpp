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
CxxTest::StaticSuiteDescription suiteDescription_TraverseTestSuite( "/Users/davidraleigh/code/davidraleigh/knight-traverse/traverse/traverse-tests/TestTraverse.h", 14, "TraverseTestSuite", suite_TraverseTestSuite, Tests_TraverseTestSuite );

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

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";

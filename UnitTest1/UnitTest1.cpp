#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\user\source\repos\222222222222\222222222222\222222222222.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{ 
	TEST_CLASS(CheckValidNTests)
	{
	public:
		TEST_METHOD(checkValidN_get5_exceptionNotThrown) {
			int n = 5;
			try {
				checkValidN(n);
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail(); 
			}
		}
		TEST_METHOD(checkValidN_get1_exceptionThrown) {
			int n = 1;
			try {
				checkValidN(n);
				Assert::Fail(); 
			}
			catch (runtime_error&) {
				Assert::IsTrue(true); 
			}
			catch (...) {
				Assert::Fail(); 
			}
		}
	};
	TEST_CLASS(CheckRerunTests)
	{
	public:
		TEST_METHOD(checkRerun_gety_exceptionNotThrown) {
			char rerun = 'y';
			try {
				checkRerun(rerun);
				Assert::IsTrue(true); 
			}
			catch (...) {
				Assert::Fail(); 
			}
		}
		TEST_METHOD(checkRerun_getN_exceptionNotThrown) {
			char rerun = 'N';
			try {
				checkRerun(rerun);
				Assert::IsTrue(true); 
			}
			catch (...) {
				Assert::Fail(); 
			}
		}
		TEST_METHOD(checkRerun_getx_exceptionThrown) {
			char rerun = 'x'; 
			try {
				checkRerun(rerun);
				Assert::Fail();
			}
			catch (const runtime_error&) {
				Assert::IsTrue(true); 
			}
			catch (...) {
				Assert::Fail(); 
			}
		}
		TEST_METHOD(checkRerun_get5_exceptionThrown) {
			char rerun = 5;
			try {
				checkRerun(rerun);
				Assert::Fail();
			}
			catch (const runtime_error&) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
		TEST_METHOD(checkRerun_get,_exceptionThrown) {
			char rerun = ',';
			try {
				checkRerun(rerun);
				Assert::Fail();
			}
			catch (const runtime_error&) {
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}
	};
		TEST_CLASS(CheckHTests)
		{
		public:
			TEST_METHOD(checkH_get5point5_exceptionNotThrown) {
				double h = 5.5;
				try {
					checkH(h);
					Assert::IsTrue(true);
				}
				catch (...) {
					Assert::Fail();
				}
			}
			TEST_METHOD(checkH_get0_exceptionThrown) {
				double h = 0.0;
				try {
					checkH(h);
					Assert::Fail();
				}
				catch (const runtime_error&) {
					Assert::IsTrue(true);
				}
				catch (...) {
					Assert::Fail();
				}
			}
			TEST_METHOD(checkH_getminus3point2_exceptionThrown) {
				double h = -3.2;
				try {
					checkH(h);
					Assert::Fail();
				}
				catch (const runtime_error&) {
					Assert::IsTrue(true);
				}
				catch (...) {
					Assert::Fail();
				}
		}
		};
		TEST_CLASS(CheckRangeTests)
		{
		public:
			TEST_METHOD(checkRange_get5and10point5_noExceptionThrown) {
				double a = 5.0, b = 10.5; 
				try {
					double result = checkRange(a, b);
					Assert::IsTrue(true); 
				}
				catch (...) {
					Assert::Fail(); 
				}
			}
			TEST_METHOD(checkRange_get5poin2and5point2_exceptionThrown) {
				double a = 5.2, b = 5.2; 
				try {
					checkRange(a, b);
					Assert::Fail(); 
				}
				catch (const runtime_error&) {
					Assert::IsTrue(true); 
				}
				catch (...) {
					Assert::Fail(); 
				}
			}
			TEST_METHOD(checkRange_get10point7and5_exceptionThrown) {
				double a = 10.7, b = 5.0; 
				try {
					checkRange(a, b);
					Assert::Fail();
				}
				catch (const runtime_error&) {
					Assert::IsTrue(true);
				}
				catch (...) {
					Assert::Fail();
				};
			}
		};
		TEST_CLASS(CheckNoRangeSolve)
		{
		public:
			TEST_METHOD(CheckCalculateNoRange_get3and2_noExceptionThrown) {
				int n = 3;
				double x = 2;
				double expected = 0;
				double actual = calculateNoRange(n, x);
				Assert::AreEqual(expected, actual);
			}
			TEST_METHOD(CheckCalculateNoRange_get3and1point678_ExceptionNotThrown) {
				int n = 3;
				double x = 1.678;
				double expected = -0.707118;
				double actual = calculateNoRange(n, x);
				double delta = 0.000001;
				Assert::IsTrue(abs(expected - actual) < delta);
			}
			TEST_METHOD(CheckCalculateNoRange_get3andminus5_ExceptionNotThrown) {
				int n = 3;
				double x = -5;
				double expected = 4;
				double actual = calculateNoRange(n, x);
				Assert::AreEqual(expected, actual);
			}
		};
}
#include "pch.h"
#include "CppUnitTest.h"

extern "C" int getPerimeter(int* length, int* width);
extern "C" int getArea(int* length, int* width);
extern "C" void setLength(int input, int* length);
extern "C" void setWidth(int input, int* width);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UNITTESTASSIGNMENT2
{
	TEST_CLASS(UNITTESTASSIGNMENT2)
	{
	public:
		
		TEST_METHOD(Test_Perimeter)
		{
			// testing the getPerimeter function with length 2, width 2.
			// since perimeter is 2(length+width) = 8
			int result = 0;
			int length = 2;
			int width = 2;
			// since getPerimeter is defined with integer pointers we need to use pass by reference
			result = getPerimeter(&length, &width);
			Assert::AreEqual(8, result);
		}

		TEST_METHOD(Test_Area)
		{
			// testing the getArea function with length 2, width 2.
			// real area = 2*2 = 4
			int result = 0;
			int length = 2;
			int width = 2;
			// since getArea is defined with integer pointers we need to use pass by reference
			result = getArea(&length, &width);
			Assert::AreEqual(4, result);
		}

		TEST_METHOD(Test_getWidth_1_correct_range)
			// test getwidth 1 that deals with input within range of the funtion
			// this test case will test setWidth function to set width to 2
			// so width should be equal to 2 for the function to pass test corrrectly
		{
			int width = 0;

			// since setWidth is defined with integer pointers we need to use pass by reference

			setWidth(2,&width);

			// test is expected to pass if the code is written correctly.

			Assert::AreEqual(2, width);
		}

		TEST_METHOD(Test_getWidth_2_upper_limit)
			// test getwidth 2 that deals with input which upper limit for the 
			// this test case will test setWidth function to set width to 100
			
		{
			int width = 1;

			// since setWidth is defined with integer pointers we need to use pass by reference

			setWidth(100, &width);

			// test is expected to pass coz input doesnt lie in the range, therefore, it wont change the width to 200

			Assert::AreNotEqual(100, width);
		}

		TEST_METHOD(Test_getWidth_3_lower_limit)
			// test getwidth 1 that deals with input 0 since range is 1 to 99 inclusive
			// this test case will test setWidth function to set width to 0
			// so width should not be equal to 0 for the function to pass test corrrectly
		{
			int width = 1;

			// since setWidth is defined with integer pointers we need to use pass by reference

			setWidth(0, & width);

			// test is expected to pass if the code is written correctly.

			Assert::AreNotEqual(0, width);
		}

		TEST_METHOD(Test_getLength_1_correct_range)
			// test setLength 1 that deals with input within range of the funtion
			// this test case will test setLength function to set Length to 2
			// so Length should be equal to 2 for the function to pass test corrrectly
		{
			int Length = 0;

			// since setLength is defined with integer pointers we need to use pass by reference

			setLength(2, &Length);

			// test is expected to pass if the code is written correctly.

			Assert::AreEqual(2, Length);
		}

		TEST_METHOD(Test_getLength_2_upper_limit)
			// test setLength 2 that deals with input which upper limit of the range
			// this test case will test setLength function to set width to 100

		{
			int Length = 1;

			// since setLength is defined with integer pointers we need to use pass by reference

			setLength(100, &Length);

			// test is expected to pass coz input doesnt lie in the range, therefore, it wont change the width to 200

			Assert::AreNotEqual(100, Length);
		}

		TEST_METHOD(Test_getLength_3_lower_limit)
			// test setLength 1 that deals with input 0 since range is 1 to 99 inclusive
			// this test case will test setLength function to set Length to 0
			// so Length should be equal to 1 for the function to pass test corrrectly
		{
			int Length = 1;

			// since getLength is defined with integer pointers we need to use pass by reference

			setLength(0, &Length);

			// test is expected to pass if the code is written correctly.

			Assert::AreNotEqual(0, Length);
		}
	};
}

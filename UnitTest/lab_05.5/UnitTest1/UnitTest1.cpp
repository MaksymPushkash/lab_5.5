#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_05.5/lab_05.5.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PascalTriangleTests
{
    TEST_CLASS(PascalTriangleTests)
    {
    public:

        TEST_METHOD(TestBinomialCoefficientBaseCases)
        {
            
            Assert::AreEqual(1, binomialCoefficient(0, 0));
            Assert::AreEqual(1, binomialCoefficient(1, 0));
            Assert::AreEqual(1, binomialCoefficient(1, 1));
            Assert::AreEqual(1, binomialCoefficient(2, 0));
            Assert::AreEqual(1, binomialCoefficient(2, 2));
        }

        TEST_METHOD(TestBinomialCoefficientGeneralCases)
        {
            
            Assert::AreEqual(2, binomialCoefficient(2, 1));
            Assert::AreEqual(3, binomialCoefficient(3, 2));
            Assert::AreEqual(6, binomialCoefficient(4, 2));
            Assert::AreEqual(10, binomialCoefficient(5, 2));
        }

        TEST_METHOD(TestRecursionDepth)
        {
            
            recursionDepth = 0;
            maxDepth = 0;

            
            printPascalTriangle(5);

            
            Assert::AreEqual(4, maxDepth);  
        }


        TEST_METHOD(TestPascalTriangleOutput)
        {
            
            stringstream buffer;
            streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            printPascalTriangle(3);

            cout.rdbuf(oldCout);

            string expectedOutput = "1 \n1 1 \n1 2 1 \n";
            Assert::AreEqual(expectedOutput, buffer.str());
        }
    };
}


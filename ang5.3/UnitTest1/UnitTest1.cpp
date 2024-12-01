#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../lab5.3.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
    TEST_CLASS(UnitTest1) {
public:

    TEST_METHOD(TestPFunctionForAbsMoreThanOne) {
        double x = 2.0;
        double result = p(x);
        double expected = (cos(sin(x)) + 1) / (exp(-x) + 1);
        Assert::AreEqual(result, expected, 0.0001);
    }

    TEST_METHOD(TestPFunctionForAbsLessThanOne) {
        double x = 0.5;
        double result = p(x);
        double expected = 1;
        double a = 1;
        for (int j = 1; j <= 4; j++) {
            double R = -x * x / ((3 * j - 2) * (3 * j - 1) * 3 * j);
            a *= R;
            expected += a;
        }
        Assert::AreEqual(result, expected, 0.0001);
    }

    TEST_METHOD(TestCalculationForExpression) {
        double gp = 0.0, gk = 2.0;
        int n = 5;
        double dg = (gk - gp) / n;
        double g = gp;

        double expected_results[] = {
            p(1 - 0 * 0) + pow(p(1 + 0 - sqrt(p(0))), 2),
            p(1 - 0.4 * 0.4) + pow(p(1 + 0.4 - sqrt(p(0.4))), 2),
            p(1 - 0.8 * 0.8) + pow(p(1 + 0.8 - sqrt(p(0.8))), 2),
            p(1 - 1.2 * 1.2) + pow(p(1 + 1.2 - sqrt(p(1.2))), 2),
            p(1 - 1.6 * 1.6) + pow(p(1 + 1.6 - sqrt(p(1.6))), 2),
            p(1 - 2 * 2) + pow(p(1 + 2 - sqrt(p(2))), 2)
        };

        for (int i = 0; i < 6; i++) {
            double result = p(1 - g * g) + pow(p(1 + g - sqrt(p(g))), 2);
            Assert::AreEqual(result, expected_results[i], 0.0001);
            g += dg;
        }
    }
    };
}

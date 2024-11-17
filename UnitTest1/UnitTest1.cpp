#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4 rec/Source.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:

	TEST_METHOD(Test_CreateArrayRecursively) {
		std::vector<int> array = { 1, 2, 3 };
		Assert::AreEqual(3, (int)array.size());
		Assert::AreEqual(1, array[0]);
		Assert::AreEqual(2, array[1]);
		Assert::AreEqual(3, array[2]);
	}

	TEST_METHOD(Test_FindMinAbsElementRecursively) {
		Assert::AreEqual(1, findMinAbsElementRecursively({ 3, -4, -1, 5 }));
	}

	TEST_METHOD(Test_SumAfterFirstZeroRecursively) {
		Assert::AreEqual(9, sumAfterFirstZeroRecursively({ 5, 0, -3, 2, 4 }));
	}

	TEST_METHOD(Test_TransformArrayRecursively) {
		std::vector<int> array = { 1, 2, 3, 4, 5, 6 }, expected = { 1, 3, 5, 2, 4, 6 };
		std::vector<int> evenElements, oddElements;
		transformArrayRecursively(array, evenElements, oddElements);

		for (size_t i = 0; i < array.size(); i++)
			Assert::AreEqual(expected[i], array[i]);
	}
	};
}

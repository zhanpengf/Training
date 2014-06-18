// training2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "library.cpp"
#include <time.h>
using namespace std; 

void permutationAndShuffle()
// permutation 
{
	time_t start,end;
	int size = 3; 
	std::vector<int> sortedArray = uber::initSortedArray(size);

	std::vector<std::vector<int>> output2;
	time (&start);
	uber::permute2(sortedArray, 0, output2);
	time (&end);
	double dif2 = difftime (end,start); 
	//std::vector<std::vector<int>>().swap(output2); //free memory

	//std::vector<std::vector<int>> output1; 
	//time (&start);
	//uber::permute(sortedArray, 0, output1);
	//time (&end); 
	//double dif1 = difftime (end,start); 
	////std::vector<std::vector<int>>().swap(output1);  //free memory

	// check if shuffle works well
	const int permuteCount = output2.size();
	int histogram[6];
	for (int j = 0; j < permuteCount; j++)
	{
		histogram[j] = 0; 
	}

	for (int i = 0; i <1000000; i++)
	{
		sortedArray = uber::initSortedArray(size);
		uber::shuffle(sortedArray);
		for (int j = 0; j < permuteCount; j++)
		{
			int k = 0; 
			for (k = 0; k < size; k++)
			{
				if (sortedArray[k] != output2[j][k])
				{
					break; 
				}
			}
			if (k == size)
			{
				histogram[j]++; 
				break; 
			}
		}
	}
	// end check if shuffle works well		
}

int _tmain(int argc, _TCHAR* argv[])
{
	time_t start,end;
 
	{
		std::vector<int> sortedArray = uber::initSortedArray(10); 
		TreeNode* BST = uber::cretateBSTFromSortedArray(sortedArray); 
		std::vector<int> inOrderResult; 
		uber::inOrder(BST, inOrderResult);
		bool isBST = uber::isBST(BST);
	}

	{
		std::vector<int> unSortedArray = uber::initUnSortedArray(10); 
		TreeNode* BST = uber::cretateBSTFromSortedArray(unSortedArray); 
		std::vector<int> inOrderResult; 
		uber::inOrder(BST, inOrderResult);
		bool isBST = uber::isBST(BST); 
	}

	//permutationAndShuffle(); 

	{
		bool isPowerOf2 = uber::isPowerOf2(17); 
		int count = uber::countDifBits(170, 112);
	}

	{
		Hanoi hanoi1; 
		hanoi1.initStack(6);
		hanoi1.hanoi(5, hanoi1.tower1, hanoi1.tower2, hanoi1.tower3); 
	}

	{
		LinkedList linkedList; 
		linkedList.testReverseLinkedList(); 
	}
	{
		std::string result = uber::removeDuplicate("abaaabbb"); 
		std::string reverse = uber::reverseWords("   i         am happily a family man   "); 
	}

	{
		int test[5] = {-1, 4, -1, 4, 2}; 
		int size = sizeof(test)/sizeof(int); 
		int result = uber::largestSum(test, size); 
		int a = result; 
	}

	{
		char test[] = "1 223 65 -1 4 89"; 
		std::vector<int> result = uber::stringToIntArray(test); 
	}

	{
		static const int a1[] = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9 };
		vector<int> v1 (a1, a1 + sizeof(a1) / sizeof(a1[0]) );
		static const int a2[] = {2, 3, 3, 3, 4, 5};
		vector<int> v2 (a2, a2 + sizeof(a2) / sizeof(a2[0]) );
		vector<int> duplicates = uber::findDuplicates(v1, v2); 
	}
	{
		vector<string> result; 
		uber::permuteParenthesis(0, 0, 3, "", result); 
		vector<string> result2; 
		uber::permuteParenthesis2(0, 0, 3, "", result2); 
		 
		vector<string> result3; 
		char mychars[] = {'(',')'};
		std::vector<char> chars (mychars, mychars + sizeof(mychars) / sizeof(char) );
		std::vector<int> currentCount(2,0); 
		int myTotalCount[] = {3,3}; 
		std::vector<int> totalCount(myTotalCount, myTotalCount + sizeof(myTotalCount) / sizeof(int)); 
		uber::permuteStringWithDuplicates(chars, currentCount, totalCount, "", result3);  
		//uber::DFS(3,0,0,"",result); 
	}
	return 0;
	//test
}




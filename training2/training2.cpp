// training2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "library.cpp"
#include <time.h>

void permutationAndShuffle()
// permutation 
{
	time_t start,end;
	int size = 3; 
	std::vector<int> sortedArray = uber::initSortedArray(size);

	//int a[] = {1, 1, 1, 2, 2, 2}; 
	//int size = sizeof(a)/sizeof(int); 
	//std::vector<int> sortedArray; 
	//for (int i = 0; i < size; i++)
	//{
	//	sortedArray.push_back(a[i]); 
	//}

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
		//std::vector<int> sortedArray = uber::initSortedArray(10); 
		int a[] = {1, 3, 5, 7, 9, 20, 23, 27}; 
		int size = sizeof(a)/sizeof(int); 
		std::vector<int> sortedArray; 
		for (int i = 0; i < size; i++)
		{
			sortedArray.push_back(a[i]); 
		}
		TreeNode* BST = uber::cretateBSTFromSortedArray(sortedArray); 
		int result = uber::findLargestSmallerThanXinBST(BST, -10);
		int result1 = uber::find(BST, -10); 
		int max = INT_MAX; 
		int result2 = uber::findClosestToXinBST(BST, -10, max); 
		
	}
	{
		std::vector<int> sortedArray = uber::initSortedArray(10);
		TreeNode* BST = uber::cretateBSTFromSortedArray(sortedArray);
		TreeNode* node1 = BST->left->left; 
		TreeNode* node2 = BST->left->right; 
		TreeNode* ancestor = uber::findLowestAncestor(node1, node2, BST); 
	}
	{
		int a[] = {1, 2, 3, 4, 1, 3, 2, 1}; 
		int size = sizeof(a)/sizeof(int); 
		std::vector<int> bars; 
		for (int i = 0; i < size; i++)
		{
			bars.push_back(a[i]); 
		}
		int result = uber::largestRectangleArea(bars); 
	}

	{
		vector<string> result; 
		string s; 
		uber::DFS(3, 0 , 0, s, result);  
	}
	{
		int n[] = {1, 2, 1}; // number for each type of parentheses
		int l[] = {0, 0, 0}; // number of left parentheses that have been generated
		int r[] = {0, 0, 0}; // ..........right........
		stack<char> s;
		string sol;
		uber::generateParentheses(n, l, r, s, sol);  
		//return 0;

	}
	{
		string s = "aabcd"; 
		vector<string> result; 
		uber::permuteString(s, 0, 5, result); 
	}
	{
		string s = "aabcd"; 
		vector<string> result; 
		uber::permuteStringWithDuplicate(s, 0, 5, result); 
	}
	return 0;
	//test
}




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
		std::string r2 = uber::reverseWords(" "); 
		//string s = "+---...2x+--x--+x-+-x2...---+";//" "; //"+---...2x+--x--+x-+-x2...---+";
		string s = "hello world!";
		uber::reverseWords2(s); 
		int a = 0; 
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
		 
		vector<string> result3; 
		char mychars[] = {'(',')'};
		std::vector<char> chars (mychars, mychars + sizeof(mychars) / sizeof(char) );
		std::vector<int> currentCount(2,0); 
		int myTotalCount[] = {3,3}; 
		std::vector<int> totalCount(myTotalCount, myTotalCount + sizeof(myTotalCount) / sizeof(int)); 
		uber::permuteStringWithDuplicates(chars, currentCount, totalCount, "", result3); 

		vector<string> result4;
		uber::permuteStringWithDuplicatesParen(chars, currentCount, totalCount, "", result4); 
		//uber::DFS(3,0,0,"",result); 
	}

	{
		vector<string> result3; 
		char mychars[] = {'(','[','{',')',']', '}'};
		std::vector<char> chars (mychars, mychars + sizeof(mychars) / sizeof(char) );
		std::vector<int> currentCount(6,0); 
		int myTotalCount[] = {1,1,2,1,1,2}; 
		std::vector<int> totalCount(myTotalCount, myTotalCount + sizeof(myTotalCount) / sizeof(int)); 
		
		vector<string> result4;
		stack<char> S; 
		uber::permuteStringWithDuplicatesParenMulti(chars, currentCount, totalCount, "", S, result4);
	}
	{
		int myJobs[] = { 1, 2};
		std::vector<int> jobs(myJobs, myJobs + sizeof(myJobs) / sizeof(int)); 
		std::vector<vector<int>> servers(2,vector<int>(0,0));
		vector<vector<vector<int>>> result; 
		uber::findAssignment(jobs, servers, 0, result); 
		int k347 = uber::findKthSmallest347(3); // should be 336
		k347 = uber::findKthSmallest347(4); //588
		k347 = uber::findKthSmallest347(5); //756

	}

	{
		int a[] = { 1, 1, 1, 0, 1, 1, 1, 1}; 
		int longestOnes = uber::findLongestOnes(a, 8);
		int a1 = 0; 
	}

	{
		int a[] = { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1};
		//int a[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; 
		//int a[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

		int flippedLongestOnes = uber::findLongestOnesWithFlip(a, 10);
		int a1 = 0; 
	}

	{
		string source = "abccccdef"; 
		char mychars[] = {'a', 'b', 'c'};
		std::vector<char> chars (mychars, mychars + sizeof(mychars) / sizeof(char) );
		vector<string> result = uber::findSubStr(source, chars); 
		int fib[10]; 
		for (int i = 0; i<10; i++)
		{
			fib[i] = uber::fib(i); 
		}
	}
	{
		int arr[] = { 4, 3, 0, 1, 1, 2}; 
		int result = uber::canJump(arr, 6);
		bool canJump = uber::canJump1(arr, 6); 
		int a = 0; 
	}

	{
		int arr[] = { 4, 3, 0, 1, 5, 2}; 
		uber::quickSort(arr,0,5); 
		int a = 0; 
	}

	{
		int myJobs[] = { 3, 2, 4};
		std::vector<int> jobs(myJobs, myJobs + sizeof(myJobs) / sizeof (int)); 
		vector<int> result = uber::twoSum(jobs, 6); 
		int a = (-10)%12;
		int b = (-10)/12;
		a = 0; 
	}

	{
		vector<vector<int> > matrix(2, vector<int>(2, 1));
		vector<int> result = uber::spiralOrder(matrix); 
	}
	{
		double result = uber::powr(8.88, 3); 
		int a = 0; 
	}

	{
		//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		string s = "aaab"; 
		unordered_set<string> dict; 
		dict.insert("a"); 
		dict.insert("aa"); 
		dict.insert("aaa"); 
		dict.insert("b"); 
		//vector<string> result = uber::wordBreak(s,dict);
		vector <int> breakPoints;
		vector <vector<string>> wordsAtPoints; // the possible words of this point
		uber::findBreakPoints(s, dict, breakPoints, wordsAtPoints); 
		vector<string> result = uber::wordBreak2(s, dict); 
		int a = 0; 

	}
	{
		//wrong
		vector<TreeNode *> result = uber::generateTrees(3); 
		int a = 0; 
	}

	{
		uber::ListNode *head = new uber::ListNode(2);
		uber::ListNode *cur = head;
		int input[] = {2,1};

		for (int i = 1; i < 2; i++)
		{
			uber::ListNode *node = new uber::ListNode(input[i]); 
			cur->next = node; 
			cur = node; 
		}
		
		
		uber::ListNode *result = uber::partition(head, 2); 
		int a = 0; 
	}
	{
		string result3 = uber::getPermutation4(4,24); 
		for (int i = 1; i < 2; i++)
		{
			string result = uber::getPermutation(9, i); 
			string result2 = uber::getPermutation3(9,i);
			
			if (result != result2)
			{
				int k = 1; // something is wrong
			}
		}
		int a = 0; 
	}
	{
		int count = 0; 
		uber::walk(0,0,7,3,count);
		count = uber::walkDP(7,3);
		count = uber::walkDP2(7,3); 
		count = uber::walkDP2(3,7);
		int a = 0; 
	}

	return 0;
	//test
}




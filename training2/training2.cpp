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
	uber::permute(sortedArray, 0, output2);
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
		string s = "abaaabbb"; 
		std::string result = uber::removeDuplicate(s); 
		string res2 = uber::removeDuplicate2(s); 
		std::string reverse = uber::reverseWords("   i         am happily a family man   "); 
		std::string r2 = uber::reverseWords(" "); 
		//string s = "+---...2x+--x--+x-+-x2...---+";//" "; //"+---...2x+--x--+x-+-x2...---+";
		string s1 = "hello world!";
		uber::reverseWords2(s1); 
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
		vector<string> res; 
		uber::generateParentheses(n, l, r, s, sol, res);  
		//return 0;

	}
	{
		string s = "aabaa"; 
		vector<string> result;
		int n = s.size(); 
		uber::permuteString(s, 0, n, result); 
		int count = 0; 
		vector<string> res1 = uber::permuteString(s, count); 
		string s2 = "abc"; 
		vector<string> res2 = uber::permuteString(s2, count); 
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

		vector<int> res; 
		//for (int i = 1; i < 100; i++)
		//{
		//	int temp = uber::findKthSmallest347_wrong(i); 
		//	res.push_back(temp); 
		//	if ( temp!= uber::findKthSmallest347(i))
		//	{
		//		break; 
		//	}
		//}

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
		std::vector<int> vec(a, a + sizeof(a) / sizeof(int)); 
		int res1 = uber::longestConsecutiveOneFlip(vec); 
		int res2 = uber::longestConsecutiveOneFlip2(vec); 
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
		int arr[] = {4,5}; //{ 4, 3, 0, 1, 5, 2}; 
		uber::quickSort(arr,0,1); 

		int arr1[] = { 4, 3, 0, 1, 5, 2}; 
		int result[6]; 
		for (int i = 0; i<6; i++)
		{
			result[i] = uber::quickSelect(arr1, 0, 5, i); 
		}
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
		double res2 = uber::powr817(8.88, 3); 
		double res3 = uber::powr(8.88, -3); 
		double res4 = uber::powr817(8.88, -3);
		double res5 = pow(8.88, 3);
		double res6 = pow(8.88, -3); 
		int a = 0; 
	}

	{
		//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		string s = "catsanddog"; 
		unordered_set<string> dict; 
		//"cat", "cats", "and", "sand", "dog"
		dict.insert("cat");
		dict.insert("cats");
		dict.insert("and"); 
		dict.insert("sand");
		dict.insert("dog"); 
		//dict.insert("aa"); 
		//dict.insert("aaa"); 
		//dict.insert("b"); 
		//vector<string> result = uber::wordBreak(s,dict);
		vector <int> breakPoints;
		vector <vector<string>> wordsAtPoints; // the possible words of this point
		uber::findBreakPoints(s, dict, breakPoints, wordsAtPoints); 
		//vector<string> result = uber::wordBreak2(s, dict); 
		vector<string> result2 = uber::wordBreak817(s, dict); 
		vector<string> res3 = uber::wordBreak(s, dict); 
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

	{
		for (int i = 0; i < 20; i++)
		{
			std::vector<int> unSortedArray = uber::initUnSortedArray(100);
			std::vector<int> result = uber::LIS(unSortedArray); 
			int count = uber::LIS3(unSortedArray);
			int count2 = uber::LIS1(unSortedArray); 
			if (count != count2)
			{
				break; 
			}
		}
		int a = 0; 
	}
	{
		vector<string> result = uber::restoreIpAddresses("2551234"); 
		int a = 0; 
	}
	{
		int myJobs[] = {2,5,10,25};
		std::vector<int> coins(myJobs, myJobs + sizeof(myJobs) / sizeof (int));
		int a1 = uber::countCoins(coins, 99); 
		//int a2 = uber::countCoins2(coins, 100); 
		vector<int> solution(coins.size());
	    int count = 0; 
		int o = 0; 
		uber::findCombinations(coins, 99, 0, solution, count, o);
		int count2 = 0; 
		int o2 = 0; 
		uber::findCombinations2(coins, 99, 0, solution, count2, o2);
	}
	{
		vector<vector<string>> result = uber::solveNQueens(1);
		int a = 0; 
	}
	{
		vector<string> result = uber::letterCombinations("12"); 
		vector<string> result2 = uber::letterCombinations2("12"); 
		int a = 0; 
	}
	{
		int A[] = {1,2,1,2,0, 0}; 
		uber::sortColors(A,6); 
	}

	{
		int arr[]  = {7,2,8,5,0,9,1,2,9}; //{7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
		vector<int> v(arr, arr + sizeof(arr) / sizeof (int));
		vector<int> res = uber::plusOne(v); 
		vector<int> res2 = uber::plusOne2(v); 

		int a = 0; 
	}

	{
		bool result = uber::isMatch("aaaphonix123cd", "aaa*cd"); 
		int a = 0; 
	}
	{
		string result = uber::multiply("11", "1"); 
		int a = 0; 
	}

	{
		uber::Interval i1(1,4);
		uber::Interval i2(4,5); 
		vector<uber::Interval> intervals;
		intervals.push_back(i1); 
		intervals.push_back(i2);
		vector<uber::Interval> res = uber::merge(intervals); 
		int a = 0; 

	}

	{
		std::vector<int> unSortedArray = uber::initUnSortedArray(4);
		int count = 0; 
		vector<vector<int>> res = uber::subsets(unSortedArray, count); 
		int count2 = 0; 
		vector<vector<int>> res2 = uber::subsets2(unSortedArray, count2);
		int count3 = 0; 
		vector<vector<int>> res3 = uber::subsets3(unSortedArray, count3);
		int a = 0; 
	}
	{
		std::vector<int> unSortedArray(4, 1);
		for (int i = 0; i < 1; i++)
		{
			unSortedArray[i] = 1; 
		}
		
		vector<vector<int>> res3 = uber::combinationSum2(unSortedArray, 1); 
			int a = 0; 
	}
	{
		string res = uber::addBinary("100", "110010"); 
		int a = 0; 
	}
	{
		int a[10]; 
		for (int i = 0; i < 10; i ++)
		{
			a[i] = uber::numTrees(i); 
			a[i] = uber::numTrees2(i); 
		}
	}
	{
		TreeNode* a = new TreeNode(1);
		vector<int> res = uber::inorderTraversal(a); 
		int res1 = uber::uniquePaths(3, 3); 

		vector<vector<int>> m(1,vector<int>(2,1));
		m[0][1] = 3; 
		bool res2 = uber::searchMatrix(m,3); 
		uber::ListNode* l0 = new uber::ListNode(0);
		uber::ListNode* l1 = new uber::ListNode(0);
		l0->next = l1; 
		l1->next = l0; 
		uber::ListNode* cycleHead = uber::detectCycle(l0); 
		vector<vector<int>> gm = uber::generateMatrix(1); 
		TreeNode *t0 = new TreeNode(-2); 
		TreeNode *t1 = new TreeNode(-3);
		t0->right = t1; 
		bool res3 = uber::hasPathSum(t0, -5); 
		int A[] = {1};
		int res4 = uber::search(A, 1, 0); 
		int res5 = uber::lengthOfLastWord("hello world h"); 
		bool res6 = uber::isPalindrome(-1); //-2147483648); 
		bool res7 = uber::isValidParentheses("()"); 

		vector<vector<int>> pathSum = uber::pathSum(t0, -5); 
		string res8 = uber::countAndSay2(3); 

		int arr[]  = {1,2,4,8,7,3}; 
		vector<int> postOrder(arr, arr + sizeof(arr) / sizeof (int));
		sort(std::begin(arr), std::end(arr));
		vector<int> inOrder(arr, arr + sizeof(arr) / sizeof (int));
		TreeNode* res9 = uber::buildTree(inOrder, postOrder); 

		vector<vector<string>> res10 = uber::partition("a"); 
		int arr1[]  = {1,2,2}; 
		vector<int> arr11(arr1, arr1 + sizeof(arr1) / sizeof (int)); 
		
		vector<vector<int>> res11 = uber::permuteUnique(arr11); 
		vector<string> input; 
		input.push_back(""); 
		input.push_back(""); 
		input.push_back("");
		input.push_back("feng");
		input.push_back("an"); 
		input.push_back("na"); 		
		input.push_back("efng");
		vector<string> res12 = uber::anagrams2(input);

		uber::print(10); 
		int aa = 0; 

	} 
	{
		int arr[]  = {1,2,-1,-1,-1,4,8,9,20,-1,-1,-1}; 
		vector<int> a(arr, arr + sizeof(arr) / sizeof (int));
		int res = uber::binarySearch(a, 0, a.size() - 1, 1);
		string input = "abbbaacyuiocccc"; 
		string res1 = uber::remove(input);

		// create vector matrix
		typedef int type; 
		type matrix[4][5]=
		{
			{ 1,  1, -1, -4, -20},
			{-8, -3,  4,  2,   1},
			{ 3,  8, 10,  1,   3},
			{-4, -1, 11,  12,  -6}
		};
		vector<vector<type> > vectorMatrix;
		for (int i = 0; i < 4; i++)
		{
			vector<type> row_vec(matrix[i], matrix[i] + sizeof(matrix[i]) / sizeof(type) );		
			vectorMatrix.push_back(row_vec);
		}
		// end

		int res2 = uber::largestSumRectangle(vectorMatrix);
		int starti; 
		int startj; 
		vector<int> resSeq;
		vector<vector<int>> resAllSeq; 
		int temp =  1;
		int res3 = uber::findIncrease(vectorMatrix, starti, startj, resSeq, resAllSeq);
		int res4; 
		vector<int> resSeq1;
		vector<int> maxSeq; 
		vector<vector<int>> allSeq; 
		uber::find(vectorMatrix, 0, 4, res4, resSeq1, maxSeq, allSeq); 

		int b = 0; 
	}

	{
		// create vector matrix
		typedef int type; 
		type matrix[4][5]=
		{
			{ 1,  1,  1,  1, -20},
			{-8, -3,  -4,  1,   1},
			{ 3,  8,  1,  1,   3},
			{-4, -4, 11,  12,  -6}
		};
		vector<vector<type> > vectorMatrix;
		for (int i = 0; i < 4; i++)
		{
			vector<type> row_vec(matrix[i], matrix[i] + sizeof(matrix[i]) / sizeof(type) );		
			vectorMatrix.push_back(row_vec);
		}
		// end
		//uber::dfsFlood(vectorMatrix, 3, 0, 0); 
		uber::dfsFlood91(vectorMatrix, 3, 0, vectorMatrix[3][0], 0); 
		int res1 = uber::minCut("cabababcbc"); 
		int res2 = uber::findLongestPalindrome("cabababcbc"); 
		vector<int> path; 
		int res3 = uber::findMaxSumPath(vectorMatrix, path); 
		string res4 = "ab12"; 
		uber::convertAB12(res4);
		string res5 = "abcde12345";
		uber::convertAB12(res5); 
		uber::convertA1B2(res5); 
		int arr[]  = {1,2,4,8,7,3}; 
		vector<int> postOrder(arr, arr + sizeof(arr) / sizeof (int));
		TreeNode *res6 = uber::reconPostOrder(postOrder); 



		int a = 0; 

	}
	{
		int arr[]  = {4,2,1,3,5,6}; 
		vector<int> preOrder(arr, arr + sizeof(arr) / sizeof (int));
		TreeNode *res1 = uber::reconPreOrder(preOrder); 
		vector<vector<vector<int>>> res2 = uber::assignTasks(3, 2); 
		int a = 0; 
	}
	{
		int arr[]  = {1, 1, 1, 1,3,5,6}; 
		vector<int> vecArr(arr, arr + sizeof(arr) / sizeof (int));
		int res = uber::findMajority(vecArr);

		vector<vector<int>> configs; 
		vector<int> tempRes;
		configs.push_back(tempRes); 
		uber::validConfig(4, 0, tempRes, configs); 
		
		vector<vector<bool>> configTwoRows = uber::validConfigTwoRows(configs); 


		// create vector matrix
		typedef int type; 
		type matrix[4][5]=
		{
			{ 1,  1,  1,  1,  20},
			{ 0,  0,  0,  0,   0},
			{ 3, 18,  1, 21,  3},
			{ 4,  4,  0,  2,  6}
		};
		//{
		//	{ 1,  1,  1,  1,  20},
		//	{ 8,  3,  4,  1,   1},
		//	{ 3,  8,  1,  1,   3},
		//	{ 4,  4, 11, 12,   6}
		//};
		vector<vector<type> > vectorMatrix;
		for (int i = 0; i < 4; i++)
		{
			vector<type> row_vec(matrix[i], matrix[i] + sizeof(matrix[i]) / sizeof(type) );		
			vectorMatrix.push_back(row_vec);
		}
		// end
		int res3 = uber::maxSumMatrixNoEightNeighbor(vectorMatrix); 
		
	}
	{
		int arr[]  = {2 ,1, 3, 1}; 
		vector<int> vecArr(arr, arr + sizeof(arr) / sizeof (int));
		int res = uber::maxHistogram(vecArr); 
		int res2 = uber::largestRectangleArea2(vecArr); 
		int res3 = uber::largestHistogram1(vecArr);
		vector<vector<int>> res4 = uber::combine(1,1); 
	}
	{
		std::vector<int> arr = uber::initSortedArray(6);
		vector<vector<int>> res1 = uber::permutation816(arr); 
		vector<vector<int>> res2 = uber::subset816(arr); 
		vector<vector<int>> res3 = uber::combination816(arr, 2);
		int myJobs[] = {1, 2, 3};
		std::vector<int> coins(myJobs, myJobs + sizeof(myJobs) / sizeof (int));
		// res4 and res 5 are the same, the order matters, we are counting permutations
		// the dp rule is that to get to dp[i] there are coins.size() number of ways, 
		// dp[i] = sum(dp[i- coins[k]]), k = 0 to coins.size() - 1
		int target = 10;  
		int res4 = uber::countCoinsPermutation816(coins, target); 
		int res5 = uber::climbStairs(target);
		vector<vector<int>> res9 = uber::findAllPermutationsCoins816(coins, target); 

		// but if we are counting combinations, there are only two way to get to dp[i], 
		// one is adding another coins[k], the other is not adding coins[k]
		// dp[i] = dp[i-coins[k]] + dp[i]
		int res6 = uber::countCoinsCombination816(coins, target); 
		int res7 = uber::countCoins(coins, target); 
		vector<vector<int>> res8 = uber::findAllCoinsCombinations816(coins, target);

		std::vector<int> sortedArray = uber::initSortedArray(10); 
		TreeNode* BST = uber::cretateBSTFromSortedArray(sortedArray); 

		TreeNode* copy = uber::copyBinaryTree(BST); 
		TreeNode* copy2 = BST; 
		int res10 = uber::kthLargestBST816(BST, 8); 
		int k = 3; 
		int res11; 
		uber::kthSmallest(BST, k, res11); 		
	}

	{
		int arr[]  = {1, 1, 1, 1, 1, 1}; 
		vector<int> vecArr(arr, arr + sizeof(arr) / sizeof (int));
		int res1 = uber::countTarget1(vecArr, 1);
		int res2 = uber::countTarget2(vecArr, 1);
		vector<int> res3 = uber::searchRange(arr, 6, 1); 
		vector<vector<string>> res4 = uber::partitionPalindrome817("aabbbcatac"); 
		int res5 = uber::lengthOfLongestSubstring("abcabcaa"); 
		int res6 = uber::lengthOfLongestSubstring817("abcabcaa"); 
		
		int a = 0; 
	}
	{
		int arr[]  = {1, 1, 1, 2, 3, 3, 4, 5}; 
		vector<int> vecArr(arr, arr + sizeof(arr) / sizeof (int));
		double res1 = uber::findMedian(vecArr); 
		char a[] = ""; 
		char b[] = ""; 
		char* res = uber::strStr(a, b); 
		string S = "raabbbbit"; 
		string T = "rabbit"; 
		int res2 = uber::numDistinct(S, T); 
		S = "rabbabbit";
		int res3 = uber::numDistinct(S, T); 
		S = "rabbbit"; 
		int res4 = uber::numDistinct(S, T); 
		S = "rabbit"; 
		int res5 = uber::numDistinct(S, T);

		string S1 = "rtttt"; 
		string T1 = "to"; 
		int res6 = uber::numDistinct(S1, T1); 
		int res7 = uber::numDistinct1(S1,T1); 
		vector <int> res8 = uber::findSquareSum(25); 
		vector <int> res9 = uber::findSquareSum(7);
		vector <int> res10 = uber::findSquareSum(8);
		vector<int> parCount(3, 0); 
		parCount[0] = 1; 
		parCount[1] = 2; 
		parCount[2] = 1; 
		vector <string> res11 = uber::genParenth(parCount); 
	}
	{
		int arr[] = {-10, -18, -7}; //{1, 3, 2, 5, -18, 9, 4, 7, 3};
		vector<int> vecArr(arr, arr + sizeof(arr) / sizeof (int));
		vector<int> res1 = uber::findMaxSlidingWindow(vecArr, 3); 
		vector<int> res2 = uber::windowKMax(vecArr, 3);
		int res3; 
		int res4;
		uber::findMinMax(vecArr, res3, res4); 
		int res6; 
		vector<int> res5 = uber::findMaxSum(vecArr, res6); 
	}
	{
		int arr1[] = {-10, -8, -7}; //{1, 3, 2, 5, -18, 9, 4, 7, 3};
		int arr2[] = {1, 4, 5}; 
		int arr3[] = {-5, 3, 10};
		vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof (int));
		//vector<int> vec1 = uber::initVector(arr1);
		vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof (int));
		vector<int> vec3(arr3, arr3 + sizeof(arr3) / sizeof (int));; 
		vector<vector<int>> karray; 
		karray.push_back(vec1); 
		karray.push_back(vec2); 
		karray.push_back(vec3); 
		vector<int> res1 = uber::kwayMerge2(karray); 
		vector<int> res2 = uber::kWayMerge3(karray); 
		vector<int> res3 = uber::kWayMerge(karray); 
		int arr4[] = {2, 3, 1, 1, 4}; 
		int res4 = uber::jump(arr4, 5); 
		int arr5[] = {0, 0, 2, 3}; 
		int res5 = uber::jump(arr5, 4); 
		int a = 0; 

		vector<int> res6;
		vector<int> res7; 
		vector<int> res8_1; 
		vector<int> res8_2; 
		int count = vec1.size() * vec2.size(); 

		int res8_3 = uber::findK(vec1, vec2, 0, 0, 3);
		for (int k = 1; k < count; k++)
		{
			// these two are looking for the sum
			int temp = uber::findksmallest(vec1, vec2, k); 
			res6.push_back(temp);
			temp = uber::findKthSmallest(vec1, vec2, k); 
			res7.push_back(temp);
			// end
			// these two are looking for the kth in merged array
			temp = uber::findKthSmallestBinary(arr1, 3, arr2, 3, k);
			res8_1.push_back(temp); 
			temp = uber::findK(vec1, vec2, 0, 0, k); 
			res8_2.push_back(temp); 
			// end
		}

		uber::RandomListNode *head = new uber::RandomListNode(-1); 
		uber::RandomListNode *node =  new uber::RandomListNode(-1);
		head->next = node; 
		uber::RandomListNode *res8 = uber::copyRandomList2(head); 
		uber::RandomListNode *res9 = uber::copyRandomList(head); 

		string s = "*11*00*11*"; 
		string s1 = s; 
		uber::replaceWildCard(s, 0); 
		
		vector<string> res10 = uber::replaceWildCard2(s1);
		vector<string> res11 = uber::replaceWildCard3(s1);

		string res12 = uber::LongestCommonSubstring("Hello World", "lime jello");

		// create vector matrix
		typedef int type; 
		type matrix[4][5]=
		{
			{ 1,  1,  1,   1,  2},
			{ 2,  5,  8,  10, 11},
			{ 3,  8,  9,  12, 13},
			{ 4, 10, 11,  12, 18}
		};
		vector<vector<type> > vectorMatrix;
		for (int i = 0; i < 4; i++)
		{
			vector<type> row_vec(matrix[i], matrix[i] + sizeof(matrix[i]) / sizeof(type) );		
			vectorMatrix.push_back(row_vec);
		}

		vector<int> result; 
		for (int k = 1; k <= 20; k++)
		{
			int temp = uber::findKthSmallest2D(vectorMatrix, k); 
			result.push_back(temp); 
		}

		TreeNode *root = new TreeNode(1); 
		TreeNode *cur = root; 
		for (int i = 0; i < 3; i++)
		{
			TreeNode *left = new TreeNode((i + 1) * 2); 
			TreeNode *right = new TreeNode((i + 1) * 2 + 1); 
			cur->left = left; 
			cur->right = right; 
			cur = cur->left; 
		}
		TreeNode *newRoot = uber::reverseTree(root); 

		vector<string> res13; 
		for (int i = 0; i < 10; i++)
		{
			res13.push_back(uber::findSubStr("aaabbbbbbbccdddddeffg", i)); 
		}

	}
	return 0;
	//test
}




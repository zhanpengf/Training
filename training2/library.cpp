#include "stdafx.h"
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>          
#include <unordered_set>
#include <unordered_map>

#include <iostream>
#include <unordered_set>
using namespace std;

//notes:
// 8/29/2014
// 1. copyGraph: need to be careful that hashset does not work, must use hashmap. When a source node
// is found in the hash, we must return the corresponding destination node, not the source node. 

// 8/17/2014: 
// 1. in function vector<vector<string>> partition(string s), the i and j in dp array stand
// for the starting index of the word and the length of the word. 
// 2. in function minCutPalindrome816 the i and j in dp array stand for the starting index 
// and ending index of the word. 
// both 1. and 2. work, they are just slightly different approaches. 
// 3. both palindrome and wordbreak problem have no need to pad extra character to the beginning. 
// Some answers from online use padding. Their purpose is to unify the dp condition to one expression. 
// I find it more cubersome than helping for me. 
// I simply check if the beginning index is 0. 
// in wordbreak817, if (dict.find(word) != dict.end() && (j == 0 || dp[j - 1].size() > 0))
// in minCutPalindrome816, if(s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) then if(i==0)
// 4. in sortColors, i0 points to the location for the next 0, i2 points to the location for the next 2
// i is the current pointer, if a[i] == 2, swap a[i] and a[i2], i2--, if a[i] == 0, swap a[i] and a[i0], i0++
// before a[i] are only 0's and 1's. Therefore swapping a[i] and a[i0] will only put 1 in a[i]. 
// if a[i] == 1, do nothing and i++. Be careful the termination condition should be while (i <= i2), 
// because when i == i2, it's possible that a[i] = 0, then we still need to swap a[i] and a[i0].
// 5. countCoinsCombination816 vs countCoinsPermutation816:
// combination: to reach a target number, the number of combination = # of combinations without coin[k] 
// + # of combinations with coin[k]. So dp outer loop is coin value 0:k, inner loop is sum value. 
// permuation: to reach a target number, # of permutation = sum of permutation of coin[0:k]. So dp
// inner loop is 0:k, outer loop is sum value. 

// 8/11/2014:
// 1. permuteWithDuplicate: use swapped() function to check k = from start to i, 
// is there any s[i] == s[k]. If yes, don't swap. 
// 2. for dfs + backtrack, most cases push temp result to final result when leaf node is reached. 
// Exception is subset problem, push result at every node. 
// 3. for recursively removing duplicate character, pop when the current char is the same as stack 
// top, then move the pointer to the end of the current sequence of duplicated chars. 
// 4. for LIS, use DP, dp[i] stores the LIS ending at i, for i, scan all dp[0] to dp[i-1], 
// if a[k] < a[i], dp[i] = max(dp[i], dp[k] + 1)
// 5. for max sum 2D, write a function of max sum 1D, loop through all combinations of 
// column start and end, sum value of columns for all rows. sum[i] += a[i][k] (k = start to end).
// then apply max sum 1D to sum[i] array. O^3. 

struct TreeNode
{
	int val;
	TreeNode *left; 
	TreeNode *right; 
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode():left(NULL), right(NULL) {}
}; 

// linkedList node
struct Node
{
	int val; 
	Node* next; 
};

class uber
{
public: 
	//const int arraySize = 10; 
	//int a[arraySize]; 
	//int sortedA[arraySize];
	//std::vector <int> vec_a; 
	//std::vector <int> sorted_a; 


public: 
	static std::vector<int> initSortedArray(int arraySize)
	{
		std::vector<int> result;
		for (int i = 0; i < arraySize; i++)
		{
			result.push_back(i); 
		}
		return result; 
	}

	static void swap(std::vector<int> &vec, int ia, int ib)
	{
		int temp = vec[ia]; 
		vec[ia] = vec[ib]; 
		vec[ib] = temp; 
	}

	static void shuffle(std::vector<int> &vec)
	{
		int size = vec.size(); 
		//srand(time(NULL)); /* seed random number generator */

		for (int i = 0; i < size - 1; i++)
		{
			int randNum = i + rand() % (size - i); // correct
			//int randNum = rand() % size; // will produce biased results. For 3 numbers, 3 results have twice as much chance as the other 3. 
			swap(vec, i, randNum); 
		}
	}

	static std::vector<int> initUnSortedArray(int arraySize)
	{
		std::vector<int> result; 
		for (int i = 0; i < arraySize; i++)
		{
			result.push_back(i); 
		} 
		shuffle(result);
		return result; 
	}

	//TreeNode* cretateBSTFromSortedArray(std::vector<int> input, int start, int end); 
	static TreeNode* cretateBSTFromSortedArray(std::vector<int> input, int start, int end)
	{
		if  ((start > end) || (input.size() ==0)) 
		{	 
			return NULL; 
		}
		TreeNode *result = new TreeNode();
		int mid = start + (end - start) / 2;
		result->val = input[mid];


		result->left = cretateBSTFromSortedArray(input, start, mid-1);
		result->right = cretateBSTFromSortedArray(input, mid + 1, end);
		return result; 
	}

	static TreeNode *cretateBSTFromSortedArray(std::vector<int> input)
	{
		return cretateBSTFromSortedArray(input, 0, input.size() - 1); 
	}

	static void inOrder(TreeNode *root, std::vector<int> &result)
	{
		if (root == NULL)
		{
			return; 
		}
		inOrder(root->left, result);
		result.push_back(root->val);
		inOrder(root->right, result); 
	}

	static bool isBST(TreeNode *root)
	{
		return isBSTHelper(root, INT_MIN, INT_MAX); 
	}

	static bool isBSTHelper(TreeNode *root, int min, int max)
	{
		if (root == NULL)
		{
			return true;
		}
		int val = root->val; 

		if ((root->val <= min) || (root->val >= max))
		{
			return false; 
		}
		return (isBSTHelper(root->left, min, val) && isBSTHelper(root->right, val, max));  
	}

	static TreeNode * findLowestAncestor(TreeNode *node1, TreeNode *node2, TreeNode *root)
	{
		if (root == NULL)
		{
			return NULL; 
		}
		if ((root == node1)||(root == node2))
		{
			return root; 
		}
		TreeNode *Left = findLowestAncestor(node1, node2, root->left); 
		TreeNode *Right = findLowestAncestor(node1, node2, root->right); 
		if ((Left != NULL)&&(Right != NULL))
		{
			return root; 
		}
		else
		{
			return Left?Left:Right; 
		}
	}

	//static TreeNode * findLowestAncestor2(TreeNode *node1, TreeNode *node2, TreeNode *root)
	//{
	//	std::vector<TreeNode*> node1path; 
	//	std::vector<TreeNode*> node2path; 

	//	TreeNode* currentNode = node1; 
	//	while (currentNode->
	//}


	// Find the largest number in a BST that is smaller than x 
	// recursively search in the BST's left subtree and right subtree.
	// 
	// If x > root, the solution is larger of the root and solution of the right tree, 
	// otherwise, the solution is in the left tree
	static int findLargestSmallerThanXinBST(TreeNode* root, int x)
	{
		int currentSolution = INT_MIN; 
		if (root == NULL)
		{
			return INT_MIN; 
		}
		if (x<=root->val)
		{
			currentSolution = findLargestSmallerThanXinBST(root->left, x); 
		}
		else
		{
			currentSolution = std::max(findLargestSmallerThanXinBST(root->right, x), root->val); 
		}
		return currentSolution;
	}

	static int find(TreeNode* root, int x) {
		TreeNode* curr = root;
		int result = x;
		while (curr) {
			if (curr->val >= x) {
				curr = curr->left;
			} else {
				result = curr->val;
				curr = curr->right;
			}
		}
		return result;
	}
	// find the number that is closest to x in a BST
	static int findClosestToXinBST(TreeNode *root, int x, int &smallestDiff)
	{	
		if (root == NULL)
		{
			return INT_MIN; 
		}
		if (root->val == x)
		{
			smallestDiff = 0; 
			return x; 
		}
		int currentSolution; 
		if (root->val > x)
		{
			currentSolution = findClosestToXinBST(root->left, x, smallestDiff); 
		}
		else
		{
			currentSolution = findClosestToXinBST(root->right, x, smallestDiff); 
		}

		int rootDiff = std::abs(x-root->val); 
		if (rootDiff < smallestDiff)
		{
			currentSolution = root->val;
			smallestDiff = rootDiff; 
		}
		return currentSolution; 

	}


	static void permute(std::vector<int> &input, int i, std::vector<std::vector<int>> &output)
	{
		int size = input.size(); 
		if (i == size - 1)
		{
			output.push_back(input);
			return; 
		}		
		for (int j = i; j < size; j++)
		{
			swap(input, i, j);  
			permute(input, i + 1, output); 
			swap(input, i, j); 
		}		
	}


	static bool isPowerOf2(int a)
	{
		if (a == 1)
		{
			return true; 
		}
		int div = a; 
		int mod = 0; 
		while (div > 1)
		{
			mod = div % 2; 
			if (mod != 0)
			{
				return false; 
			}
			div = div / 2;
		}
		return true; 
	}

	static int countDifBits(int a, int b) 
	{
		int count = 0; 
		int c = a ^ b;
		while (c > 0)
		{
			if (c % 2 == 1)
			{
				count++; 
			}
			c /= 2; 
		}
		return count; 
	}

	static std::string removeDuplicate(std::string input)
	{
		if (input.size() == 0)
		{
			return ""; 
		}
		std::string result; 
		char currentChar = input[0]; 
		int i = 0; 
		int j = 0; 
		while (i < input.size())
		{
			input[j] = currentChar;
			while ((i<input.size())&&(input[i] == currentChar))
			{
				i++;
			}
			j ++; 
			if (i < input.size())
			{
				currentChar = input[i]; 
			}
		}
		return input.substr(0,j); 
	}

	static std::string reverseWords(std::string input)
	{
		int size = input.size(); 
		if (size == 0)
		{
			return ""; 
		}
		for (int i = 0; i < size/2; i++)
		{
			char temp = input[size - 1 - i]; 
			input[size - 1 - i] = input[i]; 
			input[i] = temp; 
		}
		int i = 0; 
		int j = 0; 
		for (int i = 0; i < size; i++)
		//while (i < size)
		{
			j = i; 
			while ((j < size) && (input[j] != (' ')))
			{
				j++; 
			}
			int subSize = j - i; 
			for (int k = i; k < i + subSize / 2; k++)
			{
				char temp = input[k]; 
				input[k] = input[2 * i + subSize - k - 1]; 
				input[2 * i + subSize - k - 1] = temp;  
			}
			i = j; 
		}
		return input; 
	}

		// find largest sum sub string
	static int largestSum(int arr[], int size)
	{
		// we scan from right to left, if the left element is smaller than the right next element, increase the running sum by the value of the left element. 
		// otherwise compare the running sum with the current largest sum, and store the larger of the two as the largest sum, and retart calculating the running surm. 
		// int size = sizeof(arr)/sizeof(int); 
		int runningSum = arr[size - 1]; 
		int largestSum = arr[size - 1]; 
		for (int i = size - 2; i >= 0; i--)
		{
			int temp = runningSum + arr[i]; 
			if (arr[i] > temp)
			{
				runningSum = arr[i];   
			}
			else
			{
				runningSum = temp; 
			}


			if (runningSum > largestSum)
			{
				largestSum = runningSum; 
			}
		}
		//return runningSum;
		return largestSum; 
	}

	static std::vector<int> stringToIntArray( char *line ) 
	{
		std::vector<int> result; 
		int num, i = 0, len;
		while ( sscanf( line, "%d%n", &num, &len) == 1 ) 
		{
			//printf( "Number %d is %d\n", i, num );
			result.push_back(num); 
			line += len;    // step past the number we found
			i++;            // increment our count of the number of values found
		}
		return result; 
	}

	static int largestRectangleArea(vector<int> &height) {
		stack<int> S;
		height.push_back(0);
		int result = 0;
		for (int i = 0; i < height.size(); ) {
			if (S.empty() || height[i] > height[S.top()]) {
				S.push(i);
				i++;
			} else {
				int tmp = S.top();
				S.pop();
				int width = S.empty() ? i : i - S.top() - 1;
				int area = height[tmp] * width;
				result = max(result, area);
			}
		}
		return result;
	}


	/// doesn't work, because my stack stores the height value not the height index. Index is needed to compute the width. 
	/// My way of computing width is wrong, it only works for monotonically ascending array. 
	static int largestRectangleAreaFeng(vector<int> &height) {
		stack<int> S;
		height.push_back(0);
		int result = 0;
		for (int i = 0; i < height.size(); i++) {
			if (S.empty() || height[i] >= S.top()) {
				S.push(height[i]);
			} else {
				int width = 1; 
				while ( !S.empty() && (S.top() > height[i]))
				{
					int height = S.top();
					int area = width * height; 
					width ++; 
					S.pop();
					result = result > area ? result:area; 
				}

			}
		}
		return result;
	}

	// parentheses
	static void DFS(int n, int l, int r, string s, vector<string> &result) {
		if (r == n) {
			result.push_back(s);
			return;
		}
		if (l < n) {
			DFS(n, l+1, r, s+"(", result);
		}
		if (r < l) {
			DFS(n, l, r+1, s+")", result);
		}
	}

	static vector<string> generateParenthesis(int n) {
		vector<string> result;
		DFS(n, 0, 0, "", result);
		return result;
	}



	static void generateParentheses(int n[], int l[], int r[], stack<char> s, string sol, vector<string> &res) {
		static const char leftP[] = "([{";
		static const char rightP[] = ")]}";
		bool ok = true;
		for (int i = 0; i < 3; i++) {
			if (r[i] < n[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << sol << endl;
			res.push_back(sol); 
			return; 
		}
    
		for (int i = 0; i < 3; i++) {
			if (l[i] < n[i]) {
				s.push(leftP[i]);
				l[i]++;
				generateParentheses(n, l, r, s, sol+leftP[i], res);
				s.pop();
				l[i]--;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (r[i] < l[i]) {
				if (s.top() == leftP[i]) {
					s.pop();
					r[i]++;
					generateParentheses(n, l, r, s, sol+rightP[i], res);
					s.push(leftP[i]);
					r[i]--;
				}
			}
		}
	}

	static void permuteString(string &s, int start, int length, vector<string> &result)
	{
	  if (start == length - 1)
	  {
		result.push_back(s); 
		return;   
	  }
	  for (int i = start; i < length; i++)
	  {
		swap(s, start, i); 
		permuteString(s, start+1, length, result); 
		swap(s, i, start); 
	  }
	}

	static void swap(string &s, int index1, int index2)
	{
	  char temp = s[index1]; 
	  s[index1] = s[index2];
	  s[index2] = temp; 
	}


	static vector<int> findDuplicates(vector<int> &a1, vector<int> &a2)
	{
		vector<int> result; 
		int size1 = a1.size(); 
		int size2 = a2.size();
		int i = 0; 
		int j = 0; 
		while ((i < size1) && (j < size2))
		{
			if (a1[i] < a2[j])
			{
				i++;
				continue; 
			}
			if (a1[i] > a2[j])
			{
				j++;
				continue; 
			}
			if (a1[i] == a2[j])
			{
				result.push_back(a1[i]);
				while (( i + 1 < size1) && (a1[i+1] == a1[i]))
				{
					i++; 
				}
				while (( j + 1 < size2) && (a2[j+1] == a2[j]))
				{
					j++; 
				}
				i++;
				j++; 
				continue;  
			}
			
			
		}
		return result; 
	}

	static void permuteParenthesis(int r, int l, int n, string currentStr, vector<string> &result)
	{
		if (r==n) 
		{
			result.push_back(currentStr); 
			return; 
		}
		if (r<l)
		{
			permuteParenthesis(r+1, l, n, currentStr +")", result); 
		}
		if (l<n)
		{
			permuteParenthesis(r, l+1, n, currentStr +"(", result); 
		}
		
	}



	// works. 
	static void permuteStringWithDuplicates(vector<char> &chars, vector<int> &currentCount,  vector<int> totalCount, string currentStr, vector<string> &result)
	{
		int size = chars.size(); 
		bool done = true; 
		for (int i = 0; i < size; i++)
		{
			if (currentCount[i] != totalCount[i] )
			{
				done = false; 
				break;
			}
		}

		if (done)
		{
			result.push_back(currentStr); 
			return; 
		}

		for (int i = 0; i < size; i++)
		{			
			if (currentCount[i] < totalCount[i])
			{
				currentCount[i]++;
				permuteStringWithDuplicates(chars, currentCount, totalCount, currentStr + chars[i], result); 
				currentCount[i]--; // this line is the key
			}
		}		
	}

	static void permuteStringWithDuplicatesParen(vector<char> &chars, vector<int> &currentCount,  vector<int> totalCount, string currentStr, vector<string> &result)
	{
		int size = chars.size(); 
		bool done = true; 
		for (int i = 0; i < size; i++)
		{
			if (currentCount[i] != totalCount[i] )
			{
				done = false; 
				break;
			}
		}

		if (done)
		{
			result.push_back(currentStr); 
			return; 
		}

		
		for (int i = 0; i < 1; i++)
		{			
			if (currentCount[i] < totalCount[i])
			{
				currentCount[i]++;
				permuteStringWithDuplicatesParen(chars, currentCount, totalCount, currentStr + chars[i], result); 
				currentCount[i]--; // this line is the key
			}
		}
		
		for (int i = 1; i < 2; i++)
		{			
			if (currentCount[i] < currentCount[i-1])
			{
				currentCount[i]++;
				permuteStringWithDuplicatesParen(chars, currentCount, totalCount, currentStr + chars[i], result); 
				currentCount[i]--; // this line is the key
			}
		}	
	}

	static void permuteStringWithDuplicatesParenMulti(vector<char> &chars, vector<int> &currentCount,  vector<int> totalCount, string currentStr, stack<char> S, vector<string> &result)
	{
		int size = chars.size(); 
		bool done = true; 
		for (int i = 0; i < size; i++)
		{
			if (currentCount[i] != totalCount[i] )
			{
				done = false; 
				break;
			}
		}

		if (done)
		{
			result.push_back(currentStr); 
			return; 
		}

		int halfSize = size / 2; 
		for (int i = 0; i < halfSize; i++)
		{			
			if (currentCount[i] < totalCount[i])
			{
				currentCount[i]++;
				S.push(chars[i]); 
				permuteStringWithDuplicatesParenMulti(chars, currentCount, totalCount, currentStr + chars[i], S, result); 
				S.pop(); 
				currentCount[i]--; // this line is the key
			}
		}
		
		for (int i = halfSize; i < size; i++)
		{			
			if (currentCount[i] < currentCount[i-halfSize])
			{
				if (S.empty()||(S.top() == chars[i-halfSize]))
				{
					currentCount[i]++;
					char a = S.top(); 
					S.pop(); 
					permuteStringWithDuplicatesParenMulti(chars, currentCount, totalCount, currentStr + chars[i], S, result); 
					S.push(a); 
					currentCount[i]--; // this line is the key
				}
			}
		}	
	}

	static void findAssignment(vector<int> &jobs, vector<vector<int>> &servers, int index, vector<vector<vector<int>>> &result) 
	{
		if (index == jobs.size())
		{
			result.push_back(servers); 
			return; 
		}
		for (int i = 0; i < servers.size(); i++)
		{
			servers[i].push_back(jobs[index]);
			findAssignment(jobs, servers, index + 1, result); 
			servers[i].pop_back(); 
		}
	}

	static struct node347
	{
		int x; 
		int y; 
		int z; 
		int val; 
		node347(int x_, int y_, int z_)
		{
			x = x_; 
			y = y_; 
			z = z_; 
			val = (int)(pow(3.0,x)*pow(4.0,y)*pow(7.0,z)); 
		} 
	};

	friend bool operator < (node347 a, node347 b)
	{
		return a.val > b.val;
	}

	// this doesn't work, because the de-duplication method is worng. Everytime in the while loop the local variables xNext, yNext, and zNext will be reallocated with a new address, storing 
	// their addresses in the hashtable has no meaning. 
	//find kth smallest 3^x*4^y*7^z
	static int findKthSmallest347_wrong(int k)
	{
		//unordered_set<int> visited; 
		unordered_set<node347 *> visited;
		priority_queue<node347 > heap; 
		int popCount = 0; 
		int result = 0; 
		heap.push(node347(1, 1, 1));
		node347 popped(0, 0, 0); 
		while (!heap.empty() && popCount<k)
		{
			popped = heap.top(); 
			//visited.insert(popped.val); 
			//visited.insert(&popped); 
			heap.pop(); 
			node347 xNext(popped.x + 1, popped.y, popped.z); 
			node347 yNext(popped.x, popped.y + 1, popped.z); 
			node347 zNext(popped.x, popped.y, popped.z + 1); 
			//if (visited.find(xNext.val) == visited.end())
			if (visited.find(&xNext) == visited.end())
			{
				heap.push(xNext);
				visited.insert(&xNext); 
			}
			//if (visited.find(yNext.val) == visited.end())
			if (visited.find(&yNext) == visited.end())
			{
				heap.push(yNext); 
				visited.insert(&yNext); 
			}
			//if (visited.find(zNext.val) == visited.end())
			if (visited.find(&zNext) == visited.end())
			{
				heap.push(zNext); 
				visited.insert(&zNext); 
			}
			popCount++; 
		}
		return popped.val; 
	}

	// this method won't compile because we need to define "==" operator and hash funtion for node347
	//static int findKthSmallest347_1(int k)
	//{
	//	unordered_set<node347 > visited;
	//	priority_queue<node347 > heap; 
	//	int popCount = 0; 
	//	int result = 0; 
	//	heap.push(node347(1, 1, 1));
	//	node347 popped(0, 0, 0); 
	//	while (!heap.empty() && popCount<k)
	//	{
	//		popped = heap.top();  
	//		heap.pop(); 
	//		node347 xNext(popped.x + 1, popped.y, popped.z); 
	//		node347 yNext(popped.x, popped.y + 1, popped.z); 
	//		node347 zNext(popped.x, popped.y, popped.z + 1); 
	//		if (visited.find(xNext) == visited.end())
	//		{
	//			heap.push(xNext);
	//			visited.insert(xNext); 
	//		}
	//		if (visited.find(yNext) == visited.end())
	//		{
	//			heap.push(yNext); 
	//			//visited.insert(yNext); 
	//		}

	//		if (visited.find(zNext) == visited.end())
	//		{
	//			heap.push(zNext); 
	//			//visited.insert(zNext); 
	//		}
	//		popCount++; 
	//	}
	//	return popped.val; 
	//}


	static int findKthSmallest347(int k)
	{
		unordered_set<int> visited; 
		//unordered_set<node347 *> visited;
		priority_queue<node347 > heap; 
		int popCount = 0; 
		int result = 0; 
		heap.push(node347(1, 1, 1));
		node347 popped(0, 0, 0); 
		while (!heap.empty() && popCount<k)
		{
			popped = heap.top(); 
			//visited.insert(popped.val); 
			heap.pop(); 
			node347 xNext(popped.x + 1, popped.y, popped.z); 
			node347 yNext(popped.x, popped.y + 1, popped.z); 
			node347 zNext(popped.x, popped.y, popped.z + 1); 
			if (visited.find(xNext.val) == visited.end())
			{
				heap.push(xNext);
				visited.insert(xNext.val); 
			}			
			if (visited.find(yNext.val) == visited.end())
			{
				heap.push(yNext);
				visited.insert(yNext.val);
			}
			if (visited.find(zNext.val) == visited.end())
			{
				heap.push(zNext);
				visited.insert(zNext.val);
			}
			popCount++; 
		}
		return popped.val; 
	}

	static int findLongestOnes(int a[], int size)
	{
		int *longest = new int[size]; 
		// base case
		longest[0] = (a[0] ==1? 1:0); 
		// scan the array, put the length of longest sequence of 1's that ends in the current location
		int maxCount = longest[0]; 
		for (int i = 1; i < size; i++)
		{
			if (a[i] == 1)
			{
				longest[i] = longest[i-1] + 1;
			}
			else
			{
				longest[i] = 0; 
			}
			if (longest[i] > maxCount)
			{
				maxCount = longest[i]; 
			}
		}
		delete[] longest; 
		return maxCount;		
	}

	static int findLongestOnesWithFlip(int a[], int size)
	{
		int *longest = new int[size]; 
		// base case
		longest[0] = (a[0] ==1? 1:0); 
		// scan the array, put the length of longest sequence of 1's that ends in the current location
		int maxCount = longest[0]; 
		for (int i = 1; i < size; i++)
		{
			if (a[i] == 1)
			{
				longest[i] = longest[i-1] + 1;
			}
			else
			{
				longest[i] = 0; 
			}
			if (longest[i] > maxCount)
			{
				maxCount = longest[i]; 
			}
		}
		// create a flippedLongest array, that stores the longest after flipping. 
		int *flippedLongest = new int[size]; 
		flippedLongest[0] = 1; 
		maxCount = flippedLongest[0]; 

		// second scan on the longest array, if we get a zero at i, assign longest[i-1] + 1 to this location
		for (int i = 1; i < size; i ++)
		{
			if (longest[i] == 0)
			{
				flippedLongest[i] = longest[i-1] + 1; 
			}
			else
			{
				flippedLongest[i] = flippedLongest[i-1] + 1; 
			}
			if (flippedLongest[i] > maxCount)
			{
				maxCount = flippedLongest[i]; 
			}
		}


		delete[] longest; 
		delete[] flippedLongest; 
		return maxCount;		
	}

	static int setBit(int input, int bit)
	{
		int mask = 1; 
		mask <<= bit; 
		return input |= mask; 
	}

	// assumption all characters are lower case

	static vector<string> findSubStr(string source, vector<char> chars)
	{
		vector<string> result; 
		// first convert chars into an integer, where bit 0-25 correspond to a-z, o(n)
		int charsBits = 0; 
		for (int i = 0; i < chars.size(); i++)
		{
			int bit = chars[i] - 'a';
			charsBits = setBit(charsBits, bit); 
		}
		// then find all the substrings of the source, o(s^2), convert substring to integer, o(1), overall o(s^2)
		for (int i = 0; i < source.length(); i++)
		{
			int bit = source[i] - 'a';
			int currSubStrBits = setBit(0, bit); 
			for (int j = i; j < source.length(); j++)
			{
				//update currSubStrBits with the incoming character
				bit = source[j] - 'a'; 
				currSubStrBits = setBit(currSubStrBits, bit); 
				// then compare the currSubStrBits with charsBits, if they equal, then its not valid, we can skip the rest of j
				if (currSubStrBits == charsBits)
				{
					break; 
				}
				else
				{
					result.push_back(source.substr(i, j - i + 1)); 
				}
			}
		}
		return result; 
		
	}

	static int fib(int n)
	{
		if ((n == 0) || (n ==1 ))
		{
			return n; 
		}
		int f0 = 0; 
		int f1 = 1; 
		int f2 = 1; 
		for (int i = 2; i <= n; i++)
		{
			f2 = f0 + f1; 
			f0 = f1; 
			f1 = f2; 
		}
		return f2; 

	}

	static int canJump (int A[], const int n) {
		vector<int> canGetToEnd(n, -1);
		//std::fill(canGetToEnd, canGetToEnd + n, -1); //initilize each item in the array to -1
		canGetToEnd[n - 1] = 0;// last step doesn't need to move
		for (int i = n - 2; i >= 0; i--) {
			int min_step = INT_MAX;
			for (int j = 1; j <= A[i]; j++) { //steps A[i] can move
				if (i + j >= n - 1) {// can move to the end directly
					min_step = 1; //jump once
					break;
				}
				if (canGetToEnd[i + j] != -1) { // reach some state can reach the end
					min_step = min(min_step, canGetToEnd[i + j] + 1);  
				}
			}
			canGetToEnd[i] = min_step;
		}
		return canGetToEnd[0];
	}

	static bool canJump1(int A[], const int n )
	{
		int minJump = 1; 
		for (int i = n - 1; i >= 0; i--)
		{
			if (A[i] < minJump)
			{
				minJump++;
			}
			else
			{
				minJump = 1; 
			}
		}
		return !(minJump > 1); 
	}


	static void swap(int &a, int&b)
	{
		int temp = a; 
		a = b; 
		b = temp; 
	}

	static int partition(int a[], int left, int right) {
		if (left == right) return left;
		//use the first item as pivot
		swap(a[left], a[right]);
		int i = left;
		int j = right - 1;
		while (i <= j) {
			if(a[i] <= a[right]) {
				i++;
			} else {
				swap(a[j--], a[i]);
			}
		}
		swap(a[i], a[right]);
		return i;
	}

	static int partition1(int a[], int left, int right) {
		if (left == right) return left;
		//use the first item as pivot
		//swap(a[left], a[right]);
		int i = left + 1;
		int j = right;
		while (i <= j) {
			if(a[i] <= a[left]) {
				i++;
			} else {
				swap(a[j--], a[i]);
			}
		}
		swap(a[left], a[j]);
		return j;
	}



	static void quickSort(int a[], int left, int right) {
		if (left >= right) return;
		int index_pivot = partition1(a, left, right);
		quickSort(a, left, index_pivot - 1);
		quickSort(a, index_pivot + 1, right);
	}

	// select the kth smallest element in an array
	static int quickSelect( int a[], int left, int right, int k)
	{
		int pivotIndex = partition1(a, left, right); 
		if (pivotIndex == k)
		{
			return a[k]; 
		}
		else if (pivotIndex < k)
		{
			return quickSelect(a, pivotIndex + 1, right, k); 
		}
		else
		{
			return quickSelect(a, left, pivotIndex - 1, k); 
		}
	
	}

	static void reverseWords2(string &s) {
      if (s.size()==0)
        {
            return;
        }
        // first reverse the entire string
       reverseString(s, 0, s.size() - 1); 
       // then reverse each word
       int writeStart = 0; 
	   int writeEnd = 0; 
	   int readStart = 0; 
       int readEnd = 0; 

	   int size = s.size(); 
	  
       while (readStart < size)
       {
		   // first put the start at the right place, skippin all leading ' 's. 
		   while ((readStart < size) && (s[readStart] == ' '))
		   {
			   readStart ++;
			   readEnd = readStart;
		   }
		   
		   // if this read is all space, break out of the loop, the previous wirteStart is the length of final string
		   if (readStart == size)
		   {
			   break;
		   }
		   
		   // read till we meet a space, readEnd is the last non space letter of this word 
           while (readEnd + 1 < s.size() && s[readEnd + 1]!=' ')
           {
               readEnd++; 
           }
		   int readLength = readEnd - readStart + 1;
		   // if it is not the first word, put a space in front
		   if (writeStart!=0)
		   {
			   s[writeStart] = ' '; 
			   writeStart++; 
		   }
		   
		   // copy the word from readStart to writeStart
		   memcpy(&s[writeStart], &s[readStart], readLength); 
		   writeEnd =  writeStart + readLength - 1;
		   
		   // reverse the word
           reverseString(s,writeStart, writeEnd);
           
           // move writeStart and readStart to one behind the end of word. 
		   writeStart = writeEnd + 1; 
		   readStart = readEnd + 1; 
       }
	   s = s.substr(0,writeStart);
       
       
    }
    
    static void reverseString(string &s, int start, int end)
    {
        int i = 0;
        int length = end - start + 1; 
        while (i < length/2)
        {
            char temp = s[start + i];
            s[start + i] = s[start + length - i - 1];
            s[start + length - i - 1 ] = temp;
            i++; 
        }
    
    }

	static vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int> result; 
        // hash all numbers, o(n)
        std::unordered_map<int,int> hashmap;
        int size = numbers.size();
        for (int i = 0; i < size; i++)
        {
            hashmap[numbers[i]] = i;
        }
        for (int i = 0; i < size; i++)
        {
            int rem = target - numbers[i]; 
            if (hashmap.find(rem)!=hashmap.end())
            {
				if (i!=hashmap[rem])
				{
					result.push_back(i+1);
					result.push_back(hashmap[rem]+1); 
					break;
				}
            }
        }
        return result; 
        
    }

	static vector<int> spiralOrder(vector<vector<int> > &matrix) 
    {
        
        vector<int> result; 
        int rows = matrix.size(); 
        if (rows == 0)
        {
            return result;
        }
        int cols = matrix[0].size(); 
        if (cols == 0)
        {
            return result;
        }
        spiralHelper(result, matrix, 0, 0,  rows - 1, cols - 1 ); 
        return result; 
    }

	        // recusion helper function
    static void spiralHelper(vector<int> &result, vector<vector<int> > matrix, int top, int left, int bottom, int right)
    {
        // handle current boundry
        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        for (int i = top + 1; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        if (bottom > top)
        {
            for (int i = right - 1; i >= left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
        }
        if (left < right)
        {
            for (int i = bottom - 1; i > top; i--)
            {
                result.push_back(matrix[i][left]); 
            }
        }
        
        if ((bottom - top < 2) || (right - left < 2))
        {
            return; 
        }
        else
        {
            // recurse to the next level
            spiralHelper(result, matrix, top + 1, left + 1, bottom - 1, right - 1); 
        
        }
    }

	static double powr(double x, int n) {
        
        if (n == 0)
        {
            return 1; 
        }
        int sign = n; 
        n = abs(n);
		int rem = n % 2;
        n /= 2;        
        double temp = powr(x,n);
        double result = 0; 
        if (rem == 0)
        {
            result = temp * temp; 
        }
        else if (rem == 1)
        {
            result = temp * temp * x; 
        }
        if (sign > 0)
        {
            return result;
        }
        else
        {
            return 1/result; 
        }
        
    }

	static double powr817(double x, int n) {
		if (n == 0)
		{
			return 1; 
		}
		int quo = n / 2; 
		int rem = n % 2;
		double temp = powr817(x, quo); 
		if (rem == 0)
		{
			return temp * temp; 
		}
		if (rem == 1)
		{
			return temp * temp * x; 
		}
		if (rem == -1)
		{
			return temp * temp * 1 / x; 
		}
        
    }

	// this may work, but n^n complexity. 
	static vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;  
        // recursion
        int size = s.size(); 
        if (size == 0)
        {
            return result; 
        }
        
        if (dict.find(s) != dict.end())
        {
            result.push_back(s);
            return result; 
        }
        //bool find = false; 
        for (int i = 1; i <= size; i++)
        {
            string firstWord = s.substr(0,i); 
            string sol = ""; 
            if (dict.find(firstWord)!=dict.end())
            {
                sol += (firstWord + " "); 
                vector<string> tempResults = wordBreak(s.substr(i, size - i), dict); 
                for (int t = 0; t < tempResults.size(); t++)
                {
                    result.push_back(sol + tempResults[t]); 
                }
                //find = true; 
            }
        }
        //if (!find)
        {
            return result; 
        }
    }

	static void findBreakPoints(string s, unordered_set<string> &dict, vector <int> &breakPoints, vector <vector<string>> &wordsAtPoints)
    {
        int size = s.size(); 
        // find the first point
        bool find = false; 
        for (int i = 1; i < size; i++)
        {
            if (dict.find(s.substr(0, i))!= dict.end())
            {
                breakPoints.push_back(i);
                vector<string> words; 
                words.push_back(s.substr(0, i)); 
                wordsAtPoints.push_back(words);
                find = true;
				break;
            }
        }
        if (!find)
        {
            return; 
        }
        // after the first point, extend based dp rule
        // for every i, 
        // 1. check if substr(0, i ) is valid, if yes, add to breakPoints, add to words
        // 2. check all the previous break points, if substr(breakPoint[j], i) is valid, add to breakPoints if 1 is false, add to words
        // 3. else this is not a vaild breakpoint
        for (int i = breakPoints[0]; i < size; i++)
        {
            find = false;
            vector<string> words; 
            if (dict.find(s.substr(0,i + 1))!=dict.end())
            {
                breakPoints.push_back(i+1);
                words.push_back(s.substr(0, i + 1)); 
                find = true;
            }
            for (int j = breakPoints.size() - 1; j >= 0 ; j-- )
            {
                string temp = s.substr(breakPoints[j], i - breakPoints[j] + 1); 
                if (dict.find(temp) != dict.end())
                {
                    if (!find)
                    {
                        breakPoints.push_back(i + 1); 
                        find = true; 
                    }
                    words.push_back(temp); 
                }
            }
			if (find)
			{
				wordsAtPoints.push_back(words); 
			}

        }
    }

	static void printAll(vector <string> &result, vector<vector<string>> &wordsAtI, int i, string sol)
    {
        if (i == 0)
        {
			// remove the last " "
			
			result.push_back(sol.substr(0,sol.size()-1)); 
            return; 
        }
        vector <string> words = wordsAtI[i]; 
        int size = words.size(); 
        for (int j = 0; j < size; j++)
        {
            int length = words[j].size(); 
            printAll(result, wordsAtI, i-length + 1, words[j] + " " + sol); 
        }
    }

	static   vector<string> wordBreak2(string s, unordered_set<string> &dict) 
    {
        int size = s.size(); 
        // first use dp to find all possible words ending at index i
        vector <string> temp; 
        vector <vector<string>> wordsAtI(size + 1, temp); 
        wordsAtI[0].push_back("a"); 
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <= i; j ++)
            {
                string tempS = s.substr(j, i - j + 1); 
                if (dict.find(tempS) != dict.end())
                {
                    wordsAtI[i + 1].push_back(tempS); 
                }
            }
        }
        
        vector<string> result; 
		string sol = ""; 
        printAll(result, wordsAtI, size, sol); 
        return result; 
    }

	// recursion helper
    static void genHelper(TreeNode *tree, TreeNode *cur, vector<TreeNode *> &result, unordered_set<int> &nums, int n)
    {
        if (nums.size() == 0)
        {
            result.push_back(tree);
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (nums.find(i) != nums.end())
            {
               nums.erase(i); 
               TreeNode *newNode = new TreeNode(i); 
               // resurse
               if (cur->val > i)
               {
                   cur->left = newNode; 
                   genHelper(tree, cur->left, result, nums, n); 
               }
               else
               {
                   cur->right = newNode;
                   genHelper(tree, cur->right, result, nums, n); 
               }
               nums.insert(i);
            }
        }
    }

    static vector<TreeNode *> generateTrees(int n) {
        unordered_set<int> nums; 
        for (int i = 1; i<=n; i++)
        {
            nums.insert(i); 
        }
        vector<TreeNode *> result;
        for (int i = 1; i <= n; i++)
        {
            nums.erase(i);
            TreeNode *newNode = new TreeNode(i);
			TreeNode *cur = newNode; 
            genHelper(newNode, cur, result, nums, n); 
            nums.insert(i);
        }
        return result; 
        
    }

	  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
	 };
    
    static   ListNode *partition(ListNode *head, int x) 
    {
       if (head == NULL)
        {
            return NULL; 
        }
        // use two pointer pointing to the current location of left portion and right portion
        ListNode *left = NULL; 
        ListNode *right = NULL;
        // cur is the moving pointer
        ListNode *cur = head;
        
        ListNode *leftHead = NULL; 
        ListNode *rightHead = NULL; 
        while (cur!= NULL)
        {
            if (cur->val < x)
            {
                // check if leftHead is found yet
                if (leftHead == NULL)
                {
                    leftHead = cur;
                    left = cur; 
                }
                else
                {
                    left->next = cur;
                    left = cur;
                }
                
            }
            else
            {
                if (rightHead == NULL)
                {
                    rightHead = cur;
                    right = cur;
                }
                else
                {
                    right->next = cur;
                    right = cur;
                }
            }
            cur = cur->next;
        }
        if (leftHead!=NULL)
        {
            left->next = rightHead;
        }
        else
        {
            leftHead = rightHead; 
        }
		if (right != NULL)
		{
			right->next = NULL; 
		}
        return leftHead; 
        
    }

	static void shiftRight(string &input, int i, int j)
	{
		if (i != j)
		{
			//string a = input.substr(10, 0); 
			// not checking (j + 1 < input.size()) also works because max of j + 1 is input.size(), in this case j+1 = "\0" the ending of a string
			input = input.substr(0,i) + input[j] + input.substr(i,j-i) +input.substr(j + 1, input.size() - j - 1);  //((j + 1 < input.size())?input.substr(j + 1, input.size() - j - 1): "");
		}
	}

	static void shiftLeft(string &input, int i, int j)
	{
		if (i != j)
		{
			input = input.substr(0,i) + input.substr(i + 1,j-i) + input[i] + ((j + 1 < input.size())?input.substr(j + 1, input.size() - j - 1): ""); 
		}
	}
	/*static void shiftLeft(string &input, int i, int j)
	{
		if (i != j)
		{
			input = input
		}
	}*/
	

    static void permute(string &input, int start, int &cur, int k, string &result)
    {
        int size = input.size(); 
        if (start == size)
        {
            cur++; 
            if (cur == k)
            {
                result = input;  
            }
            return;
        }
        for (int i = start; i < size; i++)
        {
			//string temp = input; 
            shiftRight(input, start, i); 
            permute(input, start + 1, cur, k, result);
            if (result!="")
            {
                return;
            }
			shiftLeft(input, start, i); 
            //input = temp; 
        }
    }
    
    static string getPermutation(int n, int k) {
        string result = ""; 
        string input = "123456789";
        input = input.substr(0,n);
        int cur = 0; 
        permute(input, 0, cur, k, result); 
        return result; 
        
    }
	static vector<int> factorials(int n)
	{
		vector<int> result;
		result.push_back(1);
		for (int i = 1; i <= n; i++)
		{
			result[i] = result[i-1]*i;
		}
		return result;
	}

	// not work, incomplete
	static string getPermutation2(int n, int k) {
		string result = ""; 
        vector<int> factos = factorials(n); 
		if (k > factos[n])
		{
			return result; 
		}
		int digits[10];
		for (int i = 0; i< 10; i++)
		{
			digits[i] = 0; 
		}
		int rem = k; 
		for (int i = n ; i >= 1; i--)
		{
			digits[i] = rem / factos[i];
			rem = rem % factos[i]; 
			if (rem == 0)
			{
			}
		}
        
    }

	static string getPermutation3(int n, int k)
	{
           vector<int> nums(n);  
           int permCount =1;  
           for(int i =0; i< n; i++)  
           {  
                nums[i] = i+1;  
                permCount *= (i+1);        
           }  
           // change K from (1,n) to (0, n-1) to accord to index  
            k--;  
            string targetNum;  
            for(int i =0; i< n; i++)  
            {    
                 permCount = permCount/ (n-i);  
                 int choosed = k / permCount;  
                 targetNum.push_back(nums[choosed] + '0');  
                 //restruct nums since one num has been picked  
                 for(int j =choosed; j< n-i-1; j++)  
                 {  
                      nums[j]=nums[j+1];  
                 }  
                 k = k%permCount;  
            }  
            return targetNum; 
	}
	    
	static int factorial(int n)
     {
         int res = 1;
         for(int i = 2; i <= n; i++)
             res *= i;
         return res;
     }

	static string getPermutation4(int n, int k) {
         int total = factorial(n);
         string candidate = string("123456789").substr(0, n);
         string res(n,' ');
         for(int i = 0; i < n; i++)//依次计算排列的每个位
         {
             total /= (n-i);
             int index = (k-1) / total;
             res[i] = candidate[index];
             candidate.erase(index, 1);
             k -= index*total;
         }
         return res;
     }

	static void walk(int x, int y, int m, int n, int &count)
	{
		if ((x == m -1) && (y == n - 1))
		{
			count++; 
			return; 
		}
		if (x <= m -2)
		{
			walk(x + 1, y, m, n, count);
		}
		if (y <= n - 2)
		{
			walk(x, y + 1, m, n, count); 
		}

	}

	static int walkDP(int m, int n)
	{
		if ((m == 1) || (n == 1))
		{
			return 1; 
		}
		vector<vector<int>> dp(m, vector<int>(n,0)); 
		for (int i = 0; i < m ; i++)
		{
			dp[i][0] = 1; 
		}
		for (int i = 0; i < n; i++)
		{
			dp[0][i] = 1; 
		}
		dp[0][0] = 0; 
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
			{
				dp[i][j]= dp[i-1][j] + dp[i][j-1]; 
			}
		return dp[m-1][n-1]; 
	}

	static int walkDP2(int m, int n)
	{
		if ((m == 1) || (n == 1))
		{
			return 1; 
		}
		int minD = min(m, n);
		int maxD = max(m, n); 
		vector<int> dp(minD, 0); 
		for (int i = 1; i < minD ; i++)
		{
			dp[i]= 1; // base case
		}
		for (int j = 1; j < maxD; j++)
		{
			dp[0] = 1; 
			for (int i = 1; i < minD; i++)
			{
				 dp[i] = dp[i-1] + dp[i]; 
			}
		}
		
		return dp[minD - 1]; 
	}

	// longest increasing sequence
	static vector<int> LIS(vector<int> input)
	{
		int longest = 0; 
		int size = input.size(); 
		vector<int> res; 
		vector<int> curSub; 
		for (int i = 0; i < size; i++)
		{
			int subCount = 0; 
			curSub.clear(); 
			curSub.push_back(input[i]); 
			for (int j = i + 1; j < size; j++)
			{
				if (input [j] >= curSub.back())
				{
					subCount++;
					curSub.push_back(input[j]); 
				}
			}
			if (subCount > longest)
			{
				res = curSub; 
				longest = subCount; 
			}
			if (size - i < longest)
			{
				break; 
			}
		}
		return res;
	}

	static vector<string> restoreIpAddresses(string s) {
        vector<string> result; 
        int size = s.size(); 
        if (size == 0)
        {
            return result; 
        }
        vector<string> IP; 
        dfs(result, s, IP);
        return result;
    }
    
    static void dfs(vector<string> &result, string &s, vector<string> &IP)
    {
        if (IP.size() == 4 )
        {
			if (s.size() == 0)
			{
				string sol= "";
				for (int i = 0; i < 3; i++)
				{
					sol += IP[i] + "."; 
				}
				sol += IP[3]; 
				result.push_back(sol); 
			}
			return;
        }
		int size = s.size(); 
		int boundary = (size > 3) ? 3 : size; 
        for (int i = 1; i <= boundary; i++)
        {
            string temp = s.substr(0, i);
            int field = stoi(temp); 
            if ((field>=0) && (field<=255))
            {
                IP.push_back(temp);
				dfs(result, s.substr(i, size - i), IP);
				IP.pop_back(); 
            }
        }
    }

static int countCoins( std::vector<int> s, int n )
{
  std::vector<int> table(n+1,0);

  table[0] = 1;
  for each (int k in s )
    for(int j=k; j<=n; ++j)
      table[j] += table[j-k];

  return table[n];
}


static void findCombinations(vector<int> &coins, int money, int index, 
                      vector<int> &solution, int &count, int &o) {
    int n = coins.size();
	o++; 
    if (index == n) {
        count++;
        for (int i = 0; i < n; i++) {
            cout << solution[i] << "*" << coins[i] << " ";
        }
        cout << endl;
        return;
    }
    if (index == n - 1) {
        if (money % coins[index] == 0) {
            solution[index] = money/coins[index];
            findCombinations(coins, 0, index+1, solution, count, o);
        }
    } else 
	{
        for (int i = 0; i*coins[index] <= money; i++) {
            solution[index] = i;
            findCombinations(coins, money-i*coins[index], index+1, solution, count, o);
        }
    }
}

static void findCombinations2(vector<int> &coins, int money, int index, 
                      vector<int> &solution, int &count, int &o) {
    int n = coins.size();
	o++; 
    if (index == n) {
		if (money % coins[index] == 0) 
		{
            solution[index] = money/coins[index];
			count++;
			for (int i = 0; i < n; i++) {
				cout << solution[i] << "*" << coins[i] << " ";
			}
			cout << endl;
		}
        return;
    }
/*    if (index == n - 1) {
        if (money % coins[index] == 0) {
            solution[index] = money/coins[index];
            findCombinations(coins, 0, index+1, solution, count, o);
        }
    } else*/ 
	{
        for (int i = 0; i*coins[index] <= money; i++) {
            solution[index] = i;
            findCombinations(coins, money-i*coins[index], index+1, solution, count, o);
        }
    }
}

static vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result; 
        if (n <= 0)
        {
            return result; 
        }
        vector<bool> col(n,false); 
        vector<bool> r(n * 2 - 1, false); 
        vector<bool> l(n * 2 - 1, false);
        vector<string> sol; 
        dfsNQueen(result, sol, 0, n, col, r, l); 
        return result; 
        
    }
static void dfsNQueen(vector<vector<string>> &result, vector<string> sol, int row, int n, vector<bool> &col, vector<bool> &r, vector<bool> &l)
    {
        if (row == n)
        {
            result.push_back(sol); 
            return; 
        }
        string sStart = ""; 
        for (int i = 0; i < n; i++)
        {
            sStart +='.'; 
        }
        for (int i = 0; i < n; i++)
        {
            if (!col[i] && !r[i - row - 1 + n ] && !l[i + row])
            {
                string temp = sStart; 
                sStart[i] = 'Q'; 
                col[i] = true;
                r[i - row - 1 + n ] = true;
                l[i + row ] = true;
                sol.push_back(temp); 
                dfsNQueen(result, sol, row + 1, n, col, r, l); 
                sol.pop_back();
                l[i + row ] = false;
                col[i] = false;
                r[i - row - 1 + n ] = false;
            }
        }
    }

static vector<string> letterCombinations(string digits) 
    {
        vector<string> result; 
        if (digits == "")
        {
            return result;
        }
        string sol = ""; 
        combine(0, digits.size(), digits, sol, result); 
        return result; 
        
    }
    
    
static void combine(int index, int n, string digits, string sol, vector<string> &result)
    {
		string lut[] =  { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        if (index == n)
        {
            result.push_back(sol); 
            return; 
        }
        int num = digits[index] - '0'; 
        if (num == 1)
        {
            combine(index + 1, n, digits, sol, result);
        }
        else
        {
            string s = lut[num];
            int size = s.size(); 
            for (int i = 0; i < size; i++)
            {
                combine(index + 1, n, digits, sol + s[i], result);
            }
        }
    }

static vector<string> letterCombinations2(string digits) {
        vector<string> res(1,"");
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.size(); i++)
        {
            vector<string>tmp;
            for(int j = 0; j < res.size(); j++)
                for(int k = 0; k < numap[digits[i] - '0'].size(); k++)
                    tmp.push_back(res[j] + numap[digits[i] - '0'][k]);
            res = tmp;
        }
         
        return res;
    }

static void swap (int A[], int i, int j)
    {
        int temp = A[i]; 
        A[i] = A[j]; 
        A[j] = temp; 
    }
    
static void sortColors(int A[], int n) 
    {
        int i0 = 0; 
        int i2 = n - 1; 
        int i = 0; 
        while (i <= i2)
        {
            if (A[i] == 0)
            {
                swap(A, i, i0); 
                i0++; 
                i++; 
            }
            else if (A[i] == 2)
            {
                swap(A, i, i2); 
                i2--; 
            }
            else
            {
                i++; 
            }
        }
        
    }


// this is not the best answer, it doesn't handle large number overflow problem. 
static vector<int> plusOne(vector<int> &digits) {
        vector<int> result; 
        int n = digits.size(); 
        if (n == 0)
        {
            return result;
        }
        // convert to integer first
        int num = 0; 
        int unit = 1; 
        for (int i = 0; i < n; i++)
        {
            num = num * 10 + digits[i]; 
            unit*=10; 
        }
        num += 1; 
        if (num / unit != 1)
        {
            unit/=10; 
        }
        
        
        while (unit > 0)
        {
            int q = num / unit; 
            num = num % unit; 
            result.push_back(q); 
            unit /= 10; 
        }
        return result; 
    }

static  vector<int> plusOne2(vector<int> &digits) {  
     // Start typing your C/C++ solution below  
     // DO NOT write int main() function  
     int cary=1, sum =0;  
     vector<int> result(digits.size(),0);  
     for(int i = digits.size()-1; i>=0; i--)  
     {        
       sum = cary+digits[i];  
       cary = sum/10;  
        result[i] = sum%10;  
      }  
      if(cary >0)  
      {  
        result.insert(result.begin(), cary);  
      }  
      return result;  
    }

static  int ladderLength(string start, string end, unordered_set<string> &dict) {
        // use BFS,
        // 0. in order to search by layer, need to for loop the number of words in current queque. 
        // 1. for the starting string, do two for loops, for curChar 0:length, for char 'a':'z' except the the curChar, find the word in dict, 
        // 2. if found, compare with end, if yes, return layer, 
        // 3. if no, remove the word from dict, the word push to queue, search the next word of this layer, until the for loop returns, mark the length of the current queue, which is the number of words in the next layer. 
        queue<string> q;
        q.push(start); 
        int layer = 0; 
        while (!q.empty())
        {
            // bfs by layer
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string word = q.front(); 
                // check if we can find a word in the dict by changing only one char
                q.pop(); 
                for (int j = 0; j < word.size(); j++)
                {
                    for (char c = 'a'; c < 'z'; c++)
                    {
                        string newWord = word; 
                        newWord[j] = c; 
                        if (dict.find(newWord) != dict.end())
                        {
                            dict.erase(newWord); 
                            q.push(newWord);
                            if (newWord == end)
                            {
                                return layer + 1; 
                            }
                        }
                    }
                }
            }
            layer++; 
        }
    }

static bool isMatch(const char *s, const char *p) {  
    bool star = false; 
    const char *str, *ptr; 
    for (str = s, ptr = p; *str != '\0'; str++, ptr++)
    {
        switch (*ptr)
        {
            case '?':
                break;
            case '*':
                star = true;
                s = str; 
                p = ptr; 
                while (*p == '*')
                {
                    p++; 
                }
                if (*p == '\0')
                {
                    return true;
                }
                str = s - 1; 
                ptr = p - 1; 
                break;
            default:
                if (*ptr != *str)
                {
                    if(!star)
                    {
                        return false;
                    }
                    s++; 
                    str = s - 1; 
                    ptr = p - 1; 
                }
        }
    
    }
    while (*ptr == '*')
    {
        ptr++; 
    }
    return (*ptr == '\0');
}


static string multiply(string num1, string num2) {
        string result = "";
        int n1 = num1.size(); 
        int n2 = num2.size(); 
        int k = n1 - 1 + n2 - 1; 
        vector <int> temp(n1 + n2, 0); 
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < n2; j++)
            {
                temp[k - i - j] += (num1[i] - '0') * (num2[j] - '0'); 
            }
        int carry = 0;
        for (int i = 0; i < n1 + n2; i++)
        {
            temp[i] += carry;
            carry = temp[i] / 10; 
            temp[i] = temp[i] % 10; 
        }
        
        int i = k + 1; 
        while ((i >= 0)&&(temp[i] == 0))
        {
            i--; 
        }
        if (i < 0)
        {
            return "0"; 
        }
        for (; i>=0; i--)
        {
            //result.push_back(temp[i] + '0'); 
			result += 50; //(temp[i] + '0');
        }
        return result; 
        
    }

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool comp(Interval a, Interval b)
    {
        return a.start < b.start; 
    }
static vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty())
        {
            return intervals; 
        }
        sort(intervals.begin(), intervals.end(), comp);
        auto it1 = intervals.begin(); 
        auto it2 = it1 + 1; 
        while (it1 != intervals.end() && it2 != intervals.end())
        {
            if (it2->start <= it1->end)
            {
                if (it2->end <= it1->end)
                {
                    it2++; 
                }
                else
                {
                    it1->end = it2->end;
                    it1 = intervals.erase(it1 + 1, it2 + 1);
					if (it1 != intervals.end())
					{
						it2 = it1 + 1; 
					}
                }
            }
            else
            {
                it1++; 
                it2++; 
            }
        }
        if (it1 != intervals.end())
        {
            intervals.erase(it1 + 1, it2); 
        }
        return intervals; 
    }


static void generateSub(  
      vector<int> &s,   
      int step,   
      vector<vector<int> > &result,  
      vector<int>& output, int &count)  
    { 
	  count++; 
      for(int i = step;i<s.size(); i++ )  
      {  
        output.push_back(s[i]);  
        result.push_back(output);  
        //if(i< s.size()-1)  
          generateSub(s, i+1, result, output, count);  
        output.pop_back();  
      }  
    }  

static vector<vector<int> > subsets(vector<int> &S, int &count) {  
     // Start typing your C/C++ solution below  
     // DO NOT write int main() function 
	count = 0; 
     vector<vector<int> > result;  
     vector<int> output;      
     if(S.size() ==0) return result;  
     result.push_back(output);  
     sort(S.begin(), S.end());  
     generateSub(S, 0, result, output, count);  
	 return result; 
    }
static   void dfs_subset2(vector<vector<int>> &res, vector<int> &S, int iend, vector<int> &tmpres, int &count)
   {
	   count++; 
       if(iend == S.size())
           {res.push_back(tmpres); return;}
       //选择S[iend]
       tmpres.push_back(S[iend]);
       dfs_subset2(res, S, iend+1, tmpres, count);
       tmpres.pop_back();
       //不选择S[iend]
       dfs_subset2(res, S, iend+1, tmpres, count);
   }
static  vector<vector<int> > subsets2(vector<int> &S, int & count) {
       // IMPORTANT: Please reset any member data you declared, as
       // the same Solution instance will be reused for each test case.
       //先排序，然后dfs每个元素选或者不选，最后叶子节点就是所有解
	   vector<vector<int>> res; 
       res.clear();
       sort(S.begin(), S.end());
       vector<int>tmpres;
       dfs_subset2(res, S, 0, tmpres, count);
       return res;
   }

static vector<vector<int> > subsets3(vector<int> &S, int &count) {
     // IMPORTANT: Please reset any member data you declared, as
     // the same Solution instance will be reused for each test case.
     int len = S.size();
     sort(S.begin(), S.end());
     vector<vector<int> > res(1);//开始加入一个空集
	 //int count = 0; 
     for(int i = 0; i < len; ++i)
     {
         int resSize = res.size();
         for(int j = 0; j < resSize; j++)
         {
             res.push_back(res[j]);
             res.back().push_back(S[i]);
			 count++; 
         }
     }
     return res;
 }

static void dfs_combinationSum(int target, int start, int n, vector<int> &c, vector<int> &t, int &sum, vector<vector<int>> &res)
{
  for (int i = start; i < n; i++)
  {
      if (!(i > start && (c[i] == c[i-1])))
      {
        if (sum < target)
    	{
    	  t.push_back(c[i]); 
    	  sum += c[i]; 
    	  dfs_combinationSum(target, i + 1, n, c, t, sum, res); 
    	  sum -= c[i]; 
    	  t.pop_back(); 
    	}
    	else if (sum == target)
    	{
    		res.push_back(t);
    	    return; 
    	}
    	else
    	{
    		return; 
    	}
      }
  }
}

static vector<vector<int> > combinationSum2(vector<int> &candidates, int target) 
    {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> result; 
        int n = candidates.size(); 
        if ( n == 0)
        {
            return result; 
        }
        vector<int> t; 
        int sum = 0; 
        dfs_combinationSum(target, 0, n, candidates, t, sum, result); 
        return result; 
        
    }

static string addBinary(string a, string b) {
	std::reverse(a.begin(), a.end()); 
	std::reverse(b.begin(), b.end()); 
        string res = ""; 
        int n1 = a.size(); 
        int n2 = b.size(); 
        if (n1 == 0 || n2 == 0)
        {
            return ""; 
        }
        int n = max(n1, n2);
        int n0 = min(n1, n2); 
        res = n == n1 ? a : b; 
        char carryBit = '0'; 
        for (int i = 0 ; i < n0; i++)
        {
			char aa = a[i]; 
			char bb = b[i]; 
			char c = carryBit; 
            int k = (a[i] - '0') + (b[i] - '0') + (carryBit - '0');
            carryBit = k / 2 + '0'; 
            res[i] = (k % 2) + '0'; 
        }
        if (carryBit == '0')
        {
			reverse(res.begin(), res.end()); 
            return res; 
        }
        
        for (int i = n0; i < n ; i++)
        {
            if (carryBit == '0')
            {
                break;
            }
            int k = ((n1 == n ? a[i] : b[i]) - '0') + (carryBit - '0');
            carryBit = k / 2 + '0'; 
            res[i] = (k % 2) + '0'; 
        }
      

        if (carryBit == '1')
        {
            res += '1'; 
        }
        reverse(res.begin(), res.end()); 
        return res; 
    }

static   int numTrees(int n) {
        vector<int> dp(n+1, 0); 
        dp[0] = 1; 
        for (int i = 1; i <= n; i ++)
        {
            int temp = 0; 
            for (int j = 1; j <= i / 2; j++)
            {
                temp += dp[j - 1]*dp[i-j] * 2; 
            }
            if (i % 2 != 0)
            
            {
                temp += dp[(i - 1)/2] * dp[(i - 1)/2]; 
            }
            dp[i] = temp; 
        }
        return dp[n]; 
    }

static int numTrees2(int n) {
        vector<int> dp(n+1, 0); 
        dp[0] = 1; 
        for (int i = 1; i <= n; i ++)
        {
            int temp = 0; 
            for (int j = 1; j < (i + 1) / 2 ; j++)
            {
                temp += dp[j-1]*dp[i-j]*2; 
            }
            if (i % 2 != 0)
            {
                temp += dp[i/2 ]*dp[i/2]; 
            }
			else
			{
				temp +=  dp[i/2 -1 ]*dp[i/2]*2;
			}
            dp[i] = temp; 
        }
        return dp[n]; 
    }

static vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res; 
        if (root == NULL)
        {
            return res;
        }
        stack<TreeNode *> s; 
        //s.push(root);
        TreeNode *p = root; 
        while(p || !s.empty()) // p|| is for the beginning to enter the while loop
        {
           while (p)
           {
               s.push(p); 
               p = p->left; 
           }
           //if (!s.empty()) // this is for the end, p has 
           {
               p = s.top(); 
               res.push_back(p->val); 
               s.pop();
               p= p->right; 
           }
        }
		return res; 
        
    }

static    long long comb(int a, int b)
    {
        long long res = 1; 
        if (b > a / 2)
        {
            b = a - b; 
        }
        for (int i = 1; i <= b; i++)
        {
            res = res * (a - i + 1) / i; 
        }
        return res; 
    }

    
static    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1)
        {
            return 0; 
        }
        return comb(m + n - 2, n - 1); 
    }

static   bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // binary search, 1D k = 0, ... m*n-1, i = k / n, j = k % m; 
        int m = matrix.size(); 
        if (m == 0) return false;  
        int n = matrix[0].size(); 
        int start = 0; 
        int end = m * n - 1; 
        int mid = start + (end - start) / 2; 
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            int midVal  = matrix[mid/n][mid%n]; 
            if (midVal == target)
            {
                return true;
            }
            if (midVal > target)
            {
                end = mid - 1; 
            }
            else
            {
                start = mid + 1; 
            }
        }
        return false; 
    }

 static   ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
        {
            return head; 
        }
        // first detect cycle using fast slow pointers, mark the point they first met
        // loop until they meet again and mark the number of steps, this is the lenth of circle
        // then set two pointers, one at 0, the other at length of circle, traverse until these two pointers meet, 
        // the meeting point is the beginning of circle. 
        ListNode *fp = head; 
        ListNode *sp = head; 
        int loop = 0; // a loop has at least two nodes. 
        int meetTime = 0; 
        while (fp!=NULL && fp->next != NULL)
        {
            sp = sp->next; 
            fp = fp->next->next;
            if (meetTime == 1)
            {
                loop++; 
            }
            if (sp == fp)
            {
                meetTime++; 
                if (meetTime == 2)
                {
                    break; 
                }
            }
        }
        if (meetTime == 0)
        {
            return NULL; 
        }
        
        sp = head; 
        fp = head; 
        for (int i = 0; i < loop; i++)
        {
            fp = fp->next; 
        }
        
        while (sp != fp)
        {
            sp = sp->next; 
            fp = fp->next; 
        }
        return sp; 
        
    }

static     vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0)); 
        if (n == 0)
        {
            return res; 
        }
        int val = 1; 
        helper(0, n, val, res); 
        return res; 
    }
    
static    void helper(int layer, int n, int &val, vector<vector<int>> &res)
    {
        // base case
        int size = n - 2 * layer; // the matrix size of this recursion
        if (size == 0)
        {
            return;
        }
        if (size == 1)
        {
            res[layer][layer] = val;
            return;
        }
        // top
        for (int i = 0; i < size; i++)
        {
            res[layer][layer + i] = val; 
            val++; 
        }
        // right
        for (int i = 1; i < size; i++)
        {
            res[layer + i][layer + size - 1] = val; 
            val++;
        }
        // bottom
        for (int i = size - 2; i >= 0; i--)
        {
            res[layer + size - 1][layer + i] = val;
            val++; 
        }
        // left
        for (int i = size - 2; i >= 1; i--)
        {
            res[layer + i][layer] = val; 
            val++; 
        }
        
        // recurse
        helper(layer + 1, n, val, res); 
    }


static    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
        {
            return false;
        }
        return dfsPathSum(root, sum); 
    }
    
 static   bool dfsPathSum(TreeNode *root, int sum)
    {
       if (root == NULL)
        {
            return false; 
        }
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == root->val)
            {
                return true;
            }
            return false;
        }
        if (dfsPathSum(root->left, sum - root->val))
        {
            return true;
        }
        if (dfsPathSum(root->right, sum - root->val))
        {
            return true;
        }
        return false; 
    }

static  int search(int A[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l)/2;
        if (A[m] == key) return m; //return m in Search in Rotated Array I
        if (A[l] < A[m]) { //left half is sorted
            if (A[l] <= key && key < A[m])
                r = m - 1;
            else
                l = m + 1;
        } else if (A[l] > A[m]) { //right half is sorted
            if (A[m] < key && key <= A[r])
                l = m + 1;
            else
                r = m - 1;
        }
		else
		{
			l++; 
		}
    }
    return -1;
    }


static int lengthOfLastWord(const char *s) {
      if (s[0] == NULL)
      {
          return 0; 
      }
      int i = 0; // the index of the beginning of current word
      int j = 0; // the index of end of the word + 1
      int prev_i = 0; 
      while (s[i]!='\0')
      {
          while (s[i] == ' ' && s[i] != '\0')
          {
              i++;
          }
          if (s[i] == '\0')
          {
              return j - prev_i; 
          }
          j = i; 
          while (s[j] != ' ' && s[j] != '\0')
          {
              j++;
          }
          if (s[j] == '\0')
          {
              return j - i; 
          }
          prev_i = i; 
          i = j; 
      }
      
    }
static    bool isPalindrome(int x) {
	    if (x < 0)
		{
			return false; 
		}
        int unit = 1;
        int quo = x; 
        while (quo >= 10)
        {
			quo /= 10; 
            unit *= 10; 
        }
        quo = x; 
        while (quo > 0)
        {
            int l = quo / unit; 
            int r = quo % 10; 
            if (l != r)
            {
                return false; 
            }
            quo = (quo % unit) / 10; 
            unit /= 100; 
        }
        return true; 
    }
 static   bool isValidParentheses(string s) {
        int size = s.size(); 
        if (size == 0)
        {
            return true; 
        }
        unordered_map <char, char> hash; 
        hash[')'] = '('; 
        hash[']'] = '['; 
        hash['}'] = '{';
        stack<char> st; 
        
        for (int i = 0; i < size; i ++)
        {
            if (hash.find(s[i]) == hash.end()) // left paren
            {
                st.push(s[i]); 
            }
            else // right
            {
                if (st.empty() || st.top() != hash[s[i]])
                {
                    return false; 
                }
                st.pop(); 
            }
        }
        if (!st.empty())
        {
            return false; 
        }
        return true; 
    }

static    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res; 
        if (root == NULL)
        {
            return res; 
        }
        vector<int> tempRes; 
        dfs(root, sum, tempRes, res); 
        return res; 
    }
    
static    void dfs(TreeNode *root, int remain, vector<int> &tempRes, vector<vector<int>> &res)
    {

        if (root == NULL)
        {
            return; 
        }
        if (remain == root->val && root->left == NULL && root->right == NULL)
        {
            tempRes.push_back(root->val); 
            res.push_back(tempRes); 
            tempRes.pop_back(); 
            return; 
        }
        tempRes.push_back(root->val); 
        dfs(root->left, remain - root->val, tempRes, res); 
        dfs(root->right, remain - root->val, tempRes, res); 
        tempRes.pop_back(); 
    }

static     string countAndSay(int n) {
        if (n == 1)
        {
            return "1"; 
        }
        int res = 1; 
        for (int i = 2; i <= n; i++)
        {
            res = next(res); 
        }
        return to_string((long long)res); 
    }
    
static    int next(int num)
    {
        int output = 0; 
        int unit = 1; 
        int quo = num; 
        int rem;
        int prev = 1; 
        int count = 0; 
        while (quo >= 0)
        {
            if (quo == 0)
            {
                output += (count * 10 + prev) * unit;
                break;
            }
            rem = quo % 10;
            if (rem == prev)
            {
                count++; 
            }
            else
            {
                output += (count * 10 + prev) * unit; 
                unit *= 100;
                count = 1; 
                prev = rem;
            }
            quo /= 10; 
        }
        return output; 
    }

static    string countAndSay2(int n) {
        string res = "";
        string prev= "1"; 
        int it = 1;
        while (it <= n )
        {
            // scan through the prev result, if the character is the same, count++, if differnt, push_back count, then number.
            int size = prev.size(); 
            char prevChar = prev[0]; 
            res = ""; 
            int count = 0; 
			prev.push_back('#'); 
            for (int i = 0; i <= size; i++)
            {
                if (prev[i] == prevChar)
                {
                    count++; 
                }
                else
                {
                    res.push_back(count + '0'); 
                    res.push_back(prevChar);
                    prevChar = prev[i]; 
                    count = 1; 
                }
            }
            prev = res; 
            it++; 
        }
        return res; 
    }

    typedef vector<int>::iterator it; 
static    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return gen(inorder.begin(), inorder.end(), postorder.begin(), postorder.end()); 
    }
    
    // bi: beginning of the inorder tree
    // ei: end of inorder
    // bp: beginning of the post order tree
    // ep: end of post
static    TreeNode *gen(it bi, it ei, it bp, it ep)
    {
        if (bi == ei)
        {
            return NULL; 
        }
        it iroot = std::find(bi, ei, *(ep - 1)); 
        TreeNode *res = new TreeNode(*(ep - 1)); 
        res->left = gen(bi, iroot, bp, bp + (iroot - bi)); 
        res->right = gen(iroot + 1, ei, bp + (iroot - bi) , ep - 1); 
        return res; 
    }

 static    vector<vector<string>> partition(string s) {
         vector<vector<string>> res; 
         int n = s.size(); 
         if (n == 0)
         {
             return res; 
         }
         // first creat the dp array to mark a word starting from i, length j is palindrome or not
         vector<vector<bool>> dp(n, vector<bool>(n + 1, false)); 
         // base case, the first column, length = 1, are all palindromes
         for (int i = 0; i < n; i++)
         {
             dp[i][1] = true;
             dp[i][0] = true; 
         }
         for (int j = 2; j < n + 1; j++)
         {
             for (int i = 0; i <= n - j; i++)
             {
                 if (dp[i+1][j-2] && s[i] == s[i + j - 1])
                 dp[i][j] = true; 
             }
         }
         vector<string> tempRes; 
         dfs(s, 0, tempRes, res, dp); 
		 return res; 
     }
     
 static void dfs(string s, int i, vector<string> &tempRes, vector<vector<string>> &res, vector<vector<bool>> &dp)
     {
         int n = s.size(); 
         if (i == n)
         {
			 res.push_back(tempRes); 
			 return; 
         }
         for (int j = 1; j <= n - i; j++)
         {
             if (dp[i][j])
             {
                 tempRes.push_back(s.substr(i, j)); 
                 dfs(s, i + j, tempRes, res, dp); 
                 tempRes.pop_back(); 
             }
         }
     }

static   vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res; 
        dfs(0, num, res); 
        return res; 
    }
    
    
static    bool swapped(int start, int i, vector<int> &num)
    {
        for (int k = start; k < i; k++)
        {
            if (num[k] == num[i])
            {
                return true;
            }
        }
        return false; 
    }
    
static    void dfs(int start, vector<int> &num, vector<vector<int>> &res)
    {
        int n = num.size();
        if (start == n)
        {
            res.push_back(num); 
        }
            
        for (int i = start; i < n; i++)
        {
            if (i == start || !swapped(start, i, num))
            {
                swap(num, start, i);
                dfs(start + 1, num, res); 
                swap(num, start, i); 
            }
        }
    }

static     vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string,int> mp;
        for (int i=0;i<strs.size();i++){
            string ss = strs[i];
            sort(ss.begin(),ss.end());
            if (mp.find(ss)!=mp.end()){
                res.push_back(strs[i]);
                if (mp[ss]!=-1){
                    res.push_back(strs[mp[ss]]);    
                    mp[ss]=-1;
                }
            }else{
                mp[ss]=i;
            }
        }
        return res;
    }

static vector<string> anagrams2(vector<string> &strs) {
        // we use a hashtable to store the anagram whose letters are sorted 
        
        // then we scan the string array once, when we see its anagram already exist in the table, put the string into result. 
        // store its index as -1 in the hashtable, such that it is distinguished from the first anagram
        // otherwise store the string's index in the hashtable
        unordered_map<string, int> hash; 
        vector<string> res; 
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            string temp = strs[i]; 
            sort(temp.begin(), temp.end()); 
            if (hash.find(temp) != hash.end())
            {
                res.push_back(strs[i]); 
                if (hash[temp] != -1) // the first occurance hasn't been added yet
                {
                    res.push_back(strs[hash[temp]]); 
                    hash[temp] = -1; 
                }
            }
            else
            {
                // mark the index of the first occurance
                hash[temp] = i; 
            }
        }
        return res; 
    }

static void print(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", i); 
	}
}

static int binarySearch(vector<int> &arr, int start, int end, int target)
{
	if (start > end)
	{
		return -1; 
	}
	if (start == end)
	{
		if (arr[start] == target)
		{
			return start; 
		}
		else
		{
			return -1; 
		}
	}
	int mid = start + (end - start) / 2;
	if (arr[mid] == -1)
	{
		int left = binarySearch(arr, start, mid - 1, target); 
		int right = binarySearch(arr, mid + 1, end, target); 
		if (left == -1 && right == -1)
		{
			return -1; 
		}
		else if (left != -1)
		{
			return left;
		}
		else
		{
			return right; 
		}
	}
	else
	{
		if (arr[mid] == target)
		{
			return mid; 
		}
		else if (arr[mid] > target)
		{
			return binarySearch(arr, start, mid - 1, target); 
		}
		else
		{
			return binarySearch(arr, mid + 1, end, target); 
		}
	}
}


// this is longest increasing subsequence, the previous LIS is longest increasing sequence
static int LIS2(vector<int> input)
{
	int longest = 1;
	int n = input.size(); 
	vector<int> longs(n, 1); 
	for (int i = 0; i < n; i++)
	{
		int temp = 1; 
		for (int j = 0; j < i; j++)
		{
			if (input[i] > input[j])
			{
				if (longs[j] + 1 > temp)
				{
					temp = longs[j] + 1; 
					longs[i] = temp;
				}
				if (temp > longest)
				{
					longest = temp; 
				}
			}
		}
	}
	return longest;
}

static int LIS1( vector <int> arr )
{
	int n = arr.size(); 
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
    
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   /* Free memory to avoid memory leak */
   free( lis );
 
   return max;
}

static string remove(string &input)
{
	string res = ""; 
	stack<char> s; 
	int n = input.size();
	for (int i = 0; i < n; )
	{		
		if (!s.empty())
		{			 
			char top = s.top(); 
			if (input[i] == top)
			{
				s.pop(); 
			
				while (input[i] == top)
				{
					i++; 
					if (i >= n)
					{
						break; 
					}
				}
				//i--; 
			}
			else
			{
				s.push(input[i]); 
				i++; 
			}
		}
		else
		{
			s.push(input[i]);
			i++; 
		}
	}
	while (!s.empty())
	{
		char top = s.top(); 
		res = (top + res); 
		s.pop(); 
	}
	return res; 
}

static int largestSum1D(vector<int> v)
{
	if (v.size() == 0)
	{
		return 0; 
	}
	int runningSum = v[0]; 
	int maxSum = v[0]; 
	for (int i = 1; i < v.size(); i++)
	{
		runningSum = max(v[i], runningSum + v[i]);
		maxSum = max(runningSum, maxSum); 
	}
	return maxSum; 
}

static int largestSumRectangle(vector<vector<int>> mat)
{
	// for each pair of column start and end, sum the columns of a row, 
	// for the sum of each row, apply largest sum of a sequence algorithm
	int m = mat.size(); // rows
	int n = mat[0].size(); // columns
	 
	int maxSum = INT_MIN; 
	for (int j = 0; j < n; j++)
	{
		vector<int> rowSum(m, 0);
		for (int k = j; k < n; k++)
		{			
			for (int i = 0; i < m; i++)
			{
				rowSum[i] += mat[i][k];
			}
			int sum = largestSum1D(rowSum); 
			maxSum = max(maxSum, sum); 				
		}
	}
	return maxSum; 
}

static bool isBST2(TreeNode* root)
{
	return isBSTHelper2(root, INT_MIN, INT_MAX); 
}

// root node val must be between left node and right node
static bool isBSTHelper2(TreeNode* root, int minVal, int maxVal)
{
	if (root == NULL)
	{
		return true; 
	}
	if (root->val <= minVal || root->val >= maxVal)
	{
		return false;
	}
	return (isBSTHelper2(root->left, minVal, root->val) && isBSTHelper2(root->right, root->val, maxVal)); 
}

static vector<string> permuteString(string s, int& count)
{
	vector<string> res; 
	int n = s.size(); 
	if (n == 0)
	{
		return res; 
	}
	permuteStringHelper(s, 0, res, count); 
	return res; 
}

static bool swapped2(int start, int i, string &s)
{
	for (int k = start; k < i ; k ++)
	{
		if (s[k] == s[i])
		{
			return true;
		}
	}
	return false; 
}

static void permuteStringHelper(string s, int start, vector<string> &res, int &count)
{
	count++; 
	int n = s.size(); 
	if (start == n - 1)
	{
		res.push_back(s);
		return; 
	}
	for (int i = start; i < n; i++)
	{
		// handle duplicates
		if (i == start || !swapped2(start, i, s))
		{
			swap(s, start, i); 		 
			permuteStringHelper(s, start + 1, res, count); 
			swap(s, start, i);
		}
	}
}

static int LIS3(vector<int> a)
{
	int n = a.size(); 
	int res = 1; 
	vector<int> dp(n, 1); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((a[i] > a[j]) && (dp[j] + 1 > dp[i]))
			{
				dp[i] = dp[j] + 1;
				res = max(res, dp[i]); 
			}
		}
	}
	return res; 
}

static int findIncrease(vector<vector<int>> &mat, int &starti, int &startj, vector<int> &resSeq, vector<vector<int>> &resAllSeq)
{
	int tempRes = 1; 
	int res = 1; 
	starti = 0; 
	startj = 0; 
	for (int i = 0; i < mat.size(); i++)
	{		
		for (int j = 0; j < mat[0].size(); j++)
		{
			tempRes = 1;
			vector<int> seq;
			vector<int> maxSeq; 
			vector<vector<int>> allSeq;
			seq.push_back(mat[i][j]);
			find(mat, i, j, tempRes, seq, maxSeq, allSeq);			 
			if (tempRes > res)
			{
				starti = i; 
				startj = j;
				resSeq = maxSeq;
				resAllSeq = allSeq;
			}
			res = max(res, tempRes);			
		}
	}
	return res; 
}

// mat[i,j] is the starting point
static void find(vector<vector<int>> &mat, int i, int j, int &res, vector<int> &seq, vector<int> &maxSeq, vector<vector<int>> &allSeq)
{
	bool cont = false;
	int m = mat.size(); 
	int n = mat[0].size(); 
	int maximum = 0; 
	//int chosen = 0; 
	//up
	if (i - 1 >= 0 && mat[i-1][j] > mat[i][j])
	{
		seq.push_back(mat[i - 1][j]); 
		find(mat, i - 1, j, res, seq, maxSeq, allSeq);
		if (res > maximum)
		{			
			maximum = res;
		}
		seq.pop_back(); 
		cont = true;
	}
	//down
	if (i + 1 < m && mat[i+1][j] > mat[i][j])
	{
		seq.push_back(mat[i+1][j]); 
		find(mat, i + 1, j,  res, seq, maxSeq, allSeq); 
		if (res > maximum)
		{
			maximum = res;		
		}
		seq.pop_back(); 
		cont = true;
	}
	//left
	if (j - 1 >= 0 && mat[i][j - 1] > mat[i][j])
	{
		seq.push_back(mat[i][j - 1]); 
		find(mat, i, j - 1, res, seq, maxSeq, allSeq); 
		if (res > maximum)
		{
			maximum = res;		
		}
		seq.pop_back(); 
		cont = true;
	}
	//right
	if (j + 1 < n && mat[i][j + 1] > mat[i][j])
	{
		seq.push_back( mat[i][j + 1]); 
		find(mat, i, j + 1, res, seq, maxSeq, allSeq);
		if (res > maximum)
		{
			maximum = res;		
		}
		seq.pop_back(); 
		cont = true;
	}
	
	if (!cont)
	{
		if (maxSeq.size() < seq.size())
		{
			maxSeq = seq; 
		}
		allSeq.push_back(seq); 
	}
	res = maximum + 1;
}


static void dfsFlood(vector<vector<int>> &mat, int i, int j, int valAfter)
{
	int m = mat.size(); 
	int n = mat[0].size(); 
	int valBefore = mat[i][j]; 
	mat[i][j] = valAfter;
	// up
	if (i - 1 >= 0 && mat[i-1][j] == valBefore)
	{
		dfsFlood(mat, i - 1, j, valAfter); 
	}
	// down
	if (i + 1 < m && mat[i+1][j] == valBefore)
	{
		dfsFlood(mat, i + 1, j, valAfter); 
	}
	// left 
	if (j - 1 >= 0 && mat[i][j - 1] == valBefore)
	{
		dfsFlood(mat, i, j - 1,  valAfter); 
	}
	// right
	if (j + 1 < n && mat[i][j + 1] == valBefore)
	{
		dfsFlood(mat, i, j + 1, valAfter); 
	}

}

static void dfsFlood91(vector<vector<int>> &mat, int i, int j, int valBefore, int valAfter)
{
	int m = mat.size(); 
	int n = mat[0].size(); 
	if (i >= m || i < 0 || j >= n || j < 0 || mat[i][j] != valBefore)
	{
		return; 
	}
	mat[i][j] = valAfter;
	// up
	dfsFlood91(mat, i - 1, j, valBefore, valAfter); 
	// down
	dfsFlood91(mat, i + 1, j, valBefore, valAfter); 
	// left 
	dfsFlood91(mat, i, j - 1, valBefore, valAfter); 
	// right
	dfsFlood91(mat, i, j + 1, valBefore, valAfter);
}

static   int minCut(string s) {
               vector<int> minCuts(s.length() + 1, 0);
        for (int i = 0; i <= s.length(); i++){
            minCuts[i] = i - 1;
        }
        vector<bool> temp(s.length() + 1, false);
        vector<vector<bool> > isPalFast(s.length() + 1, temp);
        for (int j = 1; j <= s.length(); j++){
            for (int i = 1; i <= j; i++){
                /*
                if (isPal(s.substr(j, i - j)) && minCuts[j] + 1 < minCuts[i]){
                    minCuts[i] = minCuts[j] + 1;
                }
                */
                if (s[i - 1] == s[j - 1] && ((j - i ) < 2 || isPalFast[i + 1][j - 1])){
                    isPalFast[i][j] = true;
                    minCuts[j] = min(minCuts[j], minCuts[i - 1] + 1); // for every j, there is a corresponding minCuts[i], this is to make sure we the minimum minCut[i] from all j values. 
                }
            }
        }
        return minCuts[s.length()];
    }

static int findLongestPalindrome(string s)
{
	int longest = 1; 
	int n = s.size(); 
	vector<vector<bool>> dp(n, vector<bool>(n,false)); 
	for (int j = 0; j < n; j++)
		for (int i = 0; i <= j; i++)
		{
			if (s[i] == s[j] && ( j - i < 2 || dp[i+1][j-1]))
			{
				dp[i][j] = true; 
				longest = max(longest, j - i + 1); 
			}
		}
	return longest;
}

static int findMaxSumPath(vector<vector<int>> mat, vector<int> &path)
{
	// walk from top left to bottom right, only go down or right
	int m = mat.size(); 
	int n = mat[0].size(); 
	vector<vector<int>> dp(m, vector<int>(n, 0));
	vector<vector<int>> trace(m, vector<int>(n, 0));

	dp[0][0] = mat[0][0];
	for (int i = 1; i < m; i++)
	{
		dp[i][0] = dp[i-1][0] + mat[i][0]; 
	}
	for (int j = 1; j < n; j++)
	{
		dp[0][j] = dp[0][j - 1] + mat[0][j]; 
	}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mat[i][j]; 
			if (dp[i-1][j] > dp[i][j-1])
			{
				trace[i][j] = 1; 
			}
		}
	int nexti = m - 1; 
	int nextj = n - 1; 
	for (int i = 0; i < m + n - 1; i++)
	{
		path.push_back(mat[nexti][nextj]); 
		if (trace[nexti][nextj] == 1) // go up 
		{
			nexti -= 1; 
		}
		else
		{
			nextj -= 1; 
		}
		
	}
	return dp[m-1][n-1]; 
}

// AB12 to A1B2
static void convertAB12(string &s)
{
	convertAB12(s, 0, s.length() - 1); 
}

static void convertAB12(string &s, int l, int r)
{
	if (l >= r - 1)
	{
		return; 
	}
	int mid = (l + r + 1) / 2;
	int l1 = (l + mid) / 2; 
	int r1 = (mid + r + 1) / 2; 
	reverseStr(s, l1, mid - 1); 
	reverseStr(s, mid, r1 - 1); 
	reverseStr(s, l1, r1 - 1); 
	convertAB12(s, l, l1 * 2 - l - 1 );
	convertAB12(s, l1 * 2 - l, r); 
}

static void reverseStr(string &str, int l, int r )
{
	for (int i = 0; i < (r - l + 1) / 2; i++)
	{
		char temp = str[l + i]; 
		str[l + i] = str[r - i]; 
		str[r - i] = temp; 
	}
}

static void convertA1B2(string &s)
{
	convertA1B2(s, 0, s.length() - 1); 
}

static void convertA1B2(string &s, int left, int right)
{
	if (right - left <= 1)
	{
		return; 
	}
	int mid = (left + right + 1) / 2; 
	int l1 = (left + mid) / 2; 
	int r1 = (mid + right + 1) /2; 
	convertA1B2(s, left, l1 + (l1 - left) - 1); 
	convertA1B2(s, l1 + (l1 - left), right); 
	reverseStr(s, l1, r1 - 1); 
	reverseStr(s, l1, mid - 1); 
	reverseStr(s, mid, r1 - 1);
}

static TreeNode* reconPostOrder(vector<int> postOrder)
{
	vector<int> inOrder = postOrder; 
	sort(inOrder.begin(), inOrder.end()); 
/*    4
	/  \  
	2   5
   /\    \
  1 3     6 
*/
	// post order 132564
	// in ordre 123456

	return recon(postOrder.begin(), postOrder.end(), inOrder.begin(), inOrder.end()); 

}

static TreeNode* recon(vector<int>::iterator pl, vector<int>::iterator pr, 
	vector<int>::iterator il, vector<int>::iterator ir)
{
	if (il >= ir)
	{
		return NULL; 
	}
	vector<int>::iterator iroot = std::find(il, ir, *(pr - 1));
	TreeNode *root = new TreeNode(*(pr - 1)); 
	root->left = recon(pl, pl + (iroot - il), il, iroot); 
	root->right = recon(pl + (iroot - il), pr - 1, iroot + 1, ir);
	return root; 
}

static TreeNode* reconPreOrder(vector<int> preOrder)
{
	vector<int> inOrder = preOrder; 
	sort(inOrder.begin(), inOrder.end()); 
	return reconPreOrder(preOrder.begin(), preOrder.end(), inOrder.begin(), inOrder.end()); 
}

static TreeNode* reconPreOrder(vector<int>::iterator pl, vector<int>::iterator pr, 
	vector<int>::iterator il, vector<int>::iterator ir)
{
	if (il >= ir)
	{
		return NULL; 
	}
	vector<int>::iterator iroot = std::find(il, ir, *pl); 
	TreeNode* root = new TreeNode(*pl); 
	root->left = reconPreOrder(pl + 1, pl + (iroot - il) + 1, il, iroot); 
	root->right = reconPreOrder(pl + (iroot - il) + 1, pr, iroot + 1, ir); 
	return root; 
}

static vector<vector<vector<int>>> assignTasks(int serverCount, int taskCount)
{
	vector<vector<vector<int>>> res; 
	vector<vector<int>> tempRes(serverCount, vector<int>(0,0)); 
	dfs(taskCount, serverCount, tempRes, res); 
	return res; 
}

static void dfs(int taskLeft, int serverCount, vector<vector<int>> &tempRes, vector<vector<vector<int>>> &res)
{
	if (taskLeft == 0)
	{
		res.push_back(tempRes); 
		return; 
	}
	for (int i = 0; i < serverCount; i++)
	{
		if (canPut(taskLeft, tempRes[i]))
		{
			tempRes[i].push_back(taskLeft); 
			dfs(taskLeft - 1, serverCount, tempRes, res); 
			tempRes[i].pop_back(); 
		}
	}
}

static bool canPut(int val, vector<int> &server)
{
	for (int i = 0; i < server.size(); i++)
	{
		if (abs(val - server[i]) <= 1)
		{
			return false;
		}
	}
	return true; 
}

// if there is a majority, the return value is the majority. 
// but if we need to confirm if there is a majority, we need to scan the array one more time
static int findMajority(vector<int> arr)
{
	int n = arr.size();
	if (n == 0)
	{
		return -1; 
	}
	int count = 0; 
	int candidate; // = arr[0];  
	for (int i = 0; i < n; i++)
	{
		if (count == 0)
		{
			candidate = arr[i];
			count++;
		}
		else
		{
			if (arr[i] == candidate)
			{
				count++; 
			}
			else
			{
				count--; 
			}
		}
	}
	if (count > 0)
	{
		return candidate;
	}
	else
	{
		return -1; 
	}
}

// find maximum configuration
// step 1: find all valid configurations of one row, store it in a 2-d vector, assume k valid configurations
// step 2: initalize dp array, n * k, row 0 init with the sum of each of the k configs. 
// step 3: compare current row's config with the config of previous row, this result can be saved in a
// k by k boolean matrix 
// step 4: scan row by row, if valid, compute the sum, 
// store the max sum of each combination of config. 

static void validConfig(int n, int start, vector<int> &tempRes, vector<vector<int>> &res)
{
	//if (start == n)
	//{
	//	//res.push_back(tempRes); 
	//	return; 
	//}
	for (int i = start; i < n; i++)
	{
		if (tempRes.size() == 0 || i > tempRes.back() + 1)
		{
			tempRes.push_back(i); 
			res.push_back(tempRes); 
			validConfig(n, i + 1, tempRes, res); 
			tempRes.pop_back();
		}
	}
}

static vector<vector<bool>> validConfigTwoRows(vector<vector<int>> configs)
{
	int k = configs.size(); 
	vector<vector<bool>> res(k, vector<bool>(k, 0)); 
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
		{			
			res[i][j] = !conflict(configs[i], configs[j]); 
		}
	return res; 
}

static bool conflict(vector<int> row1, vector<int> row2)
{
	for (int i = 0; i < row1.size(); i++)
		for (int j = 0; j < row2.size(); j++)
		{
			if (abs(row1[i] - row2[j]) <= 1)
			{
				return true; 
			}
		}
	return false; 
}

// step 4: scan row by row, if valid, compute the sum, 
// store the max sum of each combination of config.
static int sum(vector<int> arr, vector<int> config)
{
	int res = 0; 
	for (int i = 0; i < config.size(); i++)
	{
		res+=arr[config[i]]; 
	}
	return res; 
}
static int maxSumMatrixNoEightNeighbor(vector<vector<int>> mat)
{
	int m = mat.size(); 
	int n = mat[0].size(); 
	vector<vector<int>> configs; 
	vector<int> tempRes;
	configs.push_back(tempRes); 
	uber::validConfig(n, 0, tempRes, configs); 
	int k = configs.size(); 
	vector<vector<bool>> configTwoRows = uber::validConfigTwoRows(configs); 
	vector<vector<int>> dp(m, vector<int>(k, 0)); 
	for (int i = 0; i < k; i++)
	{
		dp[0][i] = sum(mat[0], configs[i]); 
	}
	int maxVal = 0; 
	for (int row = 1; row < m; row++)
	{
		for (int j = 0; j < k; j++)
		{
			int maxValj = 0; 
			dp[row][j] = sum(mat[row], configs[j]); 
			for (int i = 0; i < k; i++)
			{
				if (configTwoRows[i][j])
				{
					maxValj = max(maxValj, dp[row - 1][i] + dp[row][j]);					 
				}
			}
			dp[row][j] = maxValj; 
			maxVal = max(maxVal, maxValj);
		}
	}
	return maxVal; 

}

static int maxHistogram(vector<int> arr)
{ 
	// stores the index of ascending histograms
	stack<int> s; 
	// add a zero to the end of array such that we can pop everything at the end
	arr.push_back(0); 
	int n = arr.size(); 
	//s.push(0); 
	int area;
	int maxArea = 0; 
	for (int i = 0; i < n; i++)
	{
        if (s.empty() || arr[i] > arr[s.top()])
		{
			s.push(i); 
		}
		else
		{
			int top = arr[s.top()]; 
			while (arr[i] <= top)
			{
				s.pop();
				if (s.empty())
				{
					area = top * (i); 
					maxArea = max(area, maxArea);
					break;
				}
				else
				{
					area = top * (i - s.top() - 1);
				}
				maxArea = max(area, maxArea); 
				top = arr[s.top()];
			}
			s.push(i); 
		}
	}
	return maxArea; 
}

static int largestRectangleArea2(vector<int> &height) {
    stack<int> S;
    height.push_back(0);
    int result = 0;
    for (int i = 0; i < height.size(); ) {
        if (S.empty() || height[i] > height[S.top()]) {
            S.push(i);
            i++;
        } else {
            int tmp = S.top();
            S.pop();
            int width = S.empty() ? i : i - S.top() - 1;
            int area = height[tmp] * width;
            result = max(result, area);
        }
    }
    return result;
}

int largestHistogram(vector<int> histogram)
{
	stack<int> s; // store indexes of an ascending array	
	histogram.push_back(0); // push a zero at the end such that everything will be popped at the end;
	int n = histogram.size();
	int maxarea = 0; 
	for (int i = 0; i < n; )
	{
		if (s.empty() || histogram[i] > histogram[s.top()])
		{
			s.push(i); 
			i++; 
		}
		else
		{
			int top = s.top(); 
			s.pop(); 
			int area; 
			if (s.empty())
			{
				area = histogram[top] * i; 
			}
			else
			{
				area = histogram[top] * (i - 1 - s.top()); 
			}
			maxarea = max(maxarea, area); 
		}
	}
	return maxarea; 
}


static int largestHistogram1(vector<int> hist)
{
	stack<int> s; 
	hist.push_back(0);
	int maxarea = 0; 
	for (int i = 0; i < hist.size(); )
	{
		if (s.empty() || hist[i] > hist[s.top()])
		{
			s.push(i); 
			i++;
		}
		else
		{
			int top = s.top(); 
			s.pop(); 
			int area = hist[top] * (s.empty() ? i : i - 1 - s.top()); 
			maxarea = max(area, maxarea);
		}
	}
	return maxarea; 
}

static    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res; 
        vector<int> tempRes;
        dfs(n, k, 1, tempRes, res); 
        return res; 
       
    }
    
static    void dfs(int n, int k, int start, vector<int> &tempRes, vector<vector<int>> &res)
    {
        if (tempRes.size() == k)
        {
            res.push_back(tempRes);
            return; 
        }
        for (int i = start; i <= n; i++)
        {
            tempRes.push_back(i); 
            dfs(n, k, i + 1, tempRes, res); 
            tempRes.pop_back(); 
        }
    
    }

static vector<vector<int>> permutation816(vector<int> input)
{
	vector<int> temp; 
	vector<vector<int>> res; 
	permute(0, input, res); 
	return res; 
}

static void permute(int start, vector<int> &input, vector<vector<int>> &res)
{
	int n = input.size(); 
	if (start == n)
	{
		res.push_back(input); 
		return; 
	}
	for (int i = start; i < n; i++)
	{
		swap(input, start, i); 
		permute(start + 1, input, res); 
		swap(input, start, i); 
	}
}

static vector<vector<int>> subset816(vector<int> input)
{
	vector<int> temp; 
	vector<vector<int>> res; 
	res.push_back(temp); 
	subset(0, input, temp, res); 
	return res; 
}

static void subset(int start, const vector<int> &input, vector<int> &temp, vector<vector<int>> &res)
{
	int n = input.size(); 
	if (start == n)
	{
		return; 
	}
	for (int i = start; i < n; i++)
	{
		temp.push_back(input[i]); 
		res.push_back(temp); 
		subset(i + 1, input, temp, res); 
		temp.pop_back(); 
	}
}


static vector<vector<int>> combination816(vector<int> input, int k)
{
	vector<int> temp; 
	vector<vector<int>> res;
	combination(0, k, input, temp, res); 
	return res; 
}

static void combination(int start, int k, const vector<int> &input, vector<int> &temp, vector<vector<int>> &res)
{
	int n = input.size(); 
	if (temp.size() == k)
	{
		res.push_back(temp); 
		return; 
	}
	for (int i = start; i < n; i++)
	{
		temp.push_back(input[i]); 
		combination(i + 1, k, input, temp, res); 
		temp.pop_back(); 
	}
}

static int countCoinsPermutation816(vector<int> coins, int target)
{
	vector<int> dp(target + 1, 0); 
	int n = coins.size(); 
	dp[0] = 1; 
	for (int i = 1; i <= target; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (i - coins[k] >= 0)
			{
				dp[i] += dp[i - coins[k]]; 
			}
		}
	}
	return dp[target]; 
}

static int climbStairs(int target)
{
	int dp_1 = 1; 
	int dp_2 = 2; 
	int dp_3 = 4;
	int res = 0;
	if (target == 1) return dp_1;
	if (target == 2) return dp_2; 
	if (target == 3) return dp_3; 
	for (int i = 4; i <= target; i++)
	{
		res = (dp_1 + dp_2 + dp_3); 
		dp_1 = dp_2; 
		dp_2 = dp_3; 
		dp_3 = res; 
	}
	return res; 
}

static int countCoinsCombination816(vector<int> coins, int target)
{
	vector<int> dp(target + 1, 0); 
	dp[0] = 1; 
	int n = coins.size(); 
	for (int k = 0; k < n; k++)
	{
		int coin = coins[k]; 
		for (int i = coin; i <= target; i++)
		{
			dp[i] += dp[i - coin];  
		}
	}
	return dp[target]; 
}

static vector<vector<int>> findAllCoinsCombinations816(vector<int> coins, int target)
{
	vector<vector<int>> res; 
	vector<int> temp; 
	dfs(coins, 0, target, temp, res); 
	return res; 
}

// k is the index of which coin to evaluate
// target is the remaining number to reach
static void dfs(const vector<int> &coins, int k, int target, vector<int> &temp, vector<vector<int>> &res)
{
	int n = coins.size(); 
	int coin = coins[k]; 
	if (k == n - 1)
	{
		if (target % coin == 0)
		{
			temp.push_back(target / coin); 
			res.push_back(temp); 
			temp.pop_back(); 
		}
		return; 
	}
	for (int i = 0; target - i * coin >= 0; i++)
	{
		temp.push_back(i); 
		dfs(coins, k + 1, target - i * coin, temp, res); 
		temp.pop_back(); 
	}
}

static vector<vector<int>> findAllPermutationsCoins816(vector<int> coins, int target)
{
	vector<int> temp; 
	vector<vector<int>> res; 
	dfs(coins, target, temp, res); 
	return res; 
}

static void dfs(vector<int> &coins, int target, vector<int> &temp, vector<vector<int>> &res)
{
	int n = coins.size();
	if (target < 0)
	{
		return; 
	}
	if (target == 0)
	{
		res.push_back(temp); 
		return; 
	}
	for (int i = 0; i < n; i++)
	{
		temp.push_back(coins[i]); 
		//target -= coins[i];  if target is declared as int & in the function signature this will work 
		//dfs(coins, target, temp, res); 
		//target += coins[i]; 
		dfs(coins, target - coins[i], temp, res);
		temp.pop_back(); 
	}
}

// this is in fact the kth smallest
static int kthLargestBST816(TreeNode* root, int k)
{
	int res;
	int count = 0; 
	inOrder(root, count, k, res);
	return res;
}

static void inOrder(TreeNode* root, int &count, int k, int & res)
{
	if (root == NULL)
	{ 
		return; 
	}
	if (count == k)
	{
		return; 
	}

	inOrder(root->left, count, k, res); 
	count++;
	if (count == k)
	{
		res = root->val; 
		return; 
	}
	
	inOrder(root->right, count, k, res); 
}

// this is in fact the kth largest
static void kthSmallest(TreeNode *root, int &k, int &res) {
    if (root == NULL || k <= 0) {
        return;
    }
    kthSmallest(root->right, k, res);
    k--;
    if (k == 0) {
		res = root->val; 
        cout << root->val << endl;
        return;
    }
    kthSmallest(root->left, k, res);
}

static int countTarget1(vector<int> arr, int target)
{
	int i = 0; 
	int j = arr.size(); 
	// find lower bound 
	int mid; 
	while (i < j)
	{
		mid = i + (j - i) / 2; 
		if (arr[mid] >= target)
		{
			j = mid; 
		}
		else
		{
			i = mid + 1; 
		}
	}
	int low = i; // or j doesn't matter
	// find upper bound
	i = 0; 
	j = arr.size(); 
	while (i < j)
	{
		mid = i + (j - i) / 2; 
		if (arr[mid] > target)
		{
			j = mid; 
		}
		else
		{
			i = mid + 1; 
		}
	}
	int high = j; // or j doesn't matter
	return high - low; 
}

static int countTarget2(vector<int> arr, int target)
{
	// first binary search the target
	int i = 0; 
	int j = arr.size(); 
	int mid = i + (j - i) / 2;

	// find lower bound 
	while (i < j)
	{
		mid = i + (j - i) / 2 ; 
		if (arr[mid] > target)
		{
			j = mid;
		}
		else if (arr[mid] == target)
		{
			j = mid; 
		}
		else
		{
			i = mid + 1;   
		}	
	}
	int lowerbound = i; 


	// find upper bound
	i = 0; 
	j = arr.size();
	while (i < j)
	{
		mid = i + (j - i) / 2; 
		if (arr[mid] > target)
		{
			j = mid; 
		}
		else if (arr[mid] == target)
		{
			i = mid + 1; 
		}
		else
		{
			i = mid + 1; 
		}
	}
	int upperbound = j; 

	return (upperbound - lowerbound) ; 

}


static  vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2, -1);  
        int lower = 0;  
        int upper = n;  
        int mid;  
  
        // Search for lower bound  
        while (lower < upper) {  
            mid = (lower + upper) / 2;  
            if (A[mid] < target)  
                lower = mid + 1;  
            else  
                upper = mid;  
        }  
  
        // If the target is not found, return (-1, -1)  
        if (A[lower] != target)  
            return range;  
        range[0] = lower;  
  
        // Search for upper bound  
        upper = n;  
        while (lower < upper) {  
            mid = (lower + upper) / 2;  
            if (A[mid] > target)  
                upper = mid;  
            else  
                lower = mid + 1;  
        }  
        range[1] = upper - 1;  
  
        return range;  
    }

static int minCutPalindrome816(string s)
{
	int n = s.size(); 
	// use a 2d dp to track if substr(s, i,j-i+1) is palindrome
	vector<vector<bool>> dp(n, vector<bool>(n, false)); 
	// use a vector to track the mincut of substr(s, 0, j + 1)
	vector<int> mincut(n, 0); 

	//init the mincut array
	for (int i = 0; i < n; i++)
	{
		mincut[i] = i; 
	}

	// let i be the starting index of the substring
	// let j be the ending index of the substring
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i <= j; i++)
		{
			if(s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
			{
				dp[i][j] = true;
				// when dp[i][j] is true, there is a potential that we can get smaller cut
				if (i == 0)
				{
					mincut[j] = 0; 
				}
				else
				{
					mincut[j] = min(mincut[j], mincut[i - 1] + 1); 
				}
			}
		}
	}
	return mincut[n-1];
}

static vector<vector<string>> partitionPalindrome817(string s)
{
	int n = s.size(); 
	// first use dp to find all valid palindrome, i and j are starting and ending indexes of a word
	vector<vector<bool>> dp(n, vector<bool>(n, false));
	dp[0][0] = true; 
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i <= j; i++)
		{
			if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
			{
				dp[i][j] = true; 
			}
		}
	}
	// use dfs to output all palindrome partitioning results
	vector<string> temp; 
	vector<vector<string>> res; 
	dfs817(s, dp, 0, temp, res); 
	return res; 
}

static void dfs817(const string &s, const vector<vector<bool>> &dp, int i, vector<string> & temp, vector<vector<string>> &res)
{
	int n = s.size(); 
	if (i == n)
	{
		res.push_back(temp); 
		return; 
	}
	for (int j = i; j < n; j++)
	{
		if (dp[i][j])
		{
			temp.push_back(s.substr(i, j - i + 1));
			dfs817(s, dp, j + 1, temp, res); 
			temp.pop_back(); 
		}
	}
}


static    vector<string> wordBreak817(string s, unordered_set<string> &dict) 
    {
        int n = s.size();
        vector<string> res; 
        if (n == 0)
        {
            return res; 
        }
        // first use dp to find all breakable options at every index of s, dp[i][k], i is the index of end of the word, k is the index
        // of breakpoint 
        vector<vector<int>> dp(n); 
        for (int i = 0; i < n; i++)
        {
            // i is the end, j is beginning
            for (int j = 0; j <= i; j++)
            {
                string word = s.substr(j, i - j + 1); 
                if (dict.find(word) != dict.end() && (j == 0 || dp[j - 1].size() > 0))
                {
                    dp[i].push_back(j); // push the beginning index
                }
            }
        }
        // dfs to print all results
        dfs(s, n - 1, dp, "", res);
        return res; 
    }
    
static   void dfs(const string &s, int i, const vector<vector<int>> &dp, string temp, vector<string> &res)
    {
        if (i < 0)
        {
            res.push_back(temp.substr(0, temp.size() - 1)); // remove the last " " 
            return;
        }
        for (int k = 0; k < dp[i].size(); k++)
        {
            int j = dp[i][k];
            dfs(s, j - 1, dp, s.substr(j, i - j + 1) + " " + temp, res);
        }
    }

static int findFirst(string &s, char target)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == target)
            {
                return i; 
            }
        }
        return -1; 
    }
    
static  int lengthOfLongestSubstring(string s) {
        // use bit map to store the eixsting characters of the substr ending at j, 
        // for a new char s[i], compare with bitmap, if not found, longest++, bitmap add the new char,
        int longest = 0; 
        int n = s.size(); 
        if (n == 0)
        {
            return 0; 
        }
        //vector<int> dp(n, 0); 
        
        int curCount = 0; 
        string curString = ""; 
        for (int i = 0; i < n; i++)
        {
            int curIndex = findFirst(curString, s[i]);
            if (curIndex == -1)
            {
                curString += s[i]; 
                curCount++; 
                longest = max(longest, curCount);
            }
            else
            {
				// find repeated, cut the current string to the first found repeated location
				// add the repeated char to the end
                curCount = curCount - curIndex; 
				curString += s[i];
				curString = curString.substr(curIndex + 1, curCount);
            }
        }
        return longest; 
    }

static  int lengthOfLongestSubstring817(string s) {

        // use bit map to store the eixsting characters of the substr ending at j, 
        // for a new char s[i], compare with bitmap, if not found, longest++, bitmap add the new char,
        int longest = 0; 
        int n = s.size(); 
        if (n == 0)
        {
            return 0; 
        }
        int curCount = 0; 
        // don't use an extra string, instead, use i, j to track the beginning and end of the current string
        // string curString = ""; 
        // add a bool array to track all the existing characters of the current array
        vector<bool> exist(256, false); 
        int i = 0; 
        for (int j = 0; j < n; j++)
        {
            if (!exist[s[j]])
            {
                exist[s[j]] = true;
            }
            else
            {
                // find the first index of the repeated character
                while (s[i] != s[j])
                {
                    exist[s[i]] = false;
                    i++;
                }
                i++; 
            }
            curCount = j - i + 1;  
            longest = max(longest, curCount);
        }
        return longest; 
    }

static double findMedian(vector<int> &arr)
{
	priority_queue<int> left;  // max heap
	priority_queue<int, std::vector<int>, std::greater<int>> right;  // min heap 
	int n = arr.size();
	double m = 0; 
	for (int i = 0; i < n; i++)
	{
		int lSize = left.size(); 
		int rSize = right.size(); 
		if (lSize < rSize)
		{
			if (arr[i] <= right.top())
			{
				left.push(arr[i]);			
			}
			else
			{
				left.push(right.top());
				right.pop(); 
				right.push(arr[i]); 
			}
			m = (double)(left.top() + right.top()) / 2.0; 
		}
		else if (lSize > rSize)
		{
			if (arr[i] >= left.top())
			{
				right.push(arr[i]);			
			}
			else
			{
				right.push(left.top());
				left.pop(); 
				left.push(arr[i]); 
			} 
			m = (double)(left.top() + right.top()) / 2.0; 
		}
		else // equal size
		{
			if (lSize == 0 || arr[i] < left.top())
			{
				left.push(arr[i]); 
				m = left.top(); 
			}
			else
			{
				right.push(arr[i]);
				m = right.top(); 
			}
			
		}
	}
	return m; 
}

static char *strStr(char *haystack, char *needle) {
        if (needle == NULL) return haystack; 
        char *h = haystack; 
        char *n = needle;
        while (*h != NULL)
        {
            int length = 0; 
            if (n != NULL && *h == *n)
            {
                h++; 
                n++;
                length++; 
            }
            if (n == NULL)
            {
                return n - length; 
            }
            else
            {
                h = h - length + 1; 
                n = n - length; 
            }
        }
        return NULL; 
    }

static    int numDistinct(string S, string T) {
        int count = 0;
        int left = T.size(); 
        dfs(S, T, 0, left, count); 
        return count; 
    }
    
 static   void dfs(string &S, string &T, int start, int left, int &count)
    {
        int n = S.size(); 
        int m = T.size(); 
        if (left == 0)
        {
            count++; 
            return; 
        }
        for (int i = start; i < n; i++)
        {
            if (S[i] == T[m - left]) 
            {
                dfs(S, T, i + 1, left - 1, count); 
            }
            
        }
    }

static int numDistinct1(string S, string T) 
{
   // IMPORTANT: Please reset any member data you declared, as
   // the same Solution instance will be reused for each test case.
   int lens = S.length(), lent = T.length();
   if(lent == 0)return 1;
   else if(lens == 0)return 0;
   //vector<vector<int>> dp(lens+1, vector<int>(lent+1, 0));
   vector<int> dp(lent + 1, 0); 
   //for(int i = 0; i <= lens; i++)dp[i][0] = 1;
   dp[0] = 1; 
   for(int i = 1; i <= lens; i++)
   {
       for(int j = lent; j >= 1; j--)
       {
           if(S[i-1] == T[j-1])
               dp[j] = dp[j-1]+dp[j];
           else dp[j] = dp[j];
       }
   }
   return dp[lent];
}

static vector<int> findSquareSum(int target)
{
	vector<int> res; 
	int maxi = (int)std::sqrt((double)target); 
	int i = 1; 
	int j = maxi; 
	while (i <= j)
	{
		int sum = i*i + j*j; 
		if (sum == target)
		{
			res.push_back(i); 
			res.push_back(j);
			return res;
		}
		if (sum < target)
		{
			i++; 
		}
		else
		{
			j--; 
		}
	}
	return res; 	
}

static vector<string> genParenth(vector<int> parCount)
{
	// use hash to map right to left, and check if parenthese match
	//unordered_map<char, char> hash; 
	//hash['{'] = '}'; 
	//hash['['] = ']'; 
	//hash['('] = ')'; 
	// use stack to track what parenthese has been pushed. 
	stack<char> s; 
	// user l[3] and right[3] to track how many parentheses has been used. 
	int l[3]; 
	int r[3]; 
	// dfs
	// base case, right[] = parCount[], for 0 to 2
	// increment l[i] and r[i] to recurse deeper
	// backtrack to find all valid cases.
	vector<string> res; 
	string temp; 
	for (int i = 0; i < 3; i++)
	{
		l[i] = 0; 
		r[i] = 0; 
	}
	dfs(res, temp, l, r, parCount, s); 
	return res; 
}

static void dfs(vector<string> &res, string temp, int l[], int r[], const vector<int> &n, 
	stack<char> &s)
{
	int done = true; 
	for (int i = 0; i < 3; i++)
	{
		if (r[i] != n[i])
		{
			done = false; 
			break;
		}
	}
	if (done)
	{
		res.push_back(temp); 
	}
	string left = "{[("; 
	string right = "}])"; 
	for (int i = 0; i < 3; i++)
	{
		if (l[i] < n[i])
		{
			s.push(left[i]); 
			l[i]++; 
			dfs(res, temp + left[i], l, r, n, s); 
			s.pop(); 
			l[i]--; 
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (r[i] < l[i])
		{
			if (s.top() == left[i])//hash[left[i]])
			{
				char top = s.top(); 
				s.pop(); 
				r[i]++; 
				dfs(res, temp + right[i], l, r, n, s); 
				r[i]--; 
				s.push(top); 
			}
		}
	}
}

static TreeNode* LCA(TreeNode* root, TreeNode* node1, TreeNode* node2)
{
	if (root == NULL)
	{
		return NULL; 
	}
	if (root == node1 && root == node2)
	{
		return root; 
	}
	TreeNode* l = LCA(root->left, node1, node2);
	TreeNode* r = LCA(root->right, node1, node2); 
	if (l != NULL && r != NULL)
	{
		return root; 
	}
	if (l != NULL)
	{
		return l; 
	}
	return r; 
}

static bool isComplete(TreeNode* root)
{
	//BFS
	queue<TreeNode*> q; 
	q.push(root); 
	bool nonFullFound = false;
	while (!q.empty())
	{
		TreeNode* front = q.front(); 
		q.pop(); 
		if (!nonFullFound)
		{
			if (front->left)
			{
				q.push(front->left); 
			}
			else
			{
				nonFullFound = true; 
				continue; 
			}

			if (front->right)
			{
				q.push(front->right); 
			}
			else
			{
				nonFullFound = true;
			}
		}
		else
		{
			if (front->left || front->right)
			{
				return false; 
			}
		}
	}
	return true; 
}

static vector<int> findMaxSlidingWindow(vector<int> arr, int k)
{
	vector<int> res; 
	int n = arr.size(); 
	if (k == 0 || n == 0)
	{
		return res; 
	}
	deque<int> dq; // store the index of the candidates 
	dq.push_back(arr[0]); 
	for (int i = 1; i < n; i++)
	{
		if (i - dq.front() + 1 > k)
		{
			dq.pop_front(); 
		}

		while (!dq.empty() && arr[dq.back()] < arr[i])
		{
			dq.pop_back(); 
		}
	
		dq.push_back(i);
		if (i >= k - 1)
		{
			res.push_back(arr[dq.front()]); 
		}
	}
	return res; 
}


static vector<int> windowKMax(vector<int> &A, int k) {
    vector<int> result;
    // double ended queue to store indexes in A and maintain decreasing order
    // of values from front to back
    deque<int> DQ;
    for (int i = 0; i < k; i++) {
        while (!DQ.empty() && A[i] >= A[DQ.back()]) {
            DQ.pop_back();
        }
        DQ.push_back(i);
    }
    for (int i = k; i < A.size(); i++) {
        result.push_back(A[DQ.front()]);
        while (!DQ.empty() && DQ.front() <= i - k) {
            DQ.pop_front();
        }
        while (!DQ.empty() && A[i] >= A[DQ.back()]) {
            DQ.pop_back();
        }
        DQ.push_back(i);
    }
    result.push_back(A[DQ.front()]);
    return result;
}

static vector<int> kwayMerge(vector<vector<int>> arrays)
{
	while (arrays.size() > 1)
	{
		if (arrays.size() % 2 == 1)
		{
			arrays.push_back(vector<int>()); 
		}
		vector<vector<int>> temp; 
		for (int i = 0; i < arrays.size(); i += 2)
		{
			temp.push_back(merge(arrays[i], arrays[i + 1])); 
		}
		arrays = temp; 
	}
	return arrays[0]; 
}

static vector<int> merge(vector<int> a1, vector<int> a2)
{
	vector<int> res; 
	if (a1.size() == 0)
	{
		return a2;
	}
	if (a2.size() == 0)
	{
		return a1;
	}
	int i = 0; 
	int j = 0; 
	while (i < a1.size() && j < a2.size())
	{
		if (a1[i] < a2[j])
		{
			res.push_back(a1[i]);
			i++; 
		}
		else 
		{
			res.push_back(a2[i]);
			j++; 
		}
	}
	if (i == a1.size())
	{
		while (j < a2.size())
		{
			res.push_back(a2[j]); 
			j++; 
		}
	}
	else
	{
		while (i < a1.size())
		{
			res.push_back(a1[i]); 
			i++; 
		}
	}
	return res; 
}

static vector<int> kWayMerge(vector<vector<int>> l) {
	while (l.size() > 1) {
	if (l.size() % 2 == 1) {//always is even
	l.push_back(vector<int>());
	}
	vector<vector<int>> temp;
	for(int i = 0; i < l.size(); i += 2) {
		temp.push_back( kWayMergeHelper(l[i], l[i +1]));
	}
	l = temp;
	}
	return l[0];
}
static vector<int> kWayMergeHelper(vector<int>& a1, vector<int>&a2) {
	if (a1.size() == 0) return a2;
	if (a2.size() == 0) return a1;
	int i = 0;
	int j = 0;
	vector<int> result;
	while (i < a1.size() && j < a2.size()) {
	if(a1[i] < a2[j]) {
	result.push_back(a1[i]);
	i++;
	} else {
		result.push_back(a2[j]);
		j++;
	}
	}
	while (i < a1.size() ) {
	result.push_back(a1[i]);
	i++;
	}
	while (j < a2.size() ) {
	result.push_back(a2[j]);
	j++;
	}
	return result;
}
struct pair
{
	int val;
	int index; 
	pair(int val_, int index_): val(val_), index(index_){}
	bool operator>(const pair &other) const
	{
		return val > other.val; 
	}
};
 
static vector<int> kwayMerge2(vector<vector<int>> arrays)
{
	vector<int> res; 
	int k = arrays.size(); 
	priority_queue<pair, vector<pair>, greater<pair>> minHeap; 
	vector<int> index(k, 0); 
	for (int i = 0; i < k; i++)
	{
		minHeap.push(pair(arrays[i][0], i)); 
		index[i]++; 
	}
	while (!minHeap.empty())
	{
		pair top = minHeap.top();
		minHeap.pop(); 
		res.push_back(top.val); 
		if (index[top.index] < arrays[top.index].size())
		{
			minHeap.push(pair(arrays[top.index][index[top.index]], top.index));
			index[top.index]++;
		}
	}
	return res; 
}


struct Pair {
    int value;
    int array_index;
    
    Pair() {}
    Pair(int v, int i): value(v), array_index(i) {}
    
    bool operator>(const Pair &other) const{
        return value > other.value;
    }
};


static vector<int> kWayMerge3(vector<vector<int>> arrays) {
    vector<int> result;
    int k = arrays.size();
    vector<int> index(k, 0);
    priority_queue<Pair, vector<Pair>, greater<Pair> > minHeap;
    
    for (int i = 0; i < k; i++) {
        if (arrays[i].size() > 0) {
            minHeap.push(Pair(arrays[i][0], i));
            index[i]++;
        }
    }
    while (!minHeap.empty()) {
        Pair p = minHeap.top();
        minHeap.pop();
        result.push_back(p.value);
        if (index[p.array_index] < arrays[p.array_index].size()) {
            minHeap.push(Pair(arrays[p.array_index][index[p.array_index]], 
                              p.array_index));
            index[p.array_index]++;
        }
    }
    return result;
}

static TreeNode* copyBinaryTree(TreeNode *root)
{
	if (root == NULL)
	{
		return NULL; 
	}
	TreeNode *res = new TreeNode(root->val); 
	res->right = copyBinaryTree(root->right); 
	res->left = copyBinaryTree(root->left); 
	return res; 
}

struct GraphNode
{
	int val; 
	vector<GraphNode *> nodes; 
	GraphNode(int val_): val(val_){};

};

static GraphNode* copyGraph(GraphNode *root)
{
	// this doesn't work
	//unordered_set<GraphNode *> hash;
	unordered_map<GraphNode*, GraphNode*> hash; 
	return deepCopy(root, hash); 
}

static GraphNode* deepCopy(GraphNode *root, unordered_map<GraphNode*, GraphNode*> hash)
{
	if (hash.find(root) != hash.end())
	{
		return hash[root]; 
	}
	GraphNode *res = new GraphNode(root->val); 
	hash[root] = res;
	for (int i = 0; i < root->nodes.size(); i++)
	{		 
		res->nodes.push_back(deepCopy(root->nodes[i], hash)); 
	}
	return res; 
}

static void findMinMax(vector<int> arr, int &theMin, int &theMax)
{
	int n = arr.size(); 
	if (n == 1)
	{
		theMin = arr[0]; 
		theMax = arr[0]; 
		return;
	}
	if (arr[0] > arr[1])
	{
		theMin = arr[1]; 
		theMax = arr[0]; 
	}
	else
	{
		theMin = arr[0]; 
		theMax = arr[1]; 
	}
	for (int i = 2; i < n - 1; i +=2)
	{
		if (arr[i] > arr[i + 1])
		{
			theMin = min(theMin, arr[i + 1]); 
			theMax = max(theMax, arr[i]); 
		}
		else
		{
			theMin = min(theMin, arr[i]); 
			theMax = max(theMax, arr[i + 1]); 
		}
	}
	if (n % 2 == 1)
	{
		theMin = min(theMin, arr[n - 1]); 
		theMax = max(theMax, arr[n - 1]); 
	}
	return; 
}

static vector<int> findMaxSum(vector<int> arr, int &sum)
{
	int l = 0; 
	int r = 0; 
	int n = arr.size();
	vector<int> res; 
	if (n == 0)
	{
		return res; 
	}
	int maxSum = arr[0]; 
	int curSum = 0; 
	for (int i = 0; i < n; i++)
	{
		if (curSum > 0)
		{
			curSum += arr[i]; 
		}
		else
		{
			curSum = arr[i];
			l = i; 
			r = i; 
		}
		if (curSum > maxSum)
		{
			maxSum = curSum; 
			r = i; 
		}
	}
	for (int i = l; i <= r; i++)
	{
		res.push_back(arr[i]); 
	}
	sum = maxSum; 
	return res; 
}

static     int jump(int A[], int n) {
        int step = 0; 
        int i = n - 1; 
        while (i > 0)
        {
			bool canJump = false; 
            for (int j = 0; j < i; j++)
            {
                if (A[j] + j >= i)
                {
                    i = j; 
                    step++; 
					canJump = true;
                    break;					
                }
            }
			if (!canJump)
			{
				return INT_MAX; 
			}
        }
        return step; 

    }

static string removeDuplicate2(string s)
{
	int n = s.size(); 
	int i = 0; 
	int j = 0; 
	while (j < n)
	{
		if (s[i] == s[j])
		{
			j++; 
		}
		else
		{
			i++; 
			s[i] = s[j]; 
			j++; 
		}
	}
	return s.substr(0, i + 1); 
}

static void replaceWildCard (std::string str, size_t pos)
{
    if (pos >= str.size()) {
        std::cout << str << std::endl;
        return;
    }
    if (str[pos] == '*') {
        str[pos] = '0';
        replaceWildCard (str, pos + 1);
        str[pos] = '1';
        replaceWildCard (str, pos + 1);
    }
    else {
        replaceWildCard(str, pos + 1);
    }
}

static vector<string> replaceWildCard2(string s)
{
	vector<string> res; 
	string tempRes = s; 
	dfs92(s, 0, tempRes, res); 
	return res; 
}

static void dfs92(string &source, int i, string &tempRes, vector<string> &res)
{
	int n = source.size(); 
	if (i == n )
	{
		res.push_back(tempRes);
		return; 
	}
	
	if (source[i] == '*')
	{
		tempRes[i] = '0'; 
		dfs92(source, i+1, tempRes, res); 
		tempRes[i] = '1'; 
		dfs92(source, i+1, tempRes, res); 
	}
	else
	{
		dfs92(source, i+1, tempRes, res); 
	}
}

static vector<string> replaceWildCard3(string s)
{
	vector<string> res; 
	string tempRes = ""; 
	dfs92_1(s, 0, tempRes, res); 
	return res; 
}
static void dfs92_1(string &source, int start, string &tempRes, vector<string> &res)
{
	int n = source.size(); 
	if (start == n )
	{
		res.push_back(tempRes);
		return; 
	}
	
	if (source[start] != '*')
	{
		tempRes.push_back(source[start]);
		dfs92_1(source, start + 1, tempRes, res); 
		tempRes.pop_back(); 
	}
	else
	{
		tempRes.push_back('1'); 
		dfs92_1(source, start + 1, tempRes, res); 
		tempRes.pop_back(); 
		tempRes.push_back('0');
		dfs92_1(source, start + 1, tempRes, res); 
		tempRes.pop_back(); 
	}
	
	
}
// a pair of indexes
struct pair2
{
	int i1; 
	int i2;
	int sum; 
	pair2(int i1_, int i2_, int sum_): i1(i1_), i2(i2_), sum(sum_){}
	bool operator > (const pair2 &other) const
	{
		return sum > other.sum; 
	}
}; 


static int findksmallest(vector<int> arr1, vector<int> arr2, int k)
{
	int n1 = arr1.size(); 
	int n2 = arr2.size(); 
	priority_queue<pair2, vector<pair2>, greater<pair2>> minHeap;
	unordered_set<int> hash; // hash the index of i1*n2 + i2
	pair2 p0(0,0, arr1[0]+arr2[0]);
	hash.insert(0); 
	minHeap.push(p0);
	while (!minHeap.empty())
	{
		pair2 top = minHeap.top(); 
		minHeap.pop();
		k--; 
		if (k == 0)
		{
			return top.sum; 
		}
		if (top.i1 + 1 < n1 && hash.find((top.i1 + 1)* n2 + top.i2) == hash.end())
		{
			minHeap.push(pair2(top.i1 + 1, top.i2, arr1[top.i1 + 1] + arr2[top.i2]));
			hash.insert((top.i1 + 1)* n2 + top.i2); 
		}
		if (top.i2 + 1 < n2 && hash.find(top.i1 * n2 + top.i2 + 1) == hash.end())
		{
			minHeap.push(pair2(top.i1, top.i2 + 1, arr1[top.i1] + arr2[top.i2 + 1]));
			hash.insert(top.i1 * n2 + top.i2 + 1);
		}
	} 
	return INT_MAX; 
}


struct Node {
    int index1;
    int index2;
    int sum;
};
friend bool operator < (Node a, Node b){
    return a.sum > b.sum;
}
static int findKthSmallest(vector<int>& a1, vector<int>& a2, int k) {
    int n1 = a1.size();
    int n2 = a2.size();
    priority_queue<Node> my_heap;
    unordered_map<int, bool> visited;
    int index1 = 0;
    int index2 = 0;
    if (k == 1) return a1[index1] + a2[index2];
    Node start;
    start.index1 = 0;
    start.index2 = 0;
    start.sum = a1[index1] + a2[index2];
    visited[index2 * n2 + index1] = true;
    my_heap.push(start);
    while (k > 0 && index1 < n1 && index2 < n2) {
        if (k == 1) return my_heap.top().sum;
        index1 = my_heap.top().index1;
        index2 = my_heap.top().index2;
        if (index1 != n1 - 1 && index2 != n2 - 1) {
            Node next1;
            next1.index1 = my_heap.top().index1 + 1;
            next1.index2 = my_heap.top().index2;
            next1.sum = a1[index1 + 1] + a2[index2];
            if (visited.find(next1.index2 * n1 + next1.index1) == visited.end()) {
                visited[next1.index2 * n1 + next1.index1] = true;
                //cout<<"push "<<next1.index1<<" "<<next1.index2<<" "<<next1.sum<<endl;
                my_heap.push(next1);
            }
            Node next2;
            next2.index1 = my_heap.top().index1;
            next2.index2 = my_heap.top().index2 + 1;
            next2.sum = a1[index1] + a2[index2 + 1];
            if (visited.find(next2.index2 * n1 + next2.index1) == visited.end()) {
                visited[next2.index2 * n1 + next2.index1] = true;
                //cout<<"push "<<next2.index1<<" "<<next2.index2<<" "<<next2.sum<<endl;
                my_heap.push(next2);
            }
            if (next1.sum < next2.sum)
                index1++;
            else
                index2++;
        } else if (index1 == n1 - 1 && index2 == n2 - 1) {
            break;
        } else if (index1 == n1 - 1) {
            Node next2;
            next2.index1 = my_heap.top().index1;
            next2.index2 = my_heap.top().index2 + 1;
            next2.sum = a1[index1] + a2[index2 + 1];
            if (visited.find(next2.index2 * n1 + next2.index1) == visited.end()) {
                visited[next2.index2 * n1 + next2.index1] = true;
                //cout<<"push "<<next2.index1<<" "<<next2.index2<<" "<<next2.sum<<endl;
                my_heap.push(next2);
            }
            index2++;
        } else {
            Node next1;
            next1.index1 = my_heap.top().index1 + 1;
            next1.index2 = my_heap.top().index2;
            next1.sum = a1[index1 + 1] + a2[index2];
            if (visited.find(next1.index2 * n1 + next1.index1) == visited.end()) {
                visited[next1.index2 * n1 + next1.index1] = true;
                //cout<<"push "<<next1.index1<<" "<<next1.index2<<" "<<next1.sum<<endl;
                my_heap.push(next1);
            }
            index1++;
        }
        my_heap.pop();
        k--;
    }
    while (k > 0 && !my_heap.empty()) {
        if (k == 1) return my_heap.top().sum;
        my_heap.pop();
        k--;
    }
    return -1;
}

static bool isBST830(TreeNode *root)
{
	return isBSTHelper830(root, INT_MIN, INT_MAX); 
}

static bool isBSTHelper830(TreeNode *root, int l, int r)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->val < l)
	{
		return false;
	}
	if (root->val > r)
	{
		return false;
	}
	return isBSTHelper830(root->left, l, root->val) && isBSTHelper830(root->right, root->val, r); 
}

static bool isTreeSame(TreeNode* root1, TreeNode* root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if (root1 == NULL || root2 == NULL)
	{
		return false; 
	}
	
	if (root1->val != root2->val)
	{
		return false;
	}
	return isTreeSame(root1->left, root2->left) && isTreeSame(root1->right, root2->right); 
}

static bool isTreeSymmetric(TreeNode* root)
{
	if (root == NULL)
	{
		return true; 
	}
	return isSymHelper(root->left, root->right); 
}

static bool isSymHelper(TreeNode *left, TreeNode *right)
{
	if (left == NULL && right == NULL)
	{
		return true;
	}
	if (left == NULL || right == NULL)
	{
		return false;
	}
	if (left->val != right->val)
	{
		return false; 
	}
	return isSymHelper(left->left, right->right) && isSymHelper(left->right, right->left); 
}

static TreeNode* LCA831(TreeNode* root, TreeNode *node1, TreeNode *node2)
{
	if (root == NULL)
	{
		return NULL; 
	}
	if (root == node1)
	{
		return node1; 
	}
	if (root == node2)
	{
		return node2; 
	}
	TreeNode* left = LCA831(root->left, node1, node2); 
	TreeNode* right = LCA831(root->right, node1, node2); 
	if (left != NULL && right != NULL)
	{
		return root; 
	}
	else
	{
		if (left != NULL)
		{
			return left; 
		}
		else
		{
			return right; 
		}
	}
}
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

static    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> hash; 
        if (head == NULL)
        {
            return NULL; 
        }
        // copy the head;
        RandomListNode *newHead = new RandomListNode(head->label); 
        RandomListNode *pNew = newHead; 
        RandomListNode *p = head; 
        hash[p] = pNew; 
        // copy the list
        while (p->next!=NULL)
        {
			RandomListNode *newNode = new RandomListNode(p->next->label); 
			pNew->next = newNode; 
			pNew = pNew->next; 
			p = p->next; 
        }
        
        p = head; 
        pNew = newHead;
        // copy the randm pointer
        while (p!= NULL)
        {
            pNew->random = hash[p->random];  
            p = p->next; 
            pNew = pNew->next; 
        }
        return newHead; 

      
    }

static   RandomListNode *copyRandomList2(RandomListNode *head) {
        // Use a hashMap to store the random pointer relationship between original and copy
        unordered_map <RandomListNode*, RandomListNode*> hashmap; 
        
        if (head == NULL)
        {
            return NULL; 
        }
        RandomListNode *newHead = new RandomListNode(head->label); 
        // copy the linked list
        RandomListNode *cur = head;
        RandomListNode *curCopy = newHead;
        hashmap[cur] = curCopy; 
        while (cur->next != NULL)
        {
            RandomListNode *temp = new RandomListNode(cur->next->label); 
            curCopy->next = temp; 
            cur = cur->next; 
            curCopy = temp;
            hashmap[cur] = curCopy; 
        }
        
        // copy the random pointers
        cur = head;
        curCopy = newHead;
        while (cur != NULL)
        {
           curCopy->random = hashmap[cur->random]; 
           cur = cur->next; 
           curCopy = curCopy->next; 
        }
        
        return newHead;
      
    }

struct lNode
{
	int val; 
	lNode* next; 
};
static lNode* reverseLinkedList(lNode* head)
{
	lNode* pre = NULL; 
	lNode* cur = head; 
	lNode* next = head->next; 
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur; 
		cur = next; 
	}
	return pre; 
}

static void permute92(string &s, int start, vector<string> &res)
{
	int n = s.size(); 
	if (start == n - 1)
	{
		res.push_back(s); 
	}
	for (int i = start; i < n; i++)
	{
		swap(s, i, start); 
		permute92(s, start + 1, res); 
		swap(s, i, start); 
	}	
}

static string LongestCommonSubstring(string s1, string s2)
{
	string res  = ""; 
	int m = s1.size(); 
	int n = s2.size(); 
	if (m == 0 || n == 0)
	{
		return ""; 
	}
	vector< vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
	int maxLength = 0; 
	int maxI; 
	int maxJ; 
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (s1[i - 1] == s2[ j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1; 
				if (dp[i][j] > maxLength)
				{
					maxLength = dp[i][j]; 
					maxI = i; 
					maxJ = j; 
				}
			}
		}
	}
	return s2.substr(maxJ - maxLength, maxLength); 
}

struct node
{
	int index; 
	int val; 
	node(int index_, int val_): index(index_), val(val_){}
	bool operator > (const node& other) const
	{
		return val > other.val; 
	}
}; 
static int findKthSmallest2D(const vector<vector<int>> &mat, int k)
{
	int m = mat.size(); 
	int n = mat[0].size(); 
	int res = INT_MIN; 
	if (m == 0 && n == 0)
	{
		return res; 
	}
	priority_queue<node, vector<node>, greater<node>> minHeap;
	unordered_set<int> hash; // for deduplicate. 
	minHeap.push(node(0, mat[0][0])); 
	hash.insert(0); 
	while (!minHeap.empty())
	{
		node top = minHeap.top(); 
		minHeap.pop();
		k--;
		if (k == 0)
		{
			return top.val; 
		}
		int i = top.index / n; 
		int j = top.index % n; 
		int c1 = (i + 1) * n + j; 
		int c2 = i * n + j + 1; 
		if (i + 1 < m && hash.find(c1) == hash.end())
		{
			minHeap.push(node(c1, mat[i + 1][j])); 
			hash.insert(c1); 
		}
		if (j + 1 < n && hash.find(c2) == hash.end())
		{
			minHeap.push(node(c2, mat[i][j + 1])); 
			hash.insert(c2); 
		}
	}
	return res; 
}

static int longestConsecutiveOneFlip(vector<int> arr)
{
    vector<int> f(2, 0), g(2, -1);
    int maxL = 0;
	// let g0, g1 be the longest consecutive 0's and 1's with one flip
	// let f0, f1 be the longest consecutive 0's and 1's with no flip
	// if x = 0, then f1 = 0, f0++, g0++, g1 = f1 + 1
	// if x = 1, then f0 = 1, f1++, g0 = f1 + 1, g1++

    for (int i = 0; i < arr.size(); i ++) {
		int x = arr[i]; 
        g[x]++;
        g[1-x] = f[1-x] + 1;
        f[x]++;
        f[1-x] = 0;
        maxL = max(maxL, g[x]);
    }
    return maxL;
}

static int longestConsecutiveOneFlip2(vector<int> arr)
{
	int maxL = INT_MIN;
	// let g0, g1 be the longest consecutive 0's and 1's with one flip
	// let f0, f1 be the longest consecutive 0's and 1's with no flip
	// if x = 0, then f1 = 0, f0++, g0++, g1 = f1 + 1
	// if x = 1, then f0 = 0, f1++, g0 = f0 + 1, g1++
	int f0 = 0; 
	int f1 = 0; 
	int g0 = 0; 
	int g1 = 0; 
	for (int i = 0; i < arr.size(); i++)
	{
		int x = arr[i]; 
		if (x == 0)
		{
			g1 = f1 + 1;
			f0++; 
			f1 = 0; 
			g0++;			 
		}
		else
		{
			g0 = f0 + 1;			
			f0 = 0; 
			f1++; 
			g1++; 
		}
		maxL = max(g0, g1); 
	}
	return maxL; 
}


struct node1
{
	int index; 
	int val;
	node1(int index_, int val_): index(index_), val(val_){}
	bool operator > (const node1& other) const
	{
		return val > other.val; 
	}
};

static int findKthSmallest2d(const vector<vector<int>> &mat, int k)
{
	int res = INT_MIN; 
	int m = mat.size(); 
	if (m == 0)
	{
		return res;
	}
	int n = mat[0].size(); 
	if (n == 0)
	{
		return res;
	}
	priority_queue<node1, vector<node1>, greater<node1>> minHeap;
	unordered_set<int> hash; // store i * n + j, avoid duplicates
	minHeap.push(node1(0, mat[0][0])); 
	hash.insert(0); 
	while (!minHeap.empty())
	{
		node1 top = minHeap.top();
		minHeap.pop(); 
		k--; 
		if (k == 0)
		{
			return top.val; 
		}
		int i = top.index / n; 
		int j = top.index % n; 
		// two candidates
		int c1 = (i + 1) * n + j; 
		int c2 = i * n + j + 1; 
		if ( i + 1 < m && hash.find(c1) == hash.end())
		{
			minHeap.push(node1(c1, mat[i + 1][j])); 
			hash.insert(c1); 
		}
		if ( j + 1 < n && hash.find(c2) == hash.end())
		{
			minHeap.push(node1(c2, mat[i][j + 1]));
			hash.insert(c2); 
		}
	}
	return res; 
}

static void insertMinHeap(vector<int> &arr, int x)
{
	arr.push_back(x); 
	int n = arr.size();
	int curI = n - 1; // current index 
	int parI = (curI - 1) / 2; // parent index
	while (arr[curI] < arr[parI] && curI >=0 && parI >= 0)
	{
		//int temp = arr[parI]; 
		//arr[parI] = arr[curI];
		arr[curI] = arr[parI]; 
		curI = parI; 
		parI = (curI - 1) / 2;
	}
	arr[curI] = x; 
}
//3  5  7
//|  |  |
//1->2->4->6

//to 
//3  5  7
//|  |  |
//1<-2<-4<-6

//to
//   3  5  7
//   |  |  |
//1<-2<-4<-6

/*
1-3
V
2-5
V
4-7 
V
6
*/

// to
/*
6
V
4-7
V
2-5
V
1-3
*/

// to
/*
7-6
  V
5-4
  V
3-2
  V
  1
*/

static TreeNode *reverseTree(TreeNode *root)
{
	if (root == NULL)
	{
		return NULL; 
	}
	TreeNode *cur = root; 
	TreeNode *pre = NULL; 
	TreeNode *left = cur->left; 
	TreeNode *right = cur->right; 
	while (cur != NULL)
	{
		left = cur->left;
		right = cur->right; 
		cur->right = pre;
		cur->left = right; 
		pre = cur; 		
		cur = left;
	}
	TreeNode *newRoot = pre;
	cur = pre; 
	while (cur->right != NULL)
	{
		cur->left = cur->right->left; 
		cur = cur->right; 
	}
	cur->left = NULL; 
	return newRoot; 
}

/*
3  5
|  |
1->2->4


3  5
|  |
1<-2<-4

   3  5
   |  |
1<-2<-4


*/
TreeNode* reverseTree2(TreeNode *root)
{
	if (root == NULL)
	{
		return NULL; 
	}
	TreeNode *cur = root; 
	TreeNode *pre = NULL; 
	TreeNode *left = root->left; 
	TreeNode *right = root->right; 
	while (cur != NULL)
	{
		left = cur->left; 
		right = cur->right; 
		cur->right = pre;		
		cur->left = right; 
		pre = cur;
		cur = left; 
	}
	TreeNode *newRoot = pre; 
	cur = pre; 
	while (cur->right != NULL)
	{
		cur->left = cur->right->left; 
		cur = cur->right;
	}
	cur->left = NULL; 
	return newRoot; 
}

// find Kth in two sorted arrrays
// a1 and a2 are the two sorted arrays
// l1 and r1 are search range in a1, 
// l2 and r2 are search range in a2
static int findK(const vector<int> & a1, const vector<int> & a2, int l1, int l2, int k)
{
	int r1 = a1.size() - 1; 
	int r2 = a2.size() - 1;
	if (k > a1.size() + a2.size())
	{
		return INT_MAX; 
	}
	if (l1 > r1 && l2 > r2)
	{
		return 0; 
	}
	if (l1 > r1)
	{
		return a2[l2 + k - 1]; 
	}
	if (l2 > r2)
	{
		return a1[l1 + k - 1]; 
	}
	if (k == 1)
	{
		return min(a1[l1], a2[l2]); 
	}
	//int m = r1 - l1 + 1; 
	//int n = r2 - l2 + 1; 

	int count1 = k / 2; //k * (float) m / (float)(m + n);
	//count1 = count1 > 0? count1 : 1; 
	int count2 = k - count1; 

	int v1 = a1[l1 + count1 - 1]; 
	int v2 = a2[l2 + count2 - 1]; 

	if (v1 == v2)
	{
		return v1;
	}
	if (v1 < v2)
	{
		return findK(a1, a2, l1 + count1, l2, k - count1); 
	}
	if (v1 > v2)
	{
		return findK(a1, a2, l1, l2 + count2, k - count2); 
	}
}

static int findKthSmallestBinary(int A[], int m, int B[], int n, int k)
    {
		if (k > m + n)
		{
			return INT_MAX; 
		}
		
        if (m == 0 && n == 0)
        {
            return 0; 
        }
        if (m == 0)
        {
            return B[k - 1]; 
        }
        if (n == 0)
        {
            return A[k - 1]; 
        }
        if (k == 1)
        {
            return min(A[0], B[0]); 
        }
        
        int ia = (double)m / (double)(m + n) * (k - 1); 
        int ib = k - 2 - ia; // because k = (ia + 1) + (ib + 1); 
        if (A[ia] == B[ib])
        {
            return A[ia]; 
        }
        else
        {
            if (A[ia] > B[ib])
            {
                return findKthSmallestBinary(A, ia + 1, &B[ib + 1], n - ib - 1, k - ib - 1); 
            }
            else
            {
                return findKthSmallestBinary(&A[ia + 1], m - ia - 1, B, ib + 1, k - ia - 1); 
            }        
        }    
    }

// find the longest sub-string with less then k distinct characters
static string findSubStr(const string &s, int k)
{
	int maxL = 0; 
	int maxI = 0;
	int maxJ = 0; 
	int n = s.size(); 
	vector<int> count(256, 0);
	int nDis = 0; // distinct char count
	int i = 0;  
	for (int j = 0; j < n; j++)
	{
		int cj = s[j] - 'a';  // the character 
		count[cj]++; 
		if (count[cj] == 1)
		{
			nDis++; 
		}
		while (nDis > k)
		{
			int ci = s[i] - 'a'; 
			count[ci]--; 
			if (count[ci] == 0)
			{
				nDis--; 
			}
			i++;
		}
		if (j - i + 1 > maxL)
		{
			maxL = j - i + 1; 
			maxI = i; 
			maxJ = j; 
		}

	}
	return s.substr(maxI, maxL); 
}

// doesn't work because input array size is always 1 if array is passed in as a parameter
//template<typename T>
//static vector<T> initVector(T input[])
//{
//	return vector<T>(input, input + sizeof(input) / sizeof(T)); 
//}
//
//	#include <iostream>
//#include <stack>
//using namespace std;
//
//const char leftP[] = "([{";
//const char rightP[] = ")]}";
//
//void generateParentheses(int n[], int l[], int r[], stack<char> s, string sol) {
//    bool ok = true;
//    for (int i = 0; i < 3; i++) {
//        if (r[i] < n[i]) {
//            ok = false;
//            break;
//        }
//    }
//    if (ok) {
//        cout << sol << endl;
//    }
//    
//    for (int i = 0; i < 3; i++) {
//        if (l[i] < n[i]) {
//            s.push(leftP[i]);
//            l[i]++;
//            generateParentheses(n, l, r, s, sol+leftP[i]);
//            s.pop();
//            l[i]--;
//        }
//    }
//    for (int i = 0; i < 3; i++) {
//        if (r[i] < l[i]) {
//            if (s.top() == leftP[i]) {
//                s.pop();
//                r[i]++;
//                generateParentheses(n, l, r, s, sol+rightP[i]);
//                s.push(leftP[i]);
//                r[i]--;
//            }
//        }
//    }
//}

//int main()
//{
//    int n[] = {1, 2, 1}; // number for each type of parentheses
//    int l[] = {0, 0, 0}; // number of left parentheses that have been generated
//    int r[] = {0, 0, 0}; // ..........right........
//    stack<char> s;
//    string sol;
//    generateParentheses(n, l, r, s, sol);  
//    return 0;
//}




	//static int largestSumMatrix(std::vector<std::vector<int>> ma,  int colSize,int rowSize)
	//{

	//	// find the sum of every matrix starting at (0,0)
	//	// the sum of sub matrix (top, left) to (bottom, right) is equal to sum(bottom,right) - sum(top, right) - sum(bototm, left) + sum(top, left)
	//	//int **sum; 
	//	//sum = new int*[rowSize]; 
	//	//for (int i = 0; i < rowSize; i++)
	//	//{
	//	//	sum[i] = new int[colSize]; 
	//	//}
	//	const int m = rowSize; 
	//	const int n = colSize; 
	//	int sum[m][n]; 
	//	for (int i = 0; i < rowSize; i ++)
	//		for (int j = 0; j < colSize; j++)
	//		{
	//			sum[i][j]
	//		}

	//}

//	int largestSquare(std::vector<std::vector<int>>& matrix) {
//    if (matrix.size() < 1 || matrix[0].size() < 1) {
//		return 0;
//	}
//    const int m = (const int)matrix.size();
//    const int n = (const int)matrix[0].size();
//    int temp[m][n];
//
//	// initialize the borders (our base cases)
//	for (int r = 0; r < m; r++) {
//		temp[r][0] = matrix[r][0];
//	}
//	for (int c = 0; c < n; c++) {
//		temp[0][c] = matrix[0][c];
//	}
//
//	for (int r = 1; r < m; r++) {
//		for (int c = 1; c < n; c++) {
//			if (matrix[r][c] == 1) {
//				temp[r][c] = 1 + min(temp[r][c-1],
//								min(temp[r-1][c],
//								temp[r-1][c-1]));
//			} else {
//				temp[r][c] = 0;
//			}
//		}
//	}
//	// find the largest entry
//	int maxV = INT_MIN;
//	for (int r = 0; r < m; r++) {
//		for (int c = 0; c < n; c++) {
//			maxV = max(maxV, temp[r][c]);
//		}
//	}
//    return maxV;
//}


};

class Hanoi
{
public: 
	// hanoi
	std::stack<int> tower1; 
	std::stack<int> tower2; 
	std::stack<int> tower3; 

public: 
	void initStack(int stackSize)
	{
		for (int i = 0; i < stackSize; i++)
		{
			tower1.push(stackSize - i - 1); 
		}
	}

	void hanoi(int diskSize, std::stack<int> &origin, std::stack<int> &temp, std::stack<int> &target)
	{
		if (diskSize == 1 )
		{
			int top = origin.top(); 
			origin.pop(); 
			target.push(top); 
		}
		else
		{
			hanoi(diskSize - 1, origin, target, temp); 
			int top = origin.top(); 
			origin.pop();
			target.push(top); 
			hanoi(diskSize - 1, temp, origin, target); 
		}
	}

}; 

class LinkedList
{
	/// testReverseLinkedList
public: 
	Node *llHead;// = new Node(); 
	void push (Node* &head, int val)
	{
		if (head == NULL)
		{
			head = new Node(); 
			head->val = val; 
		}
		else 
		{
			Node *currentNode = head; 
			while (currentNode->next != NULL)
			{
				currentNode = currentNode->next;  
			}
			currentNode->next = new Node(); 
			currentNode->next->val = val; 

		}    
	}


	void init(int count)
	{
		//llHead = new Node();
		for (int i = 0; i < count; i++)
		{
			push(llHead, i); 
		}
	}

	Node *ReverseLinkedList(Node *head)
	{
		if (head == NULL)
		{
			return NULL; 
		}
		else if (head->next == NULL)
		{
			return head;
		} 
		else
		{
			Node *nextHead = ReverseLinkedList(head->next);
			head->next->next = head;
			head->next = NULL; 
			return nextHead;  
		}
	}

	
	Node *ReverseLinkedList1(Node *head)
	{
		if (head == NULL)
		{
			return NULL; 
		}
		Node *cur = head; 
		Node *next = head->next; 
		
		head->next = NULL; 
		while (next != NULL)
		{
			Node *temp = next->next; 
			next->next = cur;
			cur = next; 
			next = temp;
		}
		return cur; 
	}


	Node *ReverseLinkedList2(Node* head)
	{
		Node* prev = NULL; 
		Node* curr = head; 
		Node* next; 
		while (curr)
		{
			next = curr->next; 
			curr->next = prev; 
			prev = curr; 
			curr = next; 
		}
		return prev; 
	}

	Node *ReverseLinkedListRecursive(Node *head)
	{
		if (head == NULL)
		{
			return NULL;
		}
		if (head->next == NULL)
		{
			return head; 
		}
		Node *result = ReverseLinkedListRecursive(head->next);
		head->next->next= head; 
		head->next = NULL;
		return result; 
	}

	void testReverseLinkedList()
	{
		llHead = NULL; 
		init(10);

		Node *currentNode = llHead; 
		printf("before reverse:\n"); 
		while (currentNode!=NULL)
		{ 
			printf(" %d", currentNode->val); 
			currentNode = currentNode->next;
		}
		llHead = ReverseLinkedList1(llHead);
		//llHead = ReverseLinkedList2(llHead);
		//llHead = ReverseLinkedListRecursive(llHead); 

		printf("\nafter reverse:\n");
		currentNode = llHead; 
		while (currentNode!=NULL)
		{
			printf(" %d", currentNode->val); 
			currentNode = currentNode->next;
		}
		printf("\n"); 

	}
	/// end testReverseLinkedList




}; 

class LongestString
{
public: 
	// Sort words by length in descending order
//bool &comp(const string &a, const string &b) {
//    return a.size() > b.size();
//}

// Time Complexity: O(nm^2 + nlogn), where n is number of words and
// m is average length of words
// Space Complexity: O(n)
//string longestWord(vector<string> &dict) {
//    unordered_set<string> set;
//    sort(dict.begin(), dict.end(), comp);
//    for (int i = 0; i < dict.size(); i++) {
//        set.insert(dict[i]);
//    }
//    //for (int i = 0; i < dict.size(); i++) {
//    //    for (int k = 1; k < dict[i].size(); k++) {
//    //        string substr1 = dict[i].substr(0, k);
//    //        string substr2 = dict[i].substr(k);
//    //        if (set.find(substr1) != set.end() && 
//    //            set.find(substr2) != set.end()) {
//    //            return dict[i];
//    //        }
//    //    }
//    //    break;
//    //}
//    return "";
//}
};

class LRUCache{
struct cacheNode
{
    int key; 
    int val; 
    cacheNode (int key_, int val_): key(key_), val(val_)
    {
    }
};     
private: 
    unordered_map<int, list<cacheNode>::iterator> addMap; 
    list<cacheNode> cacheList; 
    
public:
    int size; 
    LRUCache(int capacity) {
        size = capacity; 
    }
    
    int get(int key) {
        if (addMap.find(key) != addMap.end())
        {
            moveToHead(key);
            cacheNode node = *addMap[key];
            return node.val;
        }
        else
        {
            return -1; 
        }
    }
    
    void set(int key, int value) {
        if (addMap.find(key) != addMap.end())
        {
            cacheNode *node = &*addMap[key];
            addMap[key]->val = value; 
            moveToHead(key); 
        }
        else
        {
            if (addMap.size() == size)
            {
                addMap.erase(cacheList.back().key); 
                cacheList.pop_back(); 
                
            }
            cacheNode node(key,value); 
            cacheList.push_front(node); 
            addMap[key] = cacheList.begin(); 
        }
        
    }
    
    void moveToHead(int key)
    {
        cacheNode node = *addMap[key]; 
        cacheList.erase(addMap[key]); 
        cacheList.push_front(node); 
        addMap[key] = cacheList.begin(); 
    }
};
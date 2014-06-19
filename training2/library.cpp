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

#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left; 
	TreeNode *right; 
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


	static void permute(std::vector<int> &input, int head, std::vector<std::vector<int>> &output)
	{
		int size = input.size(); 
		if (head == size - 1)
		{
			output.push_back(input);
			return; 
		}
		for (int i = head; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				swap(input, i, j);  
				permute(input, i + 1, output); 
				swap(input, i, j); 
			}
		}
		output.push_back(input); 
	}

	static void permute2(std::vector<int> &input, int i, std::vector<std::vector<int>> &output)
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
			permute2(input, i + 1, output); 
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



	static void generateParentheses(int n[], int l[], int r[], stack<char> s, string sol) {
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
			return; 
		}
    
		for (int i = 0; i < 3; i++) {
			if (l[i] < n[i]) {
				s.push(leftP[i]);
				l[i]++;
				generateParentheses(n, l, r, s, sol+leftP[i]);
				s.pop();
				l[i]--;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (r[i] < l[i]) {
				if (s.top() == leftP[i]) {
					s.pop();
					r[i]++;
					generateParentheses(n, l, r, s, sol+rightP[i]);
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
		if (l<n)
		{
			permuteParenthesis(r, l+1, n, currentStr +"(", result); 
		}
		if (r<l)
		{
			permuteParenthesis(r+1, l, n, currentStr +")", result); 
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

		;  
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

	//find kth smallest 3^x*4^y*7^z
	static int findKthSmallest347(int k)
	{
		unordered_set<int> visited; 
		priority_queue<node347> heap; 
		int popCount = 0; 
		int result = 0; 
		heap.push(node347(1, 1, 1));
		node347 popped(0, 0, 0); 
		while (!heap.empty() && popCount<k)
		{
			popped = heap.top(); 
			visited.insert(popped.val); 
			heap.pop(); 
			node347 xNext(popped.x + 1, popped.y, popped.z); 
			node347 yNext(popped.x, popped.y + 1, popped.z); 
			node347 zNext(popped.x, popped.y, popped.z + 1); 
			if (visited.find(xNext.val) == visited.end())
			{
				heap.push(xNext);
			}
			if (visited.find(yNext.val) == visited.end())
			{
				heap.push(yNext); 
			}
			if (visited.find(zNext.val) == visited.end())
			{
				heap.push(zNext); 
			}
			popCount++; 
		}
		return popped.val; 
	}



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
		//llHead = ReverseLinkedList(llHead);
		llHead = ReverseLinkedList2(llHead);

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
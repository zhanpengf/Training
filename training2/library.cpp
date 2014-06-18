#include "stdafx.h"
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

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

	// intened to generated all permutations without vaild parenthesis constraint. doesn't work. 
	static void permuteParenthesis2(int r, int l, int n, string currentStr, vector<string> &result)
	{
		if ((r==n) && (l==n))
		{
			result.push_back(currentStr); 
			return; 
		}

		if (l<n)
		{
			permuteParenthesis(r, l+1, n, currentStr +"(", result);
		}
		if (r<n)
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
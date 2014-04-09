#include "stdafx.h"
#include <vector>
#include <stack>
#include <stdlib.h>
#include <time.h>

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
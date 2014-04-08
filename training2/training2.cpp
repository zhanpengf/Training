// training2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "library.cpp"
#include <time.h>


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

	// permutation 
	{
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
	return 0;
}




#include "tree.h"
#include <iostream>


int main()
{
	int choice;
	int height = 0;
	int removed = 0;
	int input = 0;
	int count = 0;
	choice = 0;
	tree myTree;
	myTree.populate();

	while (choice != 8)
	{
		std::cout << "Press 1 to display every number in the tree." << "\n";
		std::cout << "Press 2 to display the height of the tree.\n";
		std::cout << "Press 3 to display the root of the tree.\n";
		std::cout << "Press 4 to remove every node in the tree.\n";
		std::cout << "Press 5 for a new tree.\n";
		std::cout << "Press 6 to remove a single node from the tree.\n";
		std::cout << "Press 7 to display the tree in order.\n";
		std::cout << "Press 8 to quit." << "\n";
		std::cin >> choice;

		switch(choice)
		{	case 1:
				std::cout << "------\n";
				count = myTree.display_all();
				std::cout << "\n" << count << " nodes in the tree.\n";
				std::cout << "\n------\n";
				break;
			case 2:
				height = myTree.get_height();
				std::cout << "-------------------------------\n";
				std::cout << "The height of this tree is: " << height << "\n";
				std::cout << "-------------------------------\n";
				break;
			case 3:
				int num;
				num = myTree.get_root_num();	
				std::cout << "-------------------------------\n";
				std::cout << "The root of this tree is: " << num << "\n";
				std::cout << "-------------------------------\n";
				break;
			case 4:
				removed = myTree.remove_all();	
				std::cout << removed << " nodes were deleted.\n";
				break;
			case 5:
				myTree.remove_all();
				myTree.populate();
				break;
			case 6:
				std::cout << "Which number would you like to remove?\n";
				std::cin >> input;
				myTree.remove_single(input);
				break;
			case 7:
				choice = 7;
				std::cout << "------\n";
				myTree.display_in_order();
				std::cout << "\n------\n";				
				break;
			case 8:
				choice = 8;
				std::cout << "Goodbye.\n";
				break;
			default:
				choice = 8;
				std::cout << "Goodbye.\n";
		}
	}
	return 0;
}

#include <iostream>
#include "GameController.h"

int main()
{
	try 
	{
		GameController d;
		d.run();
	}

	catch (const std::runtime_error& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
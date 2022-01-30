#include <iostream>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		std::cout << "Faltan argumentos" << "(" << argc << ")" << std::endl;
		return 0;
	}

	int now = atoi(argv[1]), full = atoi(argv[2]);
	float percent;

	percent = now*100.0/full;
	std::cout << "Battery: " << percent << "%" << std::endl;

	return 0;
}

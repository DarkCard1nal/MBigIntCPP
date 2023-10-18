#include "MBigIntCPP.h"

int main()
{
	std::cout << "Start Test! " << std::endl;

	MBigIntCPP num1("51bf608414ad5726");
	MBigIntCPP num2, num3;
	num2.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");

	std::cout << "Hex 1: " << num1.getHex() << std::endl;
	std::cout << "Hex 2: " << num2.getHex() << std::endl;
	std::cout << "Hex 3: " << num3.getHex() << std::endl << std::endl;

	num1.INV();
	std::cout << "Hex 1 inverted: " << num1.getHex() << std::endl;
	if (num1.getHex() == "AE409F7BEB52A8D9") // True value
		std::cout << "Hex 1 correctly inverted! " << std::endl << std::endl;
	else
		std::cout << "Hex 1 incorrectly inverted!!! " << std::endl << std::endl;

	num1.shiftL(5);
	std::cout << "Hex 1 << 5: " << num1.getHex() << std::endl;
	if (num1.getHex() == "15C813EF7D6A551B20") // True value
		std::cout << "Hex 1 correctly bit shift left! " << std::endl << std::endl;
	else
		std::cout << "Hex 1 incorrectly bit shift left!!! " << std::endl << std::endl;

	num1.shiftR(6);
	std::cout << "Hex 1 >> 6: " << num1.getHex() << std::endl;
	if (num1.getHex() == "57204FBDF5A9546C") // True value
		std::cout << "Hex 1 correctly bit shift right! " << std::endl << std::endl;
	else
		std::cout << "Hex 1 incorrectly bit shift right!!! " << std::endl << std::endl;

	num1.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
	num2.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
	num3 = MBigIntCPP::XOR(num1, num2);
	std::cout << "Hex 1: " << num1.getHex() << std::endl;
	std::cout << "Hex 2: " << num2.getHex() << std::endl;
	std::cout << "Hex 3 = XOR(Hex 1, Hex 2): " << num3.getHex() << std::endl;
	if (num3.getHex() == "1182D8299C0EC40CA8BF3F49362E95E4ECEDAF82BFD167988972412095B13DB8") // True value
		std::cout << "Hex 3 correctly XOR! " << std::endl << std::endl;
	else
		std::cout << "Hex 3 incorrectly XOR!!! " << std::endl << std::endl;

	num1.setHex("51bf608414ad5726a3c1bec098f77b1b54ffb2787f8d528a74c1d7fde6470ea4");
	num2.setHex("403db8ad88a3932a0b7e8189aed9eeffb8121dfac05c3512fdb396dd73f6331c");
	num3 = MBigIntCPP::OR(num1, num2);
	std::cout << "Hex 1: " << num1.getHex() << std::endl;
	std::cout << "Hex 2: " << num2.getHex() << std::endl;
	std::cout << "Hex 3 = OR(Hex 1, Hex 2): " << num3.getHex() << std::endl;
	if (num3.getHex() == "51BFF8AD9CAFD72EABFFBFC9BEFFFFFFFCFFBFFAFFDD779AFDF3D7FDF7F73FBC") // True value
		std::cout << "Hex 3 correctly OR! " << std::endl << std::endl;
	else
		std::cout << "Hex 3 incorrectly OR!!! " << std::endl << std::endl;

	num1.setHex("36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80");
	num2.setHex("70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb");
	num3 = MBigIntCPP::ADD(num1, num2);
	std::cout << "Hex 1: " << num1.getHex() << std::endl;
	std::cout << "Hex 2: " << num2.getHex() << std::endl;
	std::cout << "Hex 3 = ADD(Hex 1, Hex 2): " << num3.getHex() << std::endl;
	if (num3.getHex() == "A78865C13B14AE4E25E90771B54963EE2D68C0A64D4A8BA7C6F45EE0E9DAA65B") // True value
		std::cout << "Hex 3 correctly ADD! " << std::endl << std::endl;
	else
		std::cout << "Hex 3 incorrectly ADD!!! " << std::endl << std::endl;

	num1.setHex("36f028580bb02cc8272a9a020f4200e346e276ae664e45ee80745574e2f5ab80");
	num2.setHex("70983d692f648185febe6d6fa607630ae68649f7e6fc45b94680096c06e4fadb");
	num3 = MBigIntCPP::AND(num1, num2);
	std::cout << "Hex 1: " << num1.getHex() << std::endl;
	std::cout << "Hex 2: " << num2.getHex() << std::endl;
	std::cout << "Hex 3 = AND(Hex 1, Hex 2): " << num3.getHex() << std::endl;
	if (num3.getHex() == "309028480B200080262A080206020002468240A6664C45A80000016402E4AA80") // True value
		std::cout << "Hex 3 correctly AND! " << std::endl << std::endl;
	else
		std::cout << "Hex 3 incorrectly AND!!! " << std::endl << std::endl;

	num1.setHex("33ced2c76b26cae94e162c4c0d2c0ff7c13094b0185a3c122e732d5ba77efebc");
	num2.setHex("22e962951cb6cd2ce279ab0e2095825c141d48ef3ca9dabf253e38760b57fe03");
	num3 = MBigIntCPP::SUB(num1, num2);
	std::cout << "Hex 1: " << num1.getHex() << std::endl;
	std::cout << "Hex 2: " << num2.getHex() << std::endl;
	std::cout << "Hex 3 = SUB(Hex 1, Hex 2): " << num3.getHex() << std::endl;
	if (num3.getHex() == "10E570324E6FFDBC6B9C813DEC968D9BAD134BC0DBB061530934F4E59C2700B9") // True value
		std::cout << "Hex 3 correctly SUB! " << std::endl << std::endl;
	else
		std::cout << "Hex 3 incorrectly SUB!!! " << std::endl << std::endl;

	num1.setHex("7d7deab2affa38154326e96d350deee1");
	num2.setHex("97f92a75b3faf8939e8e98b96476fd22");
	num3 = MBigIntCPP::MUL(num1, num2);
	std::cout << "Hex 1: " << num1.getHex() << std::endl;
	std::cout << "Hex 2: " << num2.getHex() << std::endl;
	std::cout << "Hex 3 = MUL(Hex 1, Hex 2): " << num3.getHex() << std::endl;
	if (num3.getHex() == "4A7F69B908E167EB0DC9AF7BBAA5456039C38359E4DE4F169CA10C44D0A416E2") // True value
		std::cout << "Hex 3 correctly MUL! " << std::endl << std::endl;
	else
		std::cout << "Hex 3 incorrectly MUL!!! " << std::endl << std::endl;

	std::cout << "End Test! " << std::endl;

	return 0;
}

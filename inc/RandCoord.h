#include <random>
#include <ctime>
// ���������� ������ � ���� �������.
class RandCoord
{
private:
	std::default_random_engine            generator_y;         // ��� ����
	std::default_random_engine            generator_x;         // ��� ����
	std::uniform_int_distribution<size_t> distribution_height; // ��� ������������� // ������� ���������� ������������� ������������� �� ��������� � ���������
	std::uniform_int_distribution<size_t> distribution_width;  // ��� ������������� // ������� ���������� ������������� ������������� �� ��������� � ���������
public:
	//std::random_device yyy;
	RandCoord(size_t, size_t);
	~RandCoord();
	std::tuple<size_t, size_t> get();
};

RandCoord::RandCoord(size_t height, size_t width)
{
	generator_y.seed(std::time(nullptr));                // ���� ������� // ����� ������� -1
	generator_x.seed(std::time(nullptr)+1);              // ���� ������� // ����� ������� -1
	std::uniform_int<size_t>::param_type h(1, height-2); // �������� ������������� ������
	std::uniform_int<size_t>::param_type w(1, width -2); // �������� ������������� ������
	distribution_height.param(h);
	distribution_width.param(w);
	//distribution_height.reset();
	//distribution_width.reset();
};
RandCoord::~RandCoord() {};

std::tuple<size_t, size_t> RandCoord::get()
{
	//size_t x = distribution_width(generator_x);
	//size_t y = distribution_height(generator_y);
	//std::cout << x << ' ' << y << std::endl;
	//return std::tuple<size_t, size_t>(x,y);
	return std::tuple<size_t, size_t>(distribution_width(generator_x), distribution_height(generator_y));
}

#include <random>
#include <ctime>
// Отработать ошибку в ядре рандома.
class RandCoord
{
private:
	std::default_random_engine            generator_y;         // Тип ядра
	std::default_random_engine            generator_x;         // Тип ядра
	std::uniform_int_distribution<size_t> distribution_height; // Тип распределения // Создает однородное целочисленное распределение по диапазону в интервале
	std::uniform_int_distribution<size_t> distribution_width;  // Тип распределения // Создает однородное целочисленное распределение по диапазону в интервале
public:
	RandCoord(size_t, size_t);
	~RandCoord();
	std::pair<uint32_t, uint32_t> get();
};

RandCoord::RandCoord(size_t width, size_t height)
{
	generator_y.seed(std::time(nullptr));                // Ядро рандома // Может вернуть -1
	generator_x.seed(std::time(nullptr)+1);              // Ядро рандома // Может вернуть -1
	std::uniform_int<size_t>::param_type h(1, height); // Диапазон распределения высоты
	std::uniform_int<size_t>::param_type w(1, width ); // Диапазон распределения ширины
	distribution_height.param(h);
	distribution_width.param(w);
	//distribution_height.reset();
	//distribution_width.reset();
};
RandCoord::~RandCoord() {};

std::pair<uint32_t, uint32_t> RandCoord::get()
{
	//size_t x = distribution_width(generator_x);
	//size_t y = distribution_height(generator_y);
	//std::cout << x << ' ' << y << std::endl;
	//return std::tuple<size_t, size_t>(x,y);
	return std::pair<uint32_t, uint32_t>(distribution_width(generator_x), distribution_height(generator_y));
}

#include <random>
#include <ctime>
// ОТработать ошибку в ядре рандома.
class RandCoord
{
private:
	std::default_random_engine            generator_y;         // Тип ядра
	std::default_random_engine            generator_x;         // Тип ядра
	std::uniform_int_distribution<size_t> distribution_height; // Тип распределения // Создает однородное целочисленное распределение по диапазону в интервале
	std::uniform_int_distribution<size_t> distribution_width;  // Тип распределения // Создает однородное целочисленное распределение по диапазону в интервале
public:
	//std::random_device yyy;
	RandCoord(size_t, size_t);
	~RandCoord();
	std::tuple<size_t, size_t> get();
};

RandCoord::RandCoord(size_t height, size_t width)
{
	generator_y.seed(std::time(nullptr));                // Ядро рандома // Может вернуть -1
	generator_x.seed(std::time(nullptr)+1);              // Ядро рандома // Может вернуть -1
	std::uniform_int<size_t>::param_type h(1, height-2); // Диапазон распределения высоты
	std::uniform_int<size_t>::param_type w(1, width -2); // Диапазон распределения ширины
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

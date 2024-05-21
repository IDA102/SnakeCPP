#include <random>
class RandCoord
{
private:
	std::default_random_engine            generator_x;
	std::default_random_engine            generator_y;
	std::uniform_int_distribution<size_t> distribution_height;
	std::uniform_int_distribution<size_t> distribution_width;
public:
	RandCoord(size_t, size_t);
	~RandCoord();
	std::tuple<size_t, size_t> get();
};

RandCoord::RandCoord(size_t height, size_t width)
{
	std::uniform_int<size_t>::param_type h(0, height);
	std::uniform_int<size_t>::param_type w(0, width);
	distribution_height.param(h);
	distribution_height.param(w);
	//distribution_height(1, height-1);
	//distribution_width (1, width -1);
};
RandCoord::~RandCoord() {};

std::tuple<size_t, size_t> RandCoord::get()
{
	return std::tuple<size_t, size_t>(distribution_width(generator_x), distribution_height(generator_y));
}

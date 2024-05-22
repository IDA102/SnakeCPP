#include<tuple>
// Заменить кортеж яблока на пару.
class Apple : public RandCoord
{
  private:
    uint32_t x; // Координата
    uint32_t y; // Координата 
  public:
	  Apple(uint32_t, uint32_t);
	  ~Apple();
    std::tuple<uint32_t, uint32_t> get();      // Return кортеж нового яблока
    std::tuple<uint32_t, uint32_t> getApple(); // Return кортеж текущего яблока
};
Apple::Apple(uint32_t height, uint32_t width) : RandCoord(height, width) {};
Apple::~Apple(){};
std::tuple<uint32_t, uint32_t> Apple::get()
{
  //x = Rand::get();
  //y = Rand::get();
  //return RandCoord::get();
  std::tie(y, x) = RandCoord::get();
  return std::tuple<uint32_t, uint32_t>(y, x);
};

std::tuple<uint32_t, uint32_t> Apple::getApple()
{
  return std::tuple<uint32_t, uint32_t>(y,x);
}

// В конструкторе создаётся и отображается.
// В деструкторе уничтожается
#include<tuple>
// Заменить кортеж яблока на пару.
class Apple : public RandCoord
{
  private:
    uint32_t x,y; // Координаты
  public:
	  Apple(uint32_t, uint32_t);
	  ~Apple();
    std::pair<uint32_t, uint32_t> get();      // Return кортеж нового яблока
    std::pair<uint32_t, uint32_t> getApple(); // Return кортеж текущего яблока
};

Apple::Apple(uint32_t width, uint32_t height) : RandCoord(width, height) {};
Apple::~Apple(){};

std::pair<uint32_t, uint32_t> Apple::get()
{
  //x = Rand::get();
  //y = Rand::get();
  //return RandCoord::get();
  return std::pair<uint32_t, uint32_t>{RandCoord::get()};
};

std::pair<uint32_t, uint32_t> Apple::getApple()
{
  return std::pair<uint32_t, uint32_t>{x,y};
}

// В конструкторе создаётся и отображается.
// В деструкторе уничтожается
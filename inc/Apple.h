#include<tuple>
// «аменить кортеж €блока на пару.

class Apple : public RandCoord
{
  private:
    uint32_t x,y; //  оординаты
  public:
	  Apple(uint32_t, uint32_t);
	  ~Apple() = default;
    std::pair<uint32_t, uint32_t> get();      // Return пару нового €блока
    std::pair<uint32_t, uint32_t> getApple(); // Return пару текущего €блока
};

Apple::Apple(uint32_t width, uint32_t height) : RandCoord(width, height) {};

std::pair<uint32_t, uint32_t> Apple::get()
{
  std::pair<uint32_t, uint32_t> tmp = RandCoord::get();
  x = tmp.first; y = tmp.second;
  return tmp;
};

std::pair<uint32_t, uint32_t> Apple::getApple(){ return std::pair<uint32_t, uint32_t>{x,y}; }

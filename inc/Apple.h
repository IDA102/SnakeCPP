#include<tuple>
// �������� ������ ������ �� ����.
class Apple : public RandCoord
{
  private:
    uint32_t x,y; // ����������
  public:
	  Apple(uint32_t, uint32_t);
	  ~Apple();
    std::pair<uint32_t, uint32_t> get();      // Return ������ ������ ������
    std::pair<uint32_t, uint32_t> getApple(); // Return ������ �������� ������
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

// � ������������ �������� � ������������.
// � ����������� ������������
#include<tuple>
// �������� ������ ������ �� ����.

class Apple : public RandCoord
{
  private:
    uint32_t x,y; // ����������
  public:
	  Apple(uint32_t, uint32_t);
	  ~Apple() = default;
    std::pair<uint32_t, uint32_t> get();      // Return ���� ������ ������
    std::pair<uint32_t, uint32_t> getApple(); // Return ���� �������� ������
};

Apple::Apple(uint32_t width, uint32_t height) : RandCoord(width, height) {};

std::pair<uint32_t, uint32_t> Apple::get()
{
  std::pair<uint32_t, uint32_t> tmp = RandCoord::get();
  x = tmp.first; y = tmp.second;
  return tmp;
};

std::pair<uint32_t, uint32_t> Apple::getApple(){ return std::pair<uint32_t, uint32_t>{x,y}; }

#include<tuple>
class Apple : public RandCoord
{
  private:
    uint32_t x; // ����������
    uint32_t y; // ���������� 
  public:
	  Apple(uint32_t, uint32_t);
	  ~Apple();
    std::tuple<uint32_t, uint32_t> get(); // Return ������
};
Apple::Apple(uint32_t height, uint32_t width) : RandCoord(height, width) {};
Apple::~Apple(){};
std::tuple<uint32_t, uint32_t> Apple::get()
{
  //x = Rand::get();
  //y = Rand::get();
  return RandCoord::get();
};

// � ������������ �������� � ������������.
// � ����������� ������������
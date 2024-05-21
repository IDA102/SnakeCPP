#include<tuple>
class Apple : public RandCoord
{
  private:
    uint32_t x; // Координата
    uint32_t y; // Координата 
  public:
	  Apple(uint32_t, uint32_t);
	  ~Apple();
    std::tuple<uint32_t, uint32_t> get(); // Return кортеж
};
Apple::Apple(uint32_t height, uint32_t width) : RandCoord(height, width) {};
Apple::~Apple(){};
std::tuple<uint32_t, uint32_t> Apple::get()
{
  //x = Rand::get();
  //y = Rand::get();
  return RandCoord::get();
};

// В конструкторе создаётся и отображается.
// В деструкторе уничтожается
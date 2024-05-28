#include<utility>
class Element
{
	protected:
		uint32_t x,y;
		Figure typeElment;
	public:
	  //void setType(Figure);
		std::pair<uint32_t, uint32_t> getCoord();
		Element(uint32_t, uint32_t, Figure);
		~Element();
};

//void Element::setType(Figure tmp){ typeElment = tmp;};

Element::Element(uint32_t _x, uint32_t _y, Figure _typeElment)
{
  x          = _x;
	y          = _y;
	typeElment = _typeElment;
};

Element::~Element(){};
std::pair<uint32_t, uint32_t> Element::getCoord(){ return std::pair<uint32_t, uint32_t>(x,y); };

//-------------------------------------------------------------

class Snake : Element
{
  private:	
    std::vector<Element> snake;
  public:
	  Snake();
		Snake(uint32_t, uint32_t, Figure);
	  ~Snake();
		//Figure getType();
		void setType(Figure);
		std::pair<uint32_t, uint32_t> getHeadSnake();
		void setCoord(std::pair<uint32_t, uint32_t>);
};

Snake::Snake() : Element(1, 1, triangleRIGHT){};
Snake::Snake(uint32_t _x, uint32_t _y, Figure _typeElment) : Element(_x, _y, _typeElment){};
Snake::~Snake(){};

void Snake::setType(Figure figure){	Element::typeElment = figure; };

std::pair<uint32_t, uint32_t> Snake::getHeadSnake()
{
  return std::pair<uint32_t, uint32_t>{ Element::getCoord() };
};

void Snake::setCoord(std::pair<uint32_t, uint32_t> coord)
{
   Element::x = coord.first;
	 Element::y = coord.second;
}
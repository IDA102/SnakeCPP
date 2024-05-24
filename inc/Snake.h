#include<utility>
class Element
{
	protected:
		uint32_t x = 1;
		uint32_t y = 1;
		Figure typeElment = triangleUP;
	public:
		//virtual Figure getType() = 0;
		//virtual Figure setType() = 0;
		std::pair<uint32_t, uint32_t> getCoord();
		Element();
		~Element();
};

Element::Element (){};
Element::~Element(){};
std::pair<uint32_t, uint32_t> Element::getCoord()
{ 
  return std::pair<uint32_t, uint32_t>(x,y); 
};

//-------------------------------------------------------------

class Snake : Element
{
  private:	
    std::vector<Figure> snake;
  public:
	  Snake();
	  ~Snake();
		//Figure getType();
		std::pair<uint32_t, uint32_t> getHeadSnake();
		void setCoord(std::pair<uint32_t, uint32_t>);
};

Snake::Snake (){ snake = std::move(std::vector<Figure>{triangleUP}); };
Snake::~Snake(){};

//Figure Snake::getType() override{ return Element::typeElment; };

/*void Snake::setType() override
{
	Element::typeElment = ;
};*/

std::pair<uint32_t, uint32_t> Snake::getHeadSnake()
{
  return std::pair<uint32_t, uint32_t>{ Element::getCoord() };
};

void Snake::setCoord(std::pair<uint32_t, uint32_t> coord)
{
   Element::x = coord.first;
	 Element::y = coord.second;
}
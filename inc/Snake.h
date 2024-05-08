class Element
{
	private:
		size_t x;
		size_t y;
		typeElment;
	public:
		Element();
		~Element();
};

Element::Element (){}
Element::~Element(){}

class Snake : Element
{
  private:
  std::vector<unsigned char> snake;
  public:
	  Snake();
	  ~Snake();
};

Snake::Snake (){};
Snake::~Snake(){};
#include<utility>
class Element
{
  protected:
    uint32_t x,y;        // Координаты головы.
    Figure   typeElment; // Направление головы, влево, вправо, вверх, вниз.
    eAction  direction;  // Ориентация головы, вертикальная или горизонтальная.
    Figure   old = triangleRIGHT;        // Старое значение направления.
    
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
    bool     flag;
    Figure   qq;
    Snake();
    Snake(uint32_t, uint32_t, Figure);
    ~Snake();
    //Figure getType();

    void   setType(Figure);
    Figure getType();

    void    setDirection(eAction);
    eAction getDirection();

    void checkAngleDirection(Figure); // Определяет каой угол ставить в случае изменения направлния движения.
    
    std::pair<uint32_t, uint32_t> getHeadSnake(); // Заменить название
    void setCoord(std::pair<uint32_t, uint32_t>);
};

Snake::Snake() : Element(1, 1, triangleRIGHT){};
Snake::Snake(uint32_t _x, uint32_t _y, Figure _typeElment) : Element(_x, _y, _typeElment){};
Snake::~Snake(){};

void   Snake::setType(Figure figure){	Element::typeElment = figure; };
Figure Snake::getType()             { return this->typeElment;      };

void    Snake::setDirection(eAction tmp) { direction = tmp; };
eAction Snake::getDirection()            { return direction;};

void Snake::checkAngleDirection(Figure tmp)
{
  if (tmp == old)
  {
    return;
  }
  //else if (tmp == triangleUP)
  //{
    //if (old == triangleLEFT) // left
    //{
      //qq = angleBottomRight;
      //flag = true;
      //old = tmp;
    //}
    //else                     // right
    //{
      //qq = angleBottomLeft;
      //flag = true;
      //old = tmp;
    //}
  //}
  else if (tmp == triangleDOWN)
  {
    if (old == triangleLEFT)
    {
      //qq = angleTopLeft;
      //flag = true;
      //old = tmp;
    }
    else
    {
      qq = angleTopRight;
      flag = true;
      old = tmp;
    }
  }
  else if (tmp == triangleLEFT)
  {
    if (old == triangleUP)    // up
    {
      qq = angleTopRight;
      flag = true;
      old = tmp;
    }
    else                      // down
    {
      qq = angleBottomRight;
      flag = true;
      old = tmp;
    }
  }
  else if (tmp == triangleRIGHT)
  {
    if (old == triangleUP)
    {
      //qq = angleTopRight;
      //flag = true;
      //old = tmp;
    }
    else
    {
      qq = angleBottomLeft;
      flag = true;
      old = tmp;
    }
  }
};

std::pair<uint32_t, uint32_t> Snake::getHeadSnake(){ return std::pair<uint32_t, uint32_t>{ Element::getCoord() }; };

void Snake::setCoord(std::pair<uint32_t, uint32_t> coord){ Element::x = coord.first; Element::y = coord.second; };
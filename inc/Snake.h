#include<utility>

class Element
{
  protected:
    uint32_t x,y;                        // Координаты головы.
    Figure   typeElment;                 // Направление головы, влево, вправо, вверх, вниз.
    eAction  direction;                  // Ориентация головы, вертикальная или горизонтальная.
    Figure   old = triangleRIGHT;        // Старое значение направления.
    
  public:
    //void setType(Figure);

    std::pair<uint32_t, uint32_t> getCoord();
    Figure getType();
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

Figure Element::getType(){ return typeElment; };

Element::~Element(){};
std::pair<uint32_t, uint32_t> Element::getCoord(){ return std::pair<uint32_t, uint32_t>(x,y); };

//-------------------------------------------------------------

class Snake : Element
{
  private:	
    std::list<Element> snakeTail;
  public:
    bool     flag;
    Figure   qq;                                // Нормальное имя дать // Какой угол рисовать
    uint32_t _x = x,_y = y;                     // Координата направлеения от угла
    uint32_t xDel, yDel;
    Snake();
    Snake(uint32_t, uint32_t, Figure);
    ~Snake();
    //Figure getType();

    void     setType(Figure);
    Figure   getType();

    uint32_t setDirection(eAction);
    eAction  getDirection();

    void checkAngleDirection(Figure);             // Определяет каой угол ставить в случае изменения направлния движения.
    
    std::pair<uint32_t, uint32_t> getHeadSnake(); // Заменить название
    std::pair<uint32_t, uint32_t> getCoordAfterTriangle();
    std::pair<uint32_t, uint32_t> snakeCoordDel();

    void setCoord(std::pair<uint32_t, uint32_t>);

    void add();
    auto getTail();
    void step();

};

Snake::Snake() : Element(2, 1, triangleRIGHT){ snakeTail.push_back( Element(1, 1, lineHORIZONTAL) ); };
Snake::Snake(uint32_t _x, uint32_t _y, Figure _typeElment) : Element(_x, _y, _typeElment){};
Snake::~Snake(){};

void   Snake::setType(Figure figure)     { Element::typeElment = figure; };
Figure Snake::getType()                  { return this->typeElment;      };

uint32_t Snake::setDirection(eAction tmp)
{ 
  if (direction == eAction::UP    && tmp == eAction::DOWN )  return 0;
  if (direction == eAction::DOWN  && tmp == eAction::UP   )  return 0;
  if (direction == eAction::LEFT  && tmp == eAction::RIGHT)  return 0;
  if (direction == eAction::RIGHT && tmp == eAction::LEFT )  return 0;
  direction = tmp;
  return 1;
};
eAction Snake::getDirection(){ return direction; };

void Snake::checkAngleDirection(Figure tmp)
{
  if (tmp == old) { return; }
  switch (tmp)
  {
    case triangleDOWN:
      switch (old)
      {
        case triangleLEFT:    // ↓←
          qq = angleTopLeft;
          _y = y + 1;
          break;
        case triangleRIGHT:   // ↓→
          qq = angleTopRight;
          _y = y + 1;
          break;
        default:
          break;
      }
      break;
    
    case triangleRIGHT:
      switch (old)
      {
        case triangleUP:       // →↑
          qq = angleTopLeft;
          _x = x + 1;
          break;
        case triangleDOWN:     // →↓
          qq = angleBottomLeft;
          _x = x + 1;
          break;
        default:
          break;
      }
      break;
   
    case triangleLEFT:
      switch (old)
      {
        case triangleUP:       // ←↑
          qq = angleTopRight;
          _x = x - 1;
          break;
        case triangleDOWN:     // ←↓
          qq = angleBottomRight;
          _x = x - 1;
          break;
        default:
          break;
      }
      break;

    case triangleUP:
      switch (old)
      {
        case triangleLEFT:     // ↑←
          qq = angleBottomLeft;
          _y = y - 1;
          break;
        case triangleRIGHT:    // ↑→
          qq = angleBottomRight;
          _y = y - 1;
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
  old  = tmp;
  flag = true;
};

std::pair<uint32_t, uint32_t> Snake::getHeadSnake(){ return std::pair<uint32_t, uint32_t>{ Element::getCoord() }; };

std::pair<uint32_t, uint32_t> Snake::getCoordAfterTriangle(){ return std::pair<uint32_t, uint32_t>{_x,_y};};

void Snake::setCoord(std::pair<uint32_t, uint32_t> coord){ Element::x = coord.first; Element::y = coord.second; _x = coord.first; _y = coord.second;  };

void Snake::add()
{
  snakeTail.push_front(snakeTail.front());
};

auto Snake::getTail(){ return std::pair<decltype(snakeTail.begin()), decltype(snakeTail.end())>{ snakeTail.begin(), snakeTail.end()}; };

void Snake::step()
{
  auto tmp = snakeTail.back();
  auto qq = tmp.getCoord();
  xDel = qq.first;
  yDel = qq.second;
  // Замена головы на линию // Продолжение после угла 
  switch (direction)
  {
    case eAction::UP:
      snakeTail.push_front( Element( x,  y, lineVERTICAL)  );
      y--;
      break;
    case eAction::DOWN:
      snakeTail.push_front( Element(x,   y, lineVERTICAL)  );
      y++;
      break;
    case eAction::LEFT:
      snakeTail.push_front( Element(x, y  , lineHORIZONTAL));
      x--;
      break;
    case eAction::RIGHT:
      snakeTail.push_front( Element(x, y  , lineHORIZONTAL));
      x++;
      break;
    default:
      return;
      break;
  }
  snakeTail.pop_back();
};

std::pair<uint32_t, uint32_t> Snake::snakeCoordDel()
{
  //auto tmp = snakeTail.back();
  return std::pair<uint32_t, uint32_t>(xDel,yDel);
};

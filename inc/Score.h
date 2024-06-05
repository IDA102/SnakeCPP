#include <iostream>

class Score
{
  private:
    size_t bestScore;
    size_t score;
    std::fstream fileBest;
  public:
    Score();
	  ~Score();
    void read();
    void write();
    size_t get();
    bool compare();
    void add(size_t a);
};

Score::Score()
{
  fileBest.open("BestScore.txt");
  if (!fileBest.is_open())
  {
    std::cout << "ERROR OPEN SCORE FILE" << std::endl;
    system("pause");
    bestScore = 0;
  }
  else{ fileBest >> bestScore; }
  score = 0;
}

Score::~Score()              { fileBest.close();      };
inline void   Score::read()  { fileBest >> bestScore; };
inline void   Score::write() { fileBest << score;     };
inline size_t Score::get()   { return bestScore;      };
inline bool   Score::compare()
{
  if (score > bestScore)
    return true;
  return false;
};
inline void Score::add(size_t a) { score += a; };

class Rand
{
private:
	size_t number;
public:
	Rand();
	~Rand();
	size_t get();
};

Rand::Rand()             { srand(time(0)); }
Rand::~Rand(){}
inline size_t Rand::get(){ return rand();  }

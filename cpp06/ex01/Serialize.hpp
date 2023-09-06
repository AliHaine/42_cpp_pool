#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

class Serialize {
public:
	Serialize(void);
	Serialize(Serialize &serialize);
	Serialize &operator=(Serialize &serialize);
	~Serialize(void);
};

#endif

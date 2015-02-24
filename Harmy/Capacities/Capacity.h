#pragma once
class Capacity
{
public:
	Capacity();
	Capacity(int);
	int level_get() { return this->level_; }
	void level_set(int value) { this->level_ = value; }
	virtual float value_get()=0;
	virtual void level_upgrade() = 0; 
	virtual void level_downgrade() = 0;
	~Capacity();
protected:
	int level_;
};


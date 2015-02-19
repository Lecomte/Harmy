#pragma once
class Capacity
{
public:
	Capacity();
	Capacity(int);
	int level_get() { return this->level_; }
	virtual float value_get()=0;
	void level_updgrade() { this->level_++; }
	void level_downgrade() { this->level_--; }
	~Capacity();
protected:
	int level_;
};


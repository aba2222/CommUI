#pragma once

class Widget {
public:
	virtual ~Widget() = default;
	virtual void Create(const char* name, int width, int height) = 0;
private:
	int id;
	float value;
	bool isVisible;
};
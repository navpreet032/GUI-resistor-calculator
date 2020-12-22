#pragma once
#include"wx/wx.h"
#include "cMain.h"
class Capp : public wxApp
{
public:
	Capp();
	~Capp();
private:
	cMain* m_frame1 = nullptr;
public:
	virtual bool OnInit();
};


#include "Capp.h"
wxIMPLEMENT_APP(Capp);//it is acting like (int main)
Capp::Capp() 
{

}
Capp::~Capp()
{

}
bool Capp::OnInit()
{
	m_frame1 = new cMain();
	m_frame1->Show();
	return true;

}
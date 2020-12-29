#include<string>

using namespace std;
#include <wx/wxprec.h>
#include <wx/config.h>
#include <wx/radiobut.h>
#include<wx/textctrl.h>
#include <wx/radiobox.h>
#include "wx/button.h"
#include"wx/statbox.h"
#include <wx/checklst.h>
#include<wx/combobox.h>
//#include"Nav.h"

#include<wx/string.h>

#include <wx/wx.h>

//#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
public:
    wxTextCtrl* textCtrl1 = new wxTextCtrl(this, 15, "", wxPoint(305, 200), wxSize(80, 25));      //}            text boX
    wxTextCtrl* textCtrlTol = new wxTextCtrl(this, 14, "", wxPoint(385, 200), wxSize(45, 25));      //}            text boX for tolarence
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++CALCULATOR CODE+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  long long int num1, num2;
   
    float multiplier;
    string s1 ;
    string s2  ;
    string conctS;
    string ANS;
    int num12 ;
    int ans ; 
  
public:
    ////////////////////  COMBOBOX
    wxComboBox* combo1;//
    wxComboBox* combo2;//
    wxComboBox* combo3;//
    wxComboBox* combo4;//
    ////////////////////
    //********************STRINGS
    wxString selected_textCbox1;
    wxString  selected_textCbox2;
    wxString  selected_textCbox3;
    wxString  selected_textCbox4;
    //***********************
    
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void onButtonCal(wxCommandEvent& event);
    void onDropDown1(wxCommandEvent& event);
    void onDropDown2(wxCommandEvent& event);
    void onDropDown3(wxCommandEvent& event);
    void onDropDown4(wxCommandEvent& event);
   // void OnNav(Nav & event);
    wxDECLARE_EVENT_TABLE();
}; 

    

enum IDs
{
    ID_Hello = 1,
    ID_RADIOBUTTON1 = 2,
    ID_RADIOBUTTON2 = 3,
    ID_RADIOBUTTON3 = 4,
    ID_COMBOBOX = 5
};


BEGIN_EVENT_TABLE(MyFrame, wxFrame)// {***************** events BOX*****************
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_BUTTON(032, onButtonCal)
EVT_COMBOBOX(033, onDropDown1)
EVT_COMBOBOX(034, onDropDown2)
EVT_COMBOBOX(035, onDropDown3)
EVT_COMBOBOX(036, onDropDown4)
wxEND_EVENT_TABLE()



wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    
    MyFrame* frame = new MyFrame("Resis CAL", wxPoint(60, 50), wxSize(600, 340));
    frame->Show(true);
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxStaticBox* statixbox = new wxStaticBox(this, wxID_STATIC, wxT("&Band One"), wxPoint(8, 36), wxSize(82,40));// static box 0
    wxStaticBox* statixbox1 = new wxStaticBox(this, wxID_STATIC, wxT("&Band Two"), wxPoint(8, 87), wxSize(82, 40));// static box1
    wxStaticBox* statixbox2 = new wxStaticBox(this, wxID_STATIC, wxT("&Multiplier"), wxPoint(8,136), wxSize(82, 40));// static box2
    wxStaticBox* statixbox3 = new wxStaticBox(this, wxID_STATIC, wxT("&Tolerance"), wxPoint(8,186), wxSize(82, 40));// static box3
    wxStaticBox* statixboxOUTPUT = new wxStaticBox(this, wxID_STATIC, wxT("&Resistor Value"), wxPoint(300, 186), wxSize(135, 50));// static box3

    wxRadioButton* radioButton1 = new wxRadioButton(this, ID_RADIOBUTTON1, wxT("&Four"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP);//{
    radioButton1->SetValue(true);
    wxRadioButton* radioButton2 = new wxRadioButton(this, ID_RADIOBUTTON2, wxT("&Five"), wxPoint(50,0), wxDefaultSize, wxRB_GROUP);//          RADIOBUTTONS code
    wxRadioButton* radioButton3 = new wxRadioButton(this, ID_RADIOBUTTON3, wxT("&Six"), wxPoint(100, 0), wxDefaultSize, wxRB_GROUP);//}
    
    wxButton* buttons;//{
    buttons=(new wxButton(this,032, wxT("Cal"), wxPoint(200, 200), wxDefaultSize));//} cal Button
    buttons->SetBackgroundColour(*wxRED);
    

    //wxButton* button = new wxButton(this, wxID_ANY, wxT(""),wxPoint(20, 100), wxDefaultSize);
    //->SetBackgroundColour(*wxRED);
    wxArrayString strings;      //{
    strings.Add(wxT("BLACK"));
    strings.Add(wxT("BROWN"));
    strings.Add(wxT("RED"));
    strings.Add(wxT("ORANGE"));
    strings.Add(wxT("YELLOW"));
    strings.Add(wxT("GREEN"));
    strings.Add(wxT("BLUE"));
    strings.Add(wxT("VOILET"));
    strings.Add(wxT("GREY"));
    strings.Add(wxT("WHITE"));//} for combobox1,2

    wxArrayString strings1;      //{
    strings1.Add(wxT("BLACK"));
    strings1.Add(wxT("BROWN"));
    strings1.Add(wxT("RED"));
    strings1.Add(wxT("ORANGE"));
    strings1.Add(wxT("YELLOW"));
    strings1.Add(wxT("GREEN"));
    strings1.Add(wxT("BLUE"));
    strings1.Add(wxT("VOILET"));
    strings1.Add(wxT("GREY"));
    strings1.Add(wxT("WHITE"));
    strings1.Add(wxT("GOLD"));
    strings1.Add(wxT("SILVER"));//} for combobox3
    wxArrayString strings2;      //{
    strings2.Add(wxT("BROWN"));
    strings2.Add(wxT("RED"));
    strings2.Add(wxT("GREEN"));
    strings2.Add(wxT("BLUE"));
    strings2.Add(wxT("VOILET"));
    strings2.Add(wxT("GREY"));
    strings2.Add(wxT("GOLD"));
    strings2.Add(wxT("SILVER"));//} for combobox4


    combo1 = new wxComboBox(this, 033,//{
        wxT("BLACK"),wxPoint(10,50), wxDefaultSize,
        strings, wxCB_DROPDOWN);                         //}     combo box 1  ID033
     combo2 = new wxComboBox(this,034,//{
        wxT("BLACK"), wxPoint(10, 100), wxDefaultSize,
        strings, wxCB_DROPDOWN);                         //}     combo box 2  ID034
     combo3 = new wxComboBox(this, 035,//{
        wxT("BLACK"), wxPoint(10, 150), wxDefaultSize,
        strings1, wxCB_DROPDOWN);                         //}     combo box 3  ID035
     combo4 = new wxComboBox(this, 036,//{
        wxT("BLACK"), wxPoint(10,200), wxSize(78,40),
        strings2, wxCB_DROPDOWN);                         //{     combo box 4  ID036
  
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    //wxMenu* menuNav = new wxMenu;
    //menuNav->Append(ID_Nav);
    // menuBar->Append(menuNav, "&Nav");
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
   
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("ResisCal: ver:1.0  By: Camo Dudes");
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
        "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::onDropDown1(wxCommandEvent& event) {// FOR COMBOBOX 1
    
    selected_textCbox1 = combo1->GetValue();
    
    {if (strcmp(selected_textCbox1, "BLACK") == 0) {
        num1 = 0;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }}
    
     {if (strcmp(selected_textCbox1, "BROWN") == 0) {
        num1 = 1;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }} 
     {if (strcmp(selected_textCbox1, "RED") == 0) {
        num1 = 2;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }}
     {if (strcmp(selected_textCbox1, "ORANGE") == 0) {
        num1 = 3;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }}
    {if (strcmp(selected_textCbox1, "YELLOW") == 0) {
        num1 = 4;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }} 
    {if (strcmp(selected_textCbox1, "GREEN") == 0) {
        num1 = 5;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }} 
    {if (strcmp(selected_textCbox1, "BLUE") == 0) {
        num1 = 6;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }} 
    {if (strcmp(selected_textCbox1, "VIOLET") == 0) {
        num1 = 7;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }} 
    {if (strcmp(selected_textCbox1, "GREY") == 0) {
        num1 = 8;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }} 
    {if (strcmp(selected_textCbox1, "WHITE") == 0) {
        num1 = 9;

        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
    }}
  
    event.Skip();
}
void MyFrame::onDropDown2(wxCommandEvent& event) {// FOR COMBOBOX 2

    selected_textCbox2 = combo2->GetValue();
    {   if (strcmp(selected_textCbox2, "BLACK") == 0) {
        num2 = 0;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
       
    }}

    {   if (strcmp(selected_textCbox2, "BROWN") == 0) {
        num2 = 1;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
       
    }}

    {   if (strcmp(selected_textCbox2, "RED") == 0) {
        num2 = 2;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        
    }}

    {   if (strcmp(selected_textCbox2, "ORANGE") == 0) {
        num2 = 3;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
       
    }}

    {   if (strcmp(selected_textCbox2, "YELLOW") == 0) {
        num2 = 4;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        
    }}

    {   if (strcmp(selected_textCbox2, "GREEN") == 0) {
        num2 = 5;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;

    }}

    {   if (strcmp(selected_textCbox2, "BLUE") == 0) {
        num2 = 6;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        
    }}

    {   if (strcmp(selected_textCbox2, "VOILET") == 0) {
        num2 = 7;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        
    }}

    {   if (strcmp(selected_textCbox2, "GREY") == 0) {
        num2 = 8;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        
    }}

    {   if (strcmp(selected_textCbox2, "WHITE") == 0) {
        num2 = 9;
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
       
    }}
    event.Skip();
}
void MyFrame::onDropDown3(wxCommandEvent& event) {// FOR COMBOBOX 3

    selected_textCbox3 = combo3->GetValue();
    { if (strcmp(selected_textCbox3, "BLACK") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 1;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "BROWN") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 10;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "RED") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 100;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "ORANGE") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 1000;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "YELLOW") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 10000;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "GREEN") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 100000;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "BLUE") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 1000000;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "VOILET") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 10000000;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "GREY") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 100000000;
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    { if (strcmp(selected_textCbox3, "WHITE") == 0) {
        s1 = to_string(num1);
        s2 = to_string(num2);
        conctS = s1 + s2;
        multiplier = 1000000000;// bug
        num12 = stoi(conctS);
        ans = num12 * multiplier;
        ANS = to_string(ans);

    }}
    event.Skip();
}
void MyFrame::onDropDown4(wxCommandEvent& event) {// FOR COMBOBOX 4

    selected_textCbox4= combo4->GetValue();
    { if (strcmp(selected_textCbox3, "BROWN") == 0) {
        textCtrlTol->AppendText("±1%");
    }}
    { if (strcmp(selected_textCbox4, "RED") == 0) {
        textCtrlTol->AppendText("±2%");
    }}
    { if (strcmp(selected_textCbox4, "GREEN") == 0) {
        textCtrlTol->AppendText("±0.5%");
    }}
    { if (strcmp(selected_textCbox4, "BLUE") == 0) {
        textCtrlTol->AppendText("±0.25%");
    }}
    { if (strcmp(selected_textCbox4, "VOILET") == 0) {
        textCtrlTol->AppendText("±0.1%");
    }}
    { if (strcmp(selected_textCbox4, "GREY") == 0) {
        textCtrlTol->AppendText("±0.05%");
    }}
    { if (strcmp(selected_textCbox4, "WHITE") == 0) {
        textCtrlTol->AppendText("±5%");
    }} { if (strcmp(selected_textCbox4, "GOLD") == 0) {
        textCtrlTol->AppendText("±10%");
    }}
    event.Skip();
}
void MyFrame::onButtonCal(wxCommandEvent& event) {
    textCtrl1->AppendText(ANS);
} //selected_textCbox2 = combo2->GetValue();

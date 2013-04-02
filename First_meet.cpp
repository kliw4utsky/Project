// First_meet.cpp: файл реализации
//

#include "stdafx.h"
#include "Kurs_rob.h"
#include "First_meet.h"
#include "afxdialogex.h"


// диалоговое окно First_meet

IMPLEMENT_DYNAMIC(First_meet, CDialogEx)

First_meet::First_meet(CWnd* pParent /*=NULL*/)
	: CDialogEx(First_meet::IDD, pParent)
{

}

First_meet::~First_meet()
{
}

void First_meet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(First_meet, CDialogEx)
END_MESSAGE_MAP()


// обработчики сообщений First_meet

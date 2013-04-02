// Insert.cpp: файл реализации
//

#include "stdafx.h"
#include "Kurs_rob.h"
#include "Insert.h"
#include "afxdialogex.h"


// диалоговое окно Insert

IMPLEMENT_DYNAMIC(Insert, CDialogEx)

Insert::Insert(CWnd* pParent /*=NULL*/)
	: CDialogEx(Insert::IDD, pParent)
{

	m_e1 = 0;
	m_e2 = _T("");
	m_e3 = 0;
	m_e4 = _T("");
	m_e5 = 0;
	m_e6 = _T("");
}

Insert::~Insert()
{
}

void Insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_e1);
	DDX_Text(pDX, IDC_EDIT2, m_e2);
	DDX_Text(pDX, IDC_EDIT3, m_e3);
	DDX_Text(pDX, IDC_EDIT4, m_e4);
	DDX_Text(pDX, IDC_EDIT5, m_e5);
	DDX_Text(pDX, IDC_EDIT6, m_e6);
}


BEGIN_MESSAGE_MAP(Insert, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Insert::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &Insert::OnEnChangeEdit3)
END_MESSAGE_MAP()


// обработчики сообщений Insert


void Insert::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void Insert::OnEnChangeEdit3()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}

// Dream_team.cpp: файл реализации
//

#include "stdafx.h"
#include "Kurs_rob.h"
#include "Dream_team.h"
#include "afxdialogex.h"
#include "afxdb.h"

CDatabase db_1;

// диалоговое окно Dream_team

IMPLEMENT_DYNAMIC(Dream_team, CDialogEx)

Dream_team::Dream_team(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dream_team::IDD, pParent)
{

}

Dream_team::~Dream_team()
{
}

void Dream_team::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list2);
}


BEGIN_MESSAGE_MAP(Dream_team, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dream_team::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Dream_team::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &Dream_team::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений Dream_team


BOOL Dream_team::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CFileDialog dlg(true,NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"MS Access File (.mdb)|*.mdb||");
	CString connectionString(_T("Driver={Driver do Microsoft Access (*.mdb)};"));
	TCHAR szBuffer[MAX_PATH];
	GetModuleFileName(NULL, szBuffer, MAX_PATH);
	CString path(szBuffer);
	path = path.Left(path.ReverseFind(_T('\\')));
	connectionString+= _T("dbq=")+path+_T("\\My.mdb;driverid=25;fil=MS Access;maxbuffersize=2048;	maxscanrows=8;pagetimeout=5;safetransactions=0;threads=3;uid=admin;usercommitsync=Yes;");	
	if(!db_1.Open(NULL, 0, 0, connectionString))	
		{
			MessageBox(_T("Невозможно установить соединение с базой данних"), _T("Ошибка"), MB_ICONERROR);
			exit(1);
			}	
	CString zapros_2=_T("Select * from Dream_team");	
	Fill_list_2(zapros_2);
	CWnd::UpdateData(true);

	// TODO:  Добавить дополнительную инициализацию

	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}


void Dream_team::Fill_list_2(CString zapros_2)
{
	int n,i;
	m_list2.DeleteAllItems();
	n=m_list2.GetHeaderCtrl()->GetItemCount();//m_list-обэкт класа
	for(i=n-1;i>=0;i--)//тому що коректно працювати з кінця,бо навпаки 1 колонка не видаляеться
	{
		
			m_list2.DeleteColumn(i);//Видаляє рядки
	}
	m_list2.SetTextColor(222); //установка цвета
	CRecordset rec(&db_1);//клас який працюэ з записом
	rec.Open(CRecordset::snapshot, zapros_2);
	int count=rec.GetODBCFieldCount();//кількість полів в базі данних
	CODBCFieldInfo info;//якась зміна яка буде містити інфу про поля
	for (i=0;i<count;i++)
	{
		rec.GetODBCFieldInfo(i,info);//читаю інфу про поля
		m_list2.InsertColumn(i,info.m_strName);//запис в список,вставляю колонку з імям стр нейм
		m_list2.SetColumnWidth(i,80);//
	}
	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);//повертае значення поля з 1 поля до останньго і повертає його в buff
			if(j == 0)
				m_list2.InsertItem(i, buff);
			else
				m_list2.SetItemText(i, j, buff);
		}
		rec.MoveNext();	
		i++;
   }	
}


void Dream_team::OnBnClickedButton1()
{
	CString str, zapros_2;
	m_list2.GetSelectedCount();
	POSITION pos=m_list2.GetFirstSelectedItemPosition();
	int npos;
	while(pos)
	{
		npos=m_list2.GetNextSelectedItem(pos);	
		str=m_list2.GetItemText(npos,0);
		zapros_2.Format(L"DELETE * FROM Dream_team WHERE Place = '%s'",str);
		db_1.ExecuteSQL(zapros_2);
		zapros_2 = "Select * from Dream_team";
		Fill_list_2(zapros_2);
	}		
}


void Dream_team::OnBnClickedButton2()
{
	
}


void Dream_team::OnBnClickedOk()
{
	db_1.Close();
	CDialogEx::OnOK();
}

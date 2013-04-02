// Dream_team.cpp: ���� ����������
//

#include "stdafx.h"
#include "Kurs_rob.h"
#include "Dream_team.h"
#include "afxdialogex.h"
#include "afxdb.h"

CDatabase db_1;

// ���������� ���� Dream_team

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


// ����������� ��������� Dream_team


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
			MessageBox(_T("���������� ���������� ���������� � ����� ������"), _T("������"), MB_ICONERROR);
			exit(1);
			}	
	CString zapros_2=_T("Select * from Dream_team");	
	Fill_list_2(zapros_2);
	CWnd::UpdateData(true);

	// TODO:  �������� �������������� �������������

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����������: �������� ������� OCX ������ ���������� �������� FALSE
}


void Dream_team::Fill_list_2(CString zapros_2)
{
	int n,i;
	m_list2.DeleteAllItems();
	n=m_list2.GetHeaderCtrl()->GetItemCount();//m_list-����� �����
	for(i=n-1;i>=0;i--)//���� �� �������� ��������� � ����,�� ������� 1 ������� �� �����������
	{
		
			m_list2.DeleteColumn(i);//������� �����
	}
	m_list2.SetTextColor(222); //��������� �����
	CRecordset rec(&db_1);//���� ���� ������ � �������
	rec.Open(CRecordset::snapshot, zapros_2);
	int count=rec.GetODBCFieldCount();//������� ���� � ��� ������
	CODBCFieldInfo info;//����� ���� ��� ���� ������ ���� ��� ����
	for (i=0;i<count;i++)
	{
		rec.GetODBCFieldInfo(i,info);//����� ���� ��� ����
		m_list2.InsertColumn(i,info.m_strName);//����� � ������,�������� ������� � ���� ��� ����
		m_list2.SetColumnWidth(i,80);//
	}
	CString buff;
	i=0;
	while (!rec.IsEOF())
	{
		for (short j=0; j<count; j++)
		{ 
			rec.GetFieldValue(j,buff);//�������� �������� ���� � 1 ���� �� ��������� � ������� ���� � buff
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

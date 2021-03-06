// CDialigLiao.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialigLiao.h"
#include "afxdialogex.h"


// CDialigLiao 对话框

IMPLEMENT_DYNAMIC(CDialigLiao, CDialog)

CDialigLiao::CDialigLiao(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_Liao, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	AfxInitRichEdit(); //richedit的初始化
}

CDialigLiao::~CDialigLiao()
{
}

void CDialigLiao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_RICHEDIT21, m_redit1);
	DDX_Control(pDX, IDC_RICHEDIT22, m_redit2);
}


BEGIN_MESSAGE_MAP(CDialigLiao, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialigLiao::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialigLiao::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDialigLiao::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CDialigLiao 消息处理程序


void CDialigLiao::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_redit1.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
	CString str;
	m_redit1.SetSel(-1, -1);
	CString sendstr;
	m_redit2.GetWindowText(sendstr);
	sendstr = L"项目负责人说: " + sendstr;
	m_redit2.SetWindowText(L"");
	m_redit1.ReplaceSel(sendstr+L"\r\n");

}


void CDialigLiao::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码



}


BOOL CDialigLiao::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  在此添加额外的初始化
	this->SetWindowTextW(L"投资人群聊");
	HICON myIcon[8];
	for (int i = 0; i < 8; i++)
		myIcon[i] = AfxGetApp()->LoadIcon(IDR_MAINFRAME);//这里使用LoadIcon获得HICON  其中IDR_MAINFRAME为系统默认图标
	m_ImageList.Create(32, 32, ILC_COLOR32, 4, 4);
	for (int i = 0; i<8; i++)
		m_ImageList.Add(myIcon[i]);
	m_list.SetImageList(&m_ImageList, LVSIL_NORMAL);
	for (int i = 0; i < 1; i++)
	{
		LVITEM lvitem;
		lvitem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvitem.iItem = i;
		lvitem.pszText = L"尹成";
		lvitem.iImage = i;
		lvitem.iSubItem = 0;
		m_list.InsertItem(&lvitem);



		// ((CListCtrl *) lParam)->InsertItem(i,m_strTitle, i);
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialigLiao::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

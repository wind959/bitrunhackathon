// CDialogViewCost.cpp: 实现文件
//

#include "stdafx.h"
#include "MFC_projector.h"
#include "CDialogViewCost.h"
#include "afxdialogex.h"


// CDialogViewCost 对话框

IMPLEMENT_DYNAMIC(CDialogViewCost, CDialog)

CDialogViewCost::CDialogViewCost(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_costlist, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CDialogViewCost::~CDialogViewCost()
{
}

void CDialogViewCost::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CDialogViewCost, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDialogViewCost::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CDialogViewCost 消息处理程序


BOOL CDialogViewCost::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// TODO:  在此添加额外的初始化
	this->SetWindowTextW(L"查看投资者投放金额");


	LONG lStyle;
	lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);//获取当前窗口style 
	lStyle &= ~LVS_TYPEMASK; //清除显示方式位 
	lStyle |= LVS_REPORT; //设置style 
	SetWindowLong(m_list.m_hWnd, GWL_STYLE, lStyle);//设置style

	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;//选中某行使整行高亮（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_GRIDLINES;//网格线（只适用与report风格的listctrl） 
	dwStyle |= LVS_EX_CHECKBOXES;//item前生成checkbox控件

	m_list.InsertColumn(0, L"花销类型", LVCFMT_LEFT, 100);//插入列 
	m_list.InsertColumn(1, L"花销金额", LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, L"投资人投票结果", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"是否允许", LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, L"花销说明", LVCFMT_LEFT, 500);

	int nRow = 0;
	nRow = m_list.InsertItem(0, L"尹成");//插入行
	m_list.SetItemText(0, 1, _T("0"));
	m_list.SetItemText(0, 2, _T("0"));
	m_list.SetItemText(0, 3, _T("0"));
	m_list.SetItemText(0, 4, _T("0"));


	nRow = m_list.InsertItem(0, L"朱胡美");//插入行
	m_list.SetItemText(0, 1, _T("0"));
	m_list.SetItemText(0, 2, _T("0"));
	m_list.SetItemText(0, 3, _T("0"));
	m_list.SetItemText(0,4, _T("0"));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogViewCost::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

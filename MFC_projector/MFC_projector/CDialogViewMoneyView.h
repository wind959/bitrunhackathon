#pragma once


// CDialogViewMoneyView 对话框

class CDialogViewMoneyView : public CDialog
{
	DECLARE_DYNAMIC(CDialogViewMoneyView)

public:
	CDialogViewMoneyView(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogViewMoneyView();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_V_money };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};

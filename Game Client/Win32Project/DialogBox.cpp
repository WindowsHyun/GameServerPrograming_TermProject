#include "Client.h"

HWND hwndOwner;
RECT rc, rcDlg, rcOwner;
HWND ipAddr, CharName;
char ipAddres[MAX_PATH] = "127.0.0.1";

BOOL CALLBACK DlgProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
	switch ( uMsg ) {
	case WM_INITDIALOG:
		//-------------------------------------------------------------------------------------------------------------------------------------
		// ���̾�α� �ڽ��� �߾�����
		if ( (hwndOwner = GetParent( hDlg )) == NULL )
			hwndOwner = GetDesktopWindow();

		GetWindowRect( hwndOwner, &rcOwner );
		GetWindowRect( hDlg, &rcDlg );
		CopyRect( &rc, &rcOwner );

		OffsetRect( &rcDlg, -rcDlg.left, -rcDlg.top );
		OffsetRect( &rc, -rc.left, -rc.top );
		OffsetRect( &rc, -rcDlg.right, -rcDlg.bottom );

		SetWindowPos( hDlg, HWND_TOP, rcOwner.left + (rc.right / 2), rcOwner.top + (rc.bottom / 2), 0, 0, SWP_NOSIZE );
		//-------------------------------------------------------------------------------------------------------------------------------------
		ipAddr = GetDlgItem( hDlg, IDC_EDIT1 );

		SetDlgItemText( hDlg, IDC_EDIT1, ipAddres );
		return TRUE;

	case WM_COMMAND:

		switch ( LOWORD( wParam ) ) {
		case IDC_BUTTON1:
			GetWindowText( ipAddr, ipAddres, MAX_PATH );
			EndDialog( hDlg, IDCANCEL );
			return TRUE;

		case IDCANCEL:
			MessageBox( NULL, "������ �ϼž� ���Ḧ �� �� �ֽ��ϴ�..!", "", 0 );
			return TRUE;

		}
		return FALSE;
	}
	return FALSE;
}
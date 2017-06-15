#include "Client.h"
#include "protocol.h"

CImage m_image; // Map �̹���
CImage Ch_image[5]; // ���� ĳ����
CImage You_image[5]; // ���� ĳ����
CImage Monster_image[10]; // ���� ĳ����
CImage Effect_image[5]; // ���� ����Ʈ
char PrintData[100];

void init_Image() {
	m_image.Load( "Image\\Map\\FullMap.png" );
	Ch_image[CS_UP].Load( "Image\\Character\\Character_Up.png" );
	Ch_image[CS_DOWN].Load( "Image\\Character\\Character_Down.png" );
	Ch_image[CS_LEFT].Load( "Image\\Character\\Character_Left.png" );
	Ch_image[CS_RIGHT].Load( "Image\\Character\\Character_Right.png" );
	You_image[CS_UP].Load( "Image\\Character\\You_Up.png" );
	You_image[CS_DOWN].Load( "Image\\Character\\You_Down.png" );
	You_image[CS_LEFT].Load( "Image\\Character\\You_Left.png" );
	You_image[CS_RIGHT].Load( "Image\\Character\\You_Right.png" );
	Monster_image[0].Load( "Image\\Monster\\Monster1.png" );
	Monster_image[1].Load( "Image\\Monster\\Monster2.png" );
	Monster_image[2].Load( "Image\\Monster\\Monster3.png" );
	Monster_image[3].Load( "Image\\Monster\\Monster4.png" );
	Monster_image[4].Load( "Image\\Monster\\Monster5.png" );
	Monster_image[5].Load( "Image\\Monster\\Monster6.png" );
	Monster_image[6].Load( "Image\\Monster\\Monster7.png" );
	Effect_image[0].Load( "Image\\Effect\\Attack_Effect1.png" );
	Effect_image[1].Load( "Image\\Effect\\Attack_Effect2.png" );
	Effect_image[2].Load( "Image\\Effect\\Attack_Effect3.png" );
	Effect_image[3].Load( "Image\\Effect\\Attack_Effect4.png" );
	Effect_image[4].Load( "Image\\Effect\\Attack_Monster.png" );
}

void cimage_draw( HDC hdc, int x, int y, int r_x, int r_y ) {
	m_image.Draw( hdc, 0 + (x * 40), 0 + (y * 40), 40, 40, 0 + (r_x * 16), 0 + (r_y * 16), 16, 16 );
}

/*
TBitmap * p = Image1->Picture->Bitmap;
p->Width  = Image1->Width;
p->Height = Image1->Height;

AnsiString sStr = "����� ���ڿ�";
int nTextW  = p->Canvas->TextWidth(sStr);  // ���ڿ� ����
int nTextH  = p->Canvas->TextHeight(sStr); // ���ڿ� ����
int nStartW = (p->Width  - nTextW) / 2;   // �¿� ��� �����ϱ� ���� ������ ã��
int nStartH = (p->Height - nTextH) / 2;   // ���� ��� �����ϱ� ���� ������ ã��

p->Canvas->TextOut(nStartW, nStartH, sStr);
*/
void Character_Draw( HDC hdc, int x, int y, int direction, int movement, int hp, int exp, int level ) {
	sprintf( PrintData, "%d | %d | %d", hp , exp, level );
	SetTextColor( hdc, RGB( 255, 0, 0 ) );
	SetBkMode( hdc, TRANSPARENT );
	SetTextAlign( hdc, TA_CENTER );
	TextOut( hdc, 20 + (x * 40), -14 + (y * 40), PrintData, strlen( PrintData ) );
	Ch_image[direction].Draw( hdc, 0 + (x * 40), 0 + (y * 40), 40, 40, 0 + (movement * 23), 0, 23, 29 );
}

void Character_You_Draw( HDC hdc, int x, int y, int direction, int movement, int hp ) {
	sprintf( PrintData, "%d", hp );
	SetTextColor( hdc, RGB( 79, 67, 178 ) );
	SetBkMode( hdc, TRANSPARENT );
	SetTextAlign( hdc, TA_CENTER );
	TextOut( hdc, 20 + (x * 40), -14 + (y * 40), PrintData, strlen( PrintData ) );
	You_image[direction].Draw( hdc, 0 + (x * 40), 0 + (y * 40), 40, 40, 0 + (movement * 23), 0, 23, 26 );
}

void Monster_Draw( HDC hdc, int x, int y, int Kind, int hp ) {
	sprintf( PrintData, "%d", hp );
	SetTextColor( hdc, RGB( 0, 0, 255 ) );
	SetBkMode( hdc, TRANSPARENT );
	SetTextAlign( hdc, TA_CENTER );
	TextOut( hdc, 20 + (x * 40), -14 + (y * 40), PrintData, strlen( PrintData ) );
	Monster_image[Kind].Draw( hdc, 0 + (x * 40), 0 + (y * 40), 40, 40, 0, 0, Monster_image[Kind].GetWidth(), Monster_image[Kind].GetHeight() );
}

void AttackEffect_Draw( HDC hdc, int x, int y, int Kind ) {
	Effect_image[Kind].Draw( hdc, 0 + ((x - 1) * 40), 0 + (y * 40), 40, 40, 0, 0, Effect_image[Kind].GetWidth(), Effect_image[Kind].GetHeight() );
	Effect_image[Kind].Draw( hdc, 0 + ((x + 1) * 40), 0 + (y * 40), 40, 40, 0, 0, Effect_image[Kind].GetWidth(), Effect_image[Kind].GetHeight() );
	Effect_image[Kind].Draw( hdc, 0 + (x * 40), 0 + ((y - 1) * 40), 40, 40, 0, 0, Effect_image[Kind].GetWidth(), Effect_image[Kind].GetHeight() );
	Effect_image[Kind].Draw( hdc, 0 + (x * 40), 0 + ((y + 1) * 40), 40, 40, 0, 0, Effect_image[Kind].GetWidth(), Effect_image[Kind].GetHeight() );
}
// ��Ŷ ����
#define SC_POS           1
#define SC_PUT_PLAYER    2
#define SC_REMOVE_PLAYER 3
#define SC_CHAT		4

#define MAX_STR_SIZE  100

// ��Ŷ ���� 2
#define CS_UP    1
#define CS_DOWN  2
#define CS_LEFT  3
#define CS_RIGHT    4
#define CS_CHAT		5
#define CS_Attack		6

struct cs_packet_up {
	BYTE size;
	BYTE type;
};

// BYTE�� 255������ �ν��Ͽ� int���� BOOL�� ����

struct sc_packet_put_player {
	BYTE size;
	BYTE type;
	WORD id;
	BOOL x;
	BOOL y;
	BOOL hp;
	BOOL direction;
	BOOL movement;
};

struct sc_packet_pos {
	BYTE size;
	BYTE type;
	WORD id;
	BOOL x;
	BOOL y;
	BOOL hp;
	BOOL direction;
	BOOL movement;
};

struct sc_packet_remove_player {
	BYTE size;
	BYTE type;
	WORD id;
};

struct sc_packet_chat {
	BYTE size;
	BYTE type;
	WORD id;
	WCHAR message[MAX_STR_SIZE];
};

struct cs_packet_attack {
	BYTE size;
	BYTE type;
	BYTE skill_num;
	BYTE damage;
};
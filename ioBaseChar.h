#pragma once
class ioBaseChar
{
private:
	char Buffer1[100]; //�ʿ� ���� ����ü�� ũ�� ��ŭ Buffer �� ũ�⸦ ���� ��Ų��.

	DWORD aa; //�ʿ��� ������ ��������

	char Buffer2[24]; //���۸� ���� ��Ų��

public:
	ioBaseChar();
	~ioBaseChar();
};
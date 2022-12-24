#pragma once
#include <iostream>
// ������������ ��������� "�������" //FIFO
// �������� ��� ��������
// 1.��������
// 2.�����
// 3.�������� �������
// 4.�������� �������
//
// 1. ������� �� ������� � ������������ 
//              size
// mem: |x|x|x|x|x|x|x| | | | | | | | | | | |
//                   ^ Last // Count
// - "��������" => mem[Last++] = �����
// - "�����" => a = mem[0]+�����������
// - �������� ������� -> Last = 0//-1
// - �������� ������� -> Last = Size
//
// 2. ������� �� ��������� ������.
//              size
// mem: |x|x|x|x|x|x|x| | | | | | | | | | | 
//       ^First      ^Last
// - "��������"=> mem[Last++]=�����||Last=0 -> Count++
//              {        count       }
// mem: ||||||||x|x|x|x|x|x|x|x|x|x|x|
//                      ^First      ^Last
// 
// - "�����" => a=mem[First++]||First=0 -> Count-- 
//  mem: |x|x|x|x|x|x|x| | | | | | | | | |x| 
//                    ^Last}              { ^First
// - �������� ������� -> count = 0
// - �������� ������� -> count = size
//
// 3. ������� �� �������� ������
//  |info| | -> | | | -> | | | -> | | | ........ ->| |0|
//   ^First                                           ^Last
// 
// - �������� => | | | -> | | | -> | | | -> | | | ->
// 
// - �����: 
//   | | | -> | | | -> | | | -> | | | ->........ ->| |0|
//                                                  ^Last
// 


class TNode
{
public:
	TNode(int _info = 0) {
		info = _info;
		next = nullptr;
	}

	TNode(const TNode& tmp) {
		info = tmp.info;
		next = nullptr;
	}

	~TNode() {
		next = nullptr;
	}

	TNode& operator=(TNode tmp) {
		info = tmp.info;
		return *this;
	}

	int getInfo() {
		return info;
	}

	void setInfo(int k) {
		info = k;
	}

	TNode* getNext() {
		return next;
	}

	/*void setNext(TNode* tmp) {
		next = tmp;
	}*/
	TNode* setNext(TNode* tmp)
	{
		next = tmp;
		return this;
	}

private:
	int info;
	TNode* next;
};
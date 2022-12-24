#pragma once
#include <iostream>
// Динамическая структура "очередь" //FIFO
// Операции над очередью
// 1.Добавить
// 2.Взять
// 3.Контроль пустоты
// 4.Контроль полноты
//
// 1. Очередь на массиве с перепаковкою 
//              size
// mem: |x|x|x|x|x|x|x| | | | | | | | | | | |
//                   ^ Last // Count
// - "Добавить" => mem[Last++] = новый
// - "Взять" => a = mem[0]+перепаковка
// - Контроль пустоты -> Last = 0//-1
// - Контроль полноты -> Last = Size
//
// 2. Очередь на кольцевом буфере.
//              size
// mem: |x|x|x|x|x|x|x| | | | | | | | | | | 
//       ^First      ^Last
// - "Добавить"=> mem[Last++]=Новый||Last=0 -> Count++
//              {        count       }
// mem: ||||||||x|x|x|x|x|x|x|x|x|x|x|
//                      ^First      ^Last
// 
// - "Взять" => a=mem[First++]||First=0 -> Count-- 
//  mem: |x|x|x|x|x|x|x| | | | | | | | | |x| 
//                    ^Last}              { ^First
// - Контроль пустоты -> count = 0
// - Контроль полноты -> count = size
//
// 3. Очередь на линейном списке
//  |info| | -> | | | -> | | | -> | | | ........ ->| |0|
//   ^First                                           ^Last
// 
// - Добавить => | | | -> | | | -> | | | -> | | | ->
// 
// - Взять: 
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
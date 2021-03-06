#pragma once
#include <iostream>
#include <list>
using namespace std;

class OrderList
{
	static list <Order> order;
public:
	OrderList() {
	};
	OrderList(OrderList &OrderList);
	OrderList& operator = (const OrderList &p);
	void move(Order);
	void remove(Order);
};
class Order : public OrderList 
{
public:
	Order();
	Order(Order &Order, string oName);
	Order& operator = (const Order &p);
	bool validate(string);
	void execute();

private:
	string name;
};

class deploy : public Order 
{
public:
	deploy();
	deploy(deploy &deploy);
	deploy& operator = (const deploy &p);

private:
	string name;
};

class advance : public Order 
{
public:
	advance();
	advance(advance &advance);
	advance& operator = (const advance &p);

private:
	string name;
};	

class bomb : public Order 
{
public:
	bomb();
	bomb(bomb &bomb);
	bomb& operator = (const bomb &p);

private:
	string name;
};

class blockade : public Order 
{
public:
	blockade();
	blockade(blockade &blockade);
	blockade& operator = (const blockade &p);

private:
	string name;
};

class airlift : public Order 
{
public:
	airlift();
	airlift(airlift &airlift);
	airlift& operator = (const airlift &p);

private:
	string name;
};

class negotiate : public Order 
{
public:
	negotiate();
	negotiate(negotiate &negotiate);
	negotiate& operator = (const negotiate &p);

private:
	string name;
};

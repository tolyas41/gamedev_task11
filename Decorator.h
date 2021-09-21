#pragma once
#include <iostream>
class PrintFactory
{
public:
	virtual ~PrintFactory() {}
	virtual void PrintOperation() const = 0;
};

class Printer : public PrintFactory
{
public:
	virtual void PrintOperation() const override
	{
		std::cout << "\nRegular print\n";
	}
};

class PrinterDecorator : public PrintFactory
{
protected:
	PrintFactory* printer;

public:
	PrinterDecorator(PrintFactory* set_printer)
		: printer(set_printer) {}
	virtual void PrintOperation() const override
	{
		printer->PrintOperation();
	}
};

class PrinterDecoratorOne : public PrinterDecorator
{
public:
	PrinterDecoratorOne(PrintFactory* set_printer)
		: PrinterDecorator(set_printer) {}
	virtual void PrintOperation() const override
	{
		printer->PrintOperation();
		std::cout << "\nPlus something first version\n";
	}
};

class PrinterDecoratorTwo : public PrinterDecorator
{
public:
	PrinterDecoratorTwo(PrintFactory* set_printer)
		: PrinterDecorator(set_printer) {}
	virtual void PrintOperation() const override
	{
		printer->PrintOperation();
		std::cout << "\nPlus something second version\n";
	}
};